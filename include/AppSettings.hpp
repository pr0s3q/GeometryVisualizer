#pragma once

class AppSettings
{
public:
    static void GetResolution(int& width, int& height);
    static void GetResolution(float& width, float& height);

private:
    static constexpr int m_iScreenWidth = 3600;
    static constexpr int m_iScreenHeight = 1900;
    static constexpr float m_fScreenWidth = 3600.0;
    static constexpr float m_fScreenHeight = 1900.0;
};