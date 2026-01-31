#include <Plane.hpp>

Plane::Plane(const Axis axis, const Vector3& coordinate, const float& width, const float& height)
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
            DrawCube(m_coordinate, m_thickness, m_height, m_width, m_planeColor);
            DrawCubeWires(m_coordinate, m_thickness, m_height, m_width, m_borderColor);
            break;
        }
        case Axis::Y:
        {
            DrawCube(m_coordinate, m_width, m_height, m_thickness, m_planeColor);
            DrawCubeWires(m_coordinate, m_width, m_height, m_thickness, m_borderColor);
            break;
        }
        case Axis::Z:
        {
            DrawCube(m_coordinate, m_height, m_thickness, m_width, m_planeColor);
            DrawCubeWires(m_coordinate, m_height, m_thickness, m_width, m_borderColor);
            break;
        }
        default:
        break;
    }
}
