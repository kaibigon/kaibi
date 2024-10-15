#include "pch.h"
#include "function/render/opengl_buffer.h"

namespace KAIBI
{

    VertexBuffer::VertexBuffer()
    {
    }

    VertexBuffer::~VertexBuffer()
    {
    }

    void VertexBuffer::bind()
    {
    }

    void VertexBuffer::unbind()
    {
    }

    VertexBuffer* VertexBuffer::create(float* vertices, size_t size)
    {
        return nullptr;
    }


    IndexBuffer::IndexBuffer()
    {
    }

    IndexBuffer::~IndexBuffer()
    {
    }

    void IndexBuffer::bind()
    {
    }

    void IndexBuffer::unbind()
    {
    }

    IndexBuffer* IndexBuffer::create(unsigned int* indices, size_t size)
    {
        return nullptr;
    }
}
