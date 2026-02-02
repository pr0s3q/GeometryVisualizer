#pragma once

#include <IDrawable.hpp>
#include <raylib.h>

class Box : IDrawable
{
public:
    Box() = default;
    Box(const Vector3& position, const Vector3& size);

    void Draw() const override;

private:
    Vector3 m_position {};
    Vector3 m_size {};
    Color m_color { LIME };
    Color m_insideColor { Fade(LIME, 0.2f) };
};
