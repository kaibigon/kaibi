#pragma once
#include "core/base/core.h"

namespace KAIBI
{
    class Mesh
    {
    public:
        Mesh(const float* vertices, unsigned int vertexCount, const unsigned int* indices, unsigned int indexCount);
        ~Mesh();

        void bind();
        void unbind();
        void draw();

    private:
        unsigned int m_VAO, m_VBO, m_EBO;
    };
}