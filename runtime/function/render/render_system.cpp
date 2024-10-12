#include "pch.h"
#include "render_system.h"
#include "function/global/global_context.h"
#include "function/render/window_system.h"

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
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1); // enable vsync
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (!status)
        {
            LOG_ERROR("Failed to initialize GLAD");
            return;
        }
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
}