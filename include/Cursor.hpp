#pragma once

#include <IDrawable.hpp>

class Cursor : IDrawable
{
public:
    Cursor() = default;

    void Draw() const override;

private:
    const float cursorXPos { 3600.0f / 2.0f };
    const float cursorYPos { 1900.0f / 2.0f };
};
