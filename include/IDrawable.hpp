#pragma once
#include "raylib.h"

class IDrawable
{
public:
    virtual ~IDrawable() = default;

    virtual void Draw() const = 0;

    [[nodiscard]] virtual const Mesh& GetMesh() const
    {
        return m_Mesh;
    }

private:

    [[nodiscard]] virtual Mesh BuildMesh() const
    {
        return m_Mesh;
    }

    const Mesh m_Mesh{};
};
