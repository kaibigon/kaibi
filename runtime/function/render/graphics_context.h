#pragma once

#include "core/base/core.h"

// this is somehow completely useless for now as we only have opengl context for now
namespace KAIBI
{
    class KAPI GraphicsContext
    {
    public:
        virtual void initialize() = 0;
        virtual void swapBuffers() = 0;

        // init serveral contexts like this???
        static GraphicsContext* createOpenGLContext(void* window);

    };
}