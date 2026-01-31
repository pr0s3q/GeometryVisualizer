#pragma once

#include <Cursor.hpp>
#include <GridCoordinateArrows.hpp>

#include <raylib.h>

class GeometryVisualizer
{
public:
    GeometryVisualizer();

    void Launch();

private:
    Cursor m_cursor {};
    Camera m_camera {};
    GridCoordinateArrows m_gridCoordinateArrows {};
};
