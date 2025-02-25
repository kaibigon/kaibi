#pragma once

#include "core/base/core.h"
#include "function/render/opengl_buffer.h"
#include "function/render/opengl_shader.h"
#include "function/render/graphics_context.h"
#include <GLFW/glfw3.h>
#include <memory>


class GLFWwindow; 
namespace KAIBI
{
    class KAPI OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow* window);
        void initialize() override;
        void swapBuffers() override;

        void bindShader() override;
        void draw() override;
        void clear() override;

    private:
        GLFWwindow* m_window;
        std::unique_ptr<OpenGLShader> m_shader;
        std::shared_ptr<Mesh> m_mesh;
    };
}