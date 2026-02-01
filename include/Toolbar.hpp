#pragma once

#include <IDrawable.hpp>

#include <raylib.h>

class Toolbar : IDrawable
{
public:
    Toolbar() = default;

    void Draw() const override;

    void HandlePressedButtons();

private:
    Color m_toolbarColor { LIGHTGRAY };
    bool m_planeButton {};
};
