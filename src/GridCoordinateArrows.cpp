#include <GridCoordinateArrows.hpp>

#include <raylib.h>

void GridCoordinateArrows::Draw() const
{
    // Red - X axis
    // m_arrow
    DrawCylinderEx((Vector3){0.0f, 0.0f, 0.0f}, (Vector3){2.0f, 0.0f, 0.0f}, m_arrowLineThickness, m_arrowLineThickness, 16, RED);
    DrawCylinderEx((Vector3){2.0f, 0.0f, 0.0f}, (Vector3){2.4f, 0.0f, 0.0f}, m_arrowTipThickness, 0.0f, 16, RED);

    // Green - Y axis
    // m_arrow
    DrawCylinderEx((Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, 2.0f, 0.0f}, m_arrowLineThickness, m_arrowLineThickness, 16, GREEN);
    DrawCylinderEx((Vector3){0.0f, 2.0f, 0.0f}, (Vector3){0.0f, 2.4f, 0.0f}, m_arrowTipThickness, 0.0f, 16, GREEN);

    // Blue - Z axis
    // m_arrow
    DrawCylinderEx((Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 2.0f}, m_arrowLineThickness, m_arrowLineThickness, 16, BLUE);
    DrawCylinderEx((Vector3){0.0f, 0.0f, 2.0f}, (Vector3){0.0f, 0.0f, 2.4f}, m_arrowTipThickness, 0.0f, 16, BLUE);
}
