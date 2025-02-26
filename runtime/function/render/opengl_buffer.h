#pragma once
#include "core/base/core.h"

namespace KAIBI
{
    class OpenGLBuffer
    {
    public:
        OpenGLBuffer(const float* vertices, unsigned int vertexCount, const unsigned int* indices, unsigned int indexCount);
        ~OpenGLBuffer();

        void bind();
        void unbind();
        void draw();

    private:
        unsigned int m_VAO, m_VBO, m_EBO;
        unsigned int m_indexCount;
        bool hasIndex;
    };
}