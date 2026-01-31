#pragma once

#include <Enums.hpp>
#include <IDrawable.hpp>
#include <raylib.h>

class Plane : IDrawable
{
public:
    Plane(Axis axis, const Vector3& coordinate, const float& width, const float& height);

    void Draw() const override;

private:
    Axis m_axis { Axis::Undefined };
    Vector3 m_coordinate {};
    float m_width { 0.0f };
    float m_height { 0.0f };

    const Color m_planeColor { Fade(YELLOW, 0.4f) };
    const Color m_borderColor { MAROON };
    const float m_thickness { 0.006f };
};
