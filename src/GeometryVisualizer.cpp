#include <AppSettings.hpp>
#include <GeometryVisualizer.hpp>
#include <Toolbar.hpp>

#include <raylib.h>

GeometryVisualizer::GeometryVisualizer()
{
    int screenWidth;
    int screenHeight;
    AppSettings::GetResolution(screenWidth, screenHeight);

    InitWindow(screenWidth, screenHeight, "GeometryVisualizer");

    m_camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    m_camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    m_camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    m_camera.fovy = 45.0f;
    m_camera.projection = CAMERA_PERSPECTIVE;

    DisableCursor();

    SetTargetFPS(100);
}

void GeometryVisualizer::Launch()
{
    while (!WindowShouldClose())
    {
        UpdateCamera(&m_camera, m_cameraMode);

        HandleKeyInput();
        m_toolbar.HandlePressedButtons();

        BeginDrawing();
        ClearBackground(DARKGRAY);
        BeginMode3D(m_camera);
        DrawGrid(50, 1.0f);

        m_gridCoordinateArrows.Draw();

        EndMode3D();

        m_cursor.Draw();
        m_toolbar.Draw();

        DrawFPS(3400, 10);

        EndDrawing();
    }
    CloseWindow();
}

void GeometryVisualizer::HandleKeyInput()
{
    if (IsKeyPressed(KEY_Z))
        m_camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    if (IsKeyPressed(KEY_M))
    {
        if (m_cameraMode == CAMERA_CUSTOM)
        {
            m_cameraMode = CAMERA_FREE;
            DisableCursor();
        }
        else
        {
            m_cameraMode = CAMERA_CUSTOM;
            EnableCursor();
        }
    }
}
