#include <AppSettings.hpp>

void AppSettings::GetResolution(int& width, int& height)
{
    width = m_iScreenWidth;
    height = m_iScreenHeight;
}

void AppSettings::GetResolution(float& width, float& height)
{
    width = m_fScreenWidth;
    height = m_fScreenHeight;
}
