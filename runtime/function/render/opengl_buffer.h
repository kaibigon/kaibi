#pragma once

namespace KAIBI
{
    class VertexBuffer
    {
    public:
        VertexBuffer();
        virtual ~VertexBuffer();

        virtual void bind() = 0;
        virtual void unbind() = 0;

        static VertexBuffer* create(float* vertices, size_t size);
    };

    class IndexBuffer
    {
    public:
        IndexBuffer();
        virtual ~IndexBuffer();

        virtual void bind();
        virtual void unbind();

        static IndexBuffer* create(unsigned int* indices, size_t size);
    };
}