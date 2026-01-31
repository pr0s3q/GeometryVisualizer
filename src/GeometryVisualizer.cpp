#include <GeometryVisualizer.hpp>

#include <raylib.h>

GeometryVisualizer::GeometryVisualizer()
{
    constexpr int screenWidth = 3600;
    constexpr int screenHeight = 1900;

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
        // Update
        //--------------------------------------------------------------------------------------
        UpdateCamera(&m_camera, CAMERA_FREE);

        if (IsKeyPressed(KEY_Z))
            m_camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };

        // Draw
        //--------------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(DARKGRAY);

        BeginMode3D(m_camera);

        DrawGrid(50, 1.0f);

        m_gridCoordinateArrows.Draw();

        EndMode3D();

        // Cursor
        m_cursor.Draw();

        DrawFPS(10, 10);

        EndDrawing();
    }
    CloseWindow();
}
