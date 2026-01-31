#pragma once

#include <IDrawable.hpp>

class GridCoordinateArrows : IDrawable
{
public:
    GridCoordinateArrows() = default;

    void Draw() const override;

private:
    const float m_arrowLineThickness { 0.02f };
    const float m_arrowTipThickness { 0.2f };
};
