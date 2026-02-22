#pragma once

#include <Defaults.hpp>
#include <IDrawable.hpp>

#include <array>
#include <cmath>
#include <optional>

#include <raylib.h>
#include <raymath.h>

template <std::size_t N>
class Curve : public IDrawable
{
public:
    explicit Curve(const std::array<Vector3, N>& array)
        : m_internalArray(array)
    {
    }

    ~Curve() override
    {
        if (m_cachedMesh.has_value())
            UnloadMesh(*m_cachedMesh);
    }

    // Non-copyable: Mesh holds GPU resources that must not be duplicated.
    Curve(const Curve&)            = delete;
    Curve& operator=(const Curve&) = delete;

    Curve(Curve&& other) noexcept
        : m_internalArray(other.m_internalArray)
        , m_cachedMesh(std::move(other.m_cachedMesh))
    {
        other.m_cachedMesh.reset(); // prevent double-unload
    }

    Curve& operator=(Curve&& other) noexcept
    {
        if (this != &other)
        {
            if (m_cachedMesh.has_value())
                UnloadMesh(*m_cachedMesh);

            m_internalArray = other.m_internalArray;
            m_cachedMesh    = std::move(other.m_cachedMesh);
            other.m_cachedMesh.reset();
        }
        return *this;
    }

    void Draw() const override
    {
        DrawMesh(GetMesh(), Defaults::Get().DefaultMaterial(), Defaults::Get().DefaultMatrix());
    }

    // Returns a GPU-ready tube mesh swept along the curve.
    // Built on the first call; subsequent calls return the cached mesh.
    // The mesh is automatically unloaded when the Curve is destroyed.
    const Mesh& GetMesh() const override
    {
        if (m_cachedMesh.has_value())
            return *m_cachedMesh;

        m_cachedMesh = BuildMesh();
        return *m_cachedMesh;
    }

private:
    Mesh BuildMesh() const override
    {
        if constexpr (N < 2)
            return Mesh{};

        constexpr std::size_t sides     = 8;
        constexpr std::size_t ringCount = N;
        constexpr std::size_t vertCount = ringCount * sides;
        constexpr std::size_t triCount  = (ringCount - 1) * sides * 2;

        Mesh mesh = {};
        mesh.vertexCount   = static_cast<int>(vertCount);
        mesh.triangleCount = static_cast<int>(triCount);
        mesh.vertices  = static_cast<float*>(MemAlloc(vertCount * 3 * sizeof(float)));
        mesh.normals   = static_cast<float*>(MemAlloc(vertCount * 3 * sizeof(float)));
        mesh.texcoords = static_cast<float*>(MemAlloc(vertCount * 2 * sizeof(float)));
        mesh.indices   = static_cast<unsigned short*>(MemAlloc(triCount * 3 * sizeof(unsigned short)));

        // Vertex generation
        for (std::size_t i = 0; i < ringCount; ++i)
        {
            // Central-difference tangent (forward/backward at the ends)
            Vector3 tangent;
            if (i == 0)
                tangent = Vector3Normalize(Vector3Subtract(m_internalArray[1],   m_internalArray[0]));
            else if (i == ringCount - 1)
                tangent = Vector3Normalize(Vector3Subtract(m_internalArray[N-1], m_internalArray[N-2]));
            else
                tangent = Vector3Normalize(Vector3Subtract(m_internalArray[i+1], m_internalArray[i-1]));

            // Build an orthonormal frame around the tangent
            const Vector3 up   = std::abs(tangent.y) < 0.99f ? Vector3{0.f, 1.f, 0.f}
                                                             : Vector3{0.f, 0.f, 1.f};
            const Vector3 normal   = Vector3Normalize(Vector3CrossProduct(up, tangent));
            auto [x, y, z] = Vector3CrossProduct(tangent, normal);

            const Vector3& center = m_internalArray[i];
            constexpr float uStep = 1.f / static_cast<float>(sides);
            const float vCoord = static_cast<float>(i) / static_cast<float>(ringCount - 1);

            for (std::size_t s = 0; s < sides; ++s)
            {
                const float angle = 2.f * PI * static_cast<float>(s) / static_cast<float>(sides);
                const float cosA  = std::cos(angle);
                const float sinA  = std::sin(angle);

                // Outward direction for this spoke
                const Vector3 outward =
                {
                    normal.x * cosA + x * sinA,
                    normal.y * cosA + y * sinA,
                    normal.z * cosA + z * sinA
                };

                const std::size_t vi = (i * sides + s) * 3;
                mesh.vertices[vi]     = center.x + outward.x * m_thickness;
                mesh.vertices[vi + 1] = center.y + outward.y * m_thickness;
                mesh.vertices[vi + 2] = center.z + outward.z * m_thickness;

                mesh.normals[vi]     = outward.x;
                mesh.normals[vi + 1] = outward.y;
                mesh.normals[vi + 2] = outward.z;

                const std::size_t ti = (i * sides + s) * 2;
                mesh.texcoords[ti]     = static_cast<float>(s) * uStep;
                mesh.texcoords[ti + 1] = vCoord;
            }
        }

        // Index generation
        std::size_t idx = 0;
        for (std::size_t i = 0; i < ringCount - 1; ++i)
        {
            for (std::size_t s = 0; s < sides; ++s)
            {
                const std::size_t next = (s + 1) % sides;
                const auto a = static_cast<unsigned short>(i       * sides + s);
                const auto b = static_cast<unsigned short>(i       * sides + next);
                const auto c = static_cast<unsigned short>((i + 1) * sides + s);
                const auto d = static_cast<unsigned short>((i + 1) * sides + next);

                mesh.indices[idx++] = a;
                mesh.indices[idx++] = c;
                mesh.indices[idx++] = b;

                mesh.indices[idx++] = b;
                mesh.indices[idx++] = c;
                mesh.indices[idx++] = d;
            }
        }

        UploadMesh(&mesh, false);
        return mesh;
    }

    std::array<Vector3, N> m_internalArray;

    mutable std::optional<Mesh> m_cachedMesh;

    const Color m_color { 0, 255, 255, 255 };
    const float m_thickness { 0.018f };
};
