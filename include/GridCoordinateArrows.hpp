#pragma once

class GridCoordinateArrows
{
public:
    GridCoordinateArrows() = default;

    void Draw() const;

private:
    const float m_arrowLineThickness { 0.02f };
    const float m_arrowTipThickness { 0.2f };
};