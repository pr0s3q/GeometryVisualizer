#pragma once

#include <IDrawable.hpp>

#include <array>

#include <raylib.h>

template <std::size_t N>
class Curve : public IDrawable
{
public:
    explicit Curve(const std::array<Vector3, N>& array)
        : m_internalArray(array)
    {
    }

    void Draw() const override
    {
        if constexpr (N < 2)
            return;

        for (auto it = m_internalArray.begin(); it != m_internalArray.end() - 1; ++it)
            DrawCylinderEx(*it, *(it + 1), m_thickness, m_thickness, 16, m_color);
    }

private:
    std::array<Vector3, N> m_internalArray;

    const Color m_color { DARKBLUE };
    const float m_thickness { 0.006f };
};
