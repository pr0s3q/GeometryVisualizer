#pragma once

#include <Cursor.hpp>
#include <GridCoordinateArrows.hpp>
#include <Toolbar.hpp>

#include <raylib.h>

class GeometryVisualizer
{
public:
    GeometryVisualizer();

    void HandleKeyInput();
    void Launch();

private:
    Cursor m_cursor {};
    Camera m_camera {};
    GridCoordinateArrows m_gridCoordinateArrows {};
    Toolbar m_toolbar {};
    int m_cameraMode { CAMERA_FREE };
};
