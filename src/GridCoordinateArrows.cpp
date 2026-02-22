#include <GridCoordinateArrows.hpp>

#include <raylib.h>

void GridCoordinateArrows::Draw() const
{
    Vector3 zero = {0.0f, 0.0f, 0.0f};

    // Red - X axis
    Vector3 startX = {m_startPosition, 0.0f, 0.0f};
    Vector3 endX = {m_endPosition, 0.0f, 0.0f};
    DrawCylinderEx(zero, startX, m_arrowLineThickness, m_arrowLineThickness, 16, RED);
    DrawCylinderEx(startX, endX, m_arrowTipThickness, 0.0f, 16, RED);

    // Green - Y axis
    Vector3 startY = {0.0f, m_startPosition, 0.0f};
    Vector3 endY = {0.0f, m_endPosition, 0.0f};
    DrawCylinderEx(zero, startY, m_arrowLineThickness, m_arrowLineThickness, 16, GREEN);
    DrawCylinderEx(startY, endY, m_arrowTipThickness, 0.0f, 16, GREEN);

    // Blue - Z axis
    Vector3 startZ = {0.0f, 0.0f, m_startPosition};
    Vector3 endZ = {0.0f, 0.0f, m_endPosition};
    DrawCylinderEx(zero, startZ, m_arrowLineThickness, m_arrowLineThickness, 16, BLUE);
    DrawCylinderEx(startZ, endZ, m_arrowTipThickness, 0.0f, 16, BLUE);
}
