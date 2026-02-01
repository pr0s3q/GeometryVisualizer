#pragma once

#include <IDrawable.hpp>

class Cursor : IDrawable
{
public:
    Cursor();

    void Draw() const override;

private:
    float m_cursorXPos {};
    float m_cursorYPos {};
};
