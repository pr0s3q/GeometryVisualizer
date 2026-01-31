#include <GridCoordinateArrows.hpp>

#include <raylib.h>

void GridCoordinateArrows::Draw() const
{
    // Red - X axis
    DrawCylinderEx((Vector3){0.0f, 0.0f, 0.0f}, (Vector3){m_startPosition, 0.0f, 0.0f}, m_arrowLineThickness, m_arrowLineThickness, 16, RED);
    DrawCylinderEx((Vector3){m_startPosition, 0.0f, 0.0f}, (Vector3){m_endPosition, 0.0f, 0.0f}, m_arrowTipThickness, 0.0f, 16, RED);

    // Green - Y axis
    DrawCylinderEx((Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, m_startPosition, 0.0f}, m_arrowLineThickness, m_arrowLineThickness, 16, GREEN);
    DrawCylinderEx((Vector3){0.0f, m_startPosition, 0.0f}, (Vector3){0.0f, m_endPosition, 0.0f}, m_arrowTipThickness, 0.0f, 16, GREEN);

    // Blue - Z axis
    DrawCylinderEx((Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, m_startPosition}, m_arrowLineThickness, m_arrowLineThickness, 16, BLUE);
    DrawCylinderEx((Vector3){0.0f, 0.0f, m_startPosition}, (Vector3){0.0f, 0.0f, m_endPosition}, m_arrowTipThickness, 0.0f, 16, BLUE);
}
