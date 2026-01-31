#pragma once

#include <raylib.h>

#include <Cursor.hpp>

#include "GridCoordinateArrows.hpp"

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
