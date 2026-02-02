#include <Box.hpp>

#include <raylib.h>

Box::Box(const Vector3& position, const Vector3& size)
{
    m_position = position;
    m_size = size;
}

void Box::Draw() const
{
    DrawCubeV(m_position, m_size, m_insideColor);
    DrawCubeWiresV(m_position, m_size, m_color);
}
