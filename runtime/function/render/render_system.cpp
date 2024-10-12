#include "pch.h"

#include "function/global/global_context.h"

#include "function/render/render_system.h"
#include "function/render/opengl_context.h"

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

    void RenderSystem::render()
    {
    }

}