#pragma once

#include <raylib.h>
#include <raymath.h>

class Defaults
{
public:
    static Defaults& Get()
    {
        static Defaults instance;
        return instance;
    }

    Defaults(const Defaults&) = delete;
    Defaults& operator=(const Defaults&) = delete;
    Defaults(Defaults&&) = delete;
    Defaults& operator=(Defaults&&) = delete;

    const Material& DefaultMaterial() const;
    const Matrix& DefaultMatrix() const;

private:
    Defaults() = default;

    const Material m_material = LoadMaterialDefault();
    const Matrix m_matrix = MatrixIdentity();
};
