#!/usr/bin/env python3

import re
import sys

def parse_stp_file(filepath):
    points = []
    curves = []
    
    with open(filepath, 'r') as f:
        content = f.read()
    
    # Find DATA section
    data_match = re.search(r'DATA;(.*?)ENDSEC;', content, re.DOTALL)
    if not data_match:
        print("No DATA section found")
        return
    
    data_section = data_match.group(1)
    
    # Split into lines, but handle multiline if needed, but in STP, entities are on one line usually
    lines = data_section.strip().split('\n')
    
    for line in lines:
        line = line.strip()
        if not line or not line.startswith('#'):
            continue
        
        # Parse entity
        parts = line.split('=', 1)
        if len(parts) != 2:
            continue
        entity_id = parts[0].strip()[1:]  # remove #
        entity_def = parts[1].strip()
        
        # Check if CARTESIAN_POINT
        if entity_def.startswith("CARTESIAN_POINT"):
            # Extract coordinates
            coords_match = re.search(r',\s*\(\s*([^)]+)\s*\)', entity_def)
            if coords_match:
                coords_str = coords_match.group(1)
                try:
                    x, y, z = map(float, coords_str.split(','))
                    x /= 1000.0
                    y /= 1000.0
                    z /= 1000.0
                    # Swap y and z
                    y, z = z, y
                    points.append((int(entity_id), x, y, z))
                except ValueError:
                    pass  # skip invalid
        
        # Check if curve definition
        elif 'B_SPLINE_CURVE_WITH_KNOTS' in entity_def or 'GEOMETRIC_CURVE_SET' in entity_def:
            if points:
                curves.append(points[:])  # copy
                points.clear()
    
    # Add remaining points if any
    if points:
        curves.append(points)
    
    return curves

def generate_cpp_code(curves):
    code_lines = []
    code_lines.append("#include <array>")
    code_lines.append("#include <Curve.hpp>")
    code_lines.append("#include <IDrawable.hpp>")
    code_lines.append("#include <raylib.h>")
    code_lines.append("#include <vector>")
    code_lines.append("#include <memory>")
    code_lines.append("")
    
    code_lines.append("std::vector<std::unique_ptr<IDrawable>> createCurves() {")
    
    curve_decls = []
    
    for i, curve_points in enumerate(curves):
        N = len(curve_points)
        if N == 0:
            continue
        
        # Generate array
        array_lines = []
        for pid, x, y, z in curve_points:
            array_lines.append(f"        {{ {x:.6f}f, {y:.6f}f, {z:.6f}f }}")
        
        array_init = ",\n".join(array_lines)
        
        code_lines.append(f"    std::array<Vector3, {N}> points{i} = {{{{")
        code_lines.append(array_init)
        code_lines.append("    }};")
        code_lines.append("")
        
        curve_decls.append(f"std::make_unique<Curve<{N}>>(points{i})")
    
    if curve_decls:
        code_lines.append(f"    std::vector<std::unique_ptr<IDrawable>> curves;")
        code_lines.append(f"    curves.reserve({len(curve_decls)});")
        
        for decl in curve_decls:
            code_lines.append(f"    curves.push_back({decl});")
        
        code_lines.append("    return curves;")
    else:
        code_lines.append("    return {};")
    
    code_lines.append("}")
    
    return "\n".join(code_lines)

def generate_hpp_code():
    code_lines = []
    code_lines.append("#pragma once")
    code_lines.append("")
    code_lines.append("#include <IDrawable.hpp>")
    code_lines.append("#include <vector>")
    code_lines.append("#include <memory>")
    code_lines.append("")
    code_lines.append("std::vector<std::unique_ptr<IDrawable>> createCurves();")
    code_lines.append("")
    return "\n".join(code_lines)
    
    for i, curve_points in enumerate(curves):
        N = len(curve_points)
        if N == 0:
            continue
        
        # Generate array
        array_lines = []
        for pid, x, y, z in curve_points:
            array_lines.append(f"        {{ {x:.6f}f, {y:.6f}f, {z:.6f}f }}")
        
        array_init = ",\n".join(array_lines)
        
        code_lines.append(f"    std::array<Vector3, {N}> points{i} = {{{{")
        code_lines.append(array_init)
        code_lines.append("    }};")
        code_lines.append("")
        
        curve_decls.append(f"std::make_unique<Curve<{N}>>(points{i})")
    
    code_lines.append("    return {" + ", ".join(curve_decls) + "};")
    code_lines.append("}")
    
    return "\n".join(code_lines)

if __name__ == "__main__":
    filepath = "/home/cristopher/git/cpp/GeometryVisualizer/curves.stp"
    curves = parse_stp_file(filepath)
    if curves:
        cpp_code = generate_cpp_code(curves)
        with open("src/GeneratedCurves.cpp", "w") as f:
            f.write(cpp_code)
        
        hpp_code = generate_hpp_code()
        with open("include/GeneratedCurves.hpp", "w") as f:
            f.write(hpp_code)
        
        print("Generated C++ code saved to src/GeneratedCurves.cpp and include/GeneratedCurves.hpp")
    else:
        print("No curves found")