#pragma once

#include "core/base/core.h"
#include "function/render/opengl_shader.h"
#include <GLFW/glfw3.h>
#include <memory>


class GLFWwindow; 
namespace KAIBI
{
    class KAPI OpenGLContext
    {
    public:
        OpenGLContext();
        void initialize(GLFWwindow* window);
        void swapBuffers();

        void bindShader();

    private:
        GLFWwindow* m_window;
        std::unique_ptr<OpenGLShader> m_shader;
    };
}