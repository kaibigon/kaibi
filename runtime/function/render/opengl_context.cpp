#include "pch.h"
#include "opengl_context.h"
// #include "function/render/window_system.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace KAIBI
{
    OpenGLContext::OpenGLContext()
    {
    }

    void OpenGLContext::initialize(GLFWwindow* window)
    {
        m_window = window;

        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(1); // enable vsync
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (!status)
        {
            LOG_ERROR("Failed to initialize GLAD");
            return;
        }
        else
        {
            LOG_INFO("OpenGL Version: %s", glGetString(GL_VERSION));
        }
    }

    void OpenGLContext::swapBuffers() 
    {
        glfwSwapBuffers(m_window);
    }
}