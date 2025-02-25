#include "pch.h"
#include "opengl_context.h"
// #include "function/render/window_system.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace KAIBI
{
    OpenGLContext::OpenGLContext(GLFWwindow* window)
        : m_window(window)
    {
    }

    void OpenGLContext::initialize()
    {
        // opengl initialization
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

        std::string vertexShaderSource ="#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "layout (location = 1) in vec3 aColor;\n"
            "out vec3 ourColor;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos, 1.0);\n"
            "   ourColor = aColor;\n"
            "}\0";

        std::string fragmentShaderSource = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "in vec3 ourColor;\n"
            "void main()\n"
            "{\n"
            "   FragColor = vec4(ourColor, 1.0f);\n"
            "}\n\0";

        m_shader = std::make_unique<OpenGLShader>(vertexShaderSource, fragmentShaderSource);

		float vertices [] = {
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
		};

		unsigned int indices[3] = {
			0, 1, 2
		};

        m_buffer = std::make_shared<OpenGLBuffer>(vertices, 3 * 6, indices, 3);
    }


    void OpenGLContext::swapBuffers() 
    {
        glfwSwapBuffers(m_window);
    }

    void OpenGLContext::bindShader()
    {
        m_shader->bind();
    }

    void OpenGLContext::draw()
    {
        clear();
        m_buffer->bind();
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        m_buffer->unbind();
    }

    void OpenGLContext::clear()
    {
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}