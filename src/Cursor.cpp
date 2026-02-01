#include <Cursor.hpp>

#include <raylib.h>

#include "AppSettings.hpp"

Cursor::Cursor()
{
    float width, height;
    AppSettings::GetResolution(width, height);
    m_cursorXPos = width / 2.0f;
    m_cursorYPos = height / 2.0f;
}

void Cursor::Draw() const
{
    DrawLineEx((Vector2){m_cursorXPos-20, m_cursorYPos}, (Vector2){m_cursorXPos+20, m_cursorYPos}, 2, BLACK);
    DrawLineEx((Vector2){m_cursorXPos, m_cursorYPos-20}, (Vector2){m_cursorXPos, m_cursorYPos+20}, 2, BLACK);
}
