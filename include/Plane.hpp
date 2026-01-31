#pragma once

#include <Enums.hpp>
#include <IDrawable.hpp>
#include <raylib.h>

class Plane : IDrawable
{
public:
    Plane(Axis axis, Vector3 coordinate, float width, float height);

    void Draw() const override;

private:
    Axis m_axis {Axis::Undefined};
    Vector3 m_coordinate {};
    float m_width {0.0f};
    float m_height {0.0f};

    Color s_yellow = Fade(YELLOW, 0.4f);
};
