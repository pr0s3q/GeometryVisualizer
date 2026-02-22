#pragma once

#include <IDrawable.hpp>

#include <raylib.h>

class Toolbar : IDrawable
{
public:
    Toolbar() = default;

    void Draw() const override;

    void HandlePressedButtons();
    void PlaneCreatorUI();

private:
    Color m_toolbarColor { LIGHTGRAY };
    bool m_planeButton {};

    bool m_planeCreatorUI {};
    bool m_planeCreatorXBool {};
    bool m_planeCreatorYBool {};
    bool m_planeCreatorZBool {};
    char m_planeCreatorXInput[256] {};
    char m_planeCreatorYInput[256] {};
    char m_planeCreatorZInput[256] {};
};
