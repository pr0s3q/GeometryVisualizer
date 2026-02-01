#pragma once

#include <IDrawable.hpp>

class Toolbar : IDrawable
{
public:
    Toolbar() = default;

    void Draw() const override;
};
