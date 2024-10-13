#include "pch.h"
#include "render_system.h"
#include "function/global/global_context.h"
#include "function/render/window_system.h"
#include "function/render/opengl_context.h"

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
        m_opengl_context = std::make_shared<OpenGLContext>();
        m_opengl_context->initialize(window);
    }

    void RenderSystem::shutdown()
    {
    }

    void RenderSystem::newFrame()
    {
    }

    void RenderSystem::render()
    {
    }

    void RenderSystem::swapBuffers()
    {
        m_opengl_context->swapBuffers();
    }
}