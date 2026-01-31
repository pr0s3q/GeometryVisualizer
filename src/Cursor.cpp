#include <Cursor.hpp>

#include <raylib.h>

void Cursor::Draw() const
{
    DrawLineEx((Vector2){cursorXPos-20, cursorYPos}, (Vector2){cursorXPos+20, cursorYPos}, 2, BLACK);
    DrawLineEx((Vector2){cursorXPos, cursorYPos-20}, (Vector2){cursorXPos, cursorYPos+20}, 2, BLACK);
}
