#include "pch.h"
#include "render_system.h"
#include "function/global/global_context.h"
#include "function/render/window_system.h"
#include "function/render/opengl_context.h"
#include "function/render/graphics_context.h"

#include <glad/glad.h>  

namespace KAIBI
{
    RenderSystem::RenderSystem()
    {
    }

    RenderSystem::~RenderSystem()
    {
    }

    void RenderSystem::initialize(GLFWwindow* window)
    {
#ifdef KB_GRAPHICS_OPENGL
        m_graphics_context = std::make_shared<OpenGLContext>(window);
        m_graphics_context->initialize();
#endif
    }

    void RenderSystem::shutdown()
    {
    }

    void RenderSystem::newFrame()
    {
    }

    void RenderSystem::render()
    {
        m_graphics_context->bindShader();
    }

    void RenderSystem::swapBuffers()
    {
        m_graphics_context->swapBuffers();
    }
}