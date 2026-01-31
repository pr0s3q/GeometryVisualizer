#include <Plane.hpp>

Plane::Plane(const Axis axis, Vector3 coordinate, const float width, const float height)
    : m_axis(axis)
    , m_coordinate(coordinate)
    , m_width(width)
    , m_height(height)
{
}

void Plane::Draw() const
{
    switch (m_axis)
    {
        case Axis::X:
        {
            DrawCube(m_coordinate, 0.006f, m_height, m_width, s_yellow);
            DrawCubeWires(m_coordinate, 0.006f, m_height, m_width, MAROON);
            break;
        }
        case Axis::Y:
        {
            DrawCube(m_coordinate, m_width, m_height, 0.006f, s_yellow);
            DrawCubeWires(m_coordinate, m_width, m_height, 0.006f, MAROON);
            break;
        }
        case Axis::Z:
        {
            DrawCube(m_coordinate, m_height, 0.006f, m_width, s_yellow);
            DrawCubeWires(m_coordinate, m_height, 0.006f, m_width, MAROON);
            break;
        }
        default:
        break;
    }
}
