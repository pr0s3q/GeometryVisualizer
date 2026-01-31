#pragma once

class Cursor
{
public:
    Cursor() = default;

    void Draw() const;

private:
    const float cursorXPos { 3600.0f / 2.0f };
    const float cursorYPos { 1900.0f / 2.0f };
};