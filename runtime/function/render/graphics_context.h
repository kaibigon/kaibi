#pragma once

#include "core/base/core.h"

// AS WE ONLY HAVE OPENGL CONTEXT FOR NOW
// SEEMS MEANINGLESS TO PRETEND WE HAVE OTHER GRAPHICS CONTEXT
namespace KAIBI
{
    class KAPI GraphicsContext
    {
    public:
        virtual ~GraphicsContext() = default;
        virtual void initialize() = 0;
        virtual void swapBuffers() = 0;
        virtual void bindShader() = 0;
        virtual void draw() = 0;
        virtual void clear() = 0;
    };
}