#include "pch.h"
#include "engine.h"
#include "core/log/log_system.h"
#include "function/render/window_system.h"
#include "function/render/imgui_system.h"
#include "function/global/global_context.h"
#include "function/render/render_system.h"

#include <GLFW/glfw3.h>
#include "glad/glad.h"

namespace KAIBI	
{
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

    unsigned int m_vertexArray, m_vertexBuffer, m_indexBuffer;
    unsigned int vertexShader, fragmentShader, shaderProgram;

	Engine::Engine()
	{
	}

	Engine::~Engine()
	{
	}

	void Engine::startEngine()
	{
		LOG_INFO("------START ENGINE");
		g_runtime_global_context.startSystems();
		LOG_INFO("---START SUBSYSTEMS");

		// abstract this
		float vertices [] = {
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
		};

		unsigned int indices[3] = {
			0, 1, 2
		};

		glGenVertexArrays(1, &m_vertexArray);
		glBindVertexArray(m_vertexArray);

		glGenBuffers(1, &m_vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glGenBuffers(1, &m_indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}

	void Engine::shutdownEngine()
	{
		LOG_INFO("------SHUTDOWN SUBSYSTEMS");
		g_runtime_global_context.shutdownSystems();
		LOG_INFO("---SHUTDOWN SUBSYSTEMS");
	}

	bool Engine::tickOneFrame()
	{
		// logic tick
		
		// fps

		// render tick

		// window poll event

		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// glUseProgram(shaderProgram);
		g_runtime_global_context.m_render_system->render();

        glBindVertexArray(m_vertexArray); 
        glDrawArrays(GL_TRIANGLES, 0, 3);
		// glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

		// imgui
		g_runtime_global_context.m_imgui_system->newFrame();
		g_runtime_global_context.m_imgui_system->render();

		g_runtime_global_context.m_window_system->pollEvents();
		g_runtime_global_context.m_render_system->swapBuffers();

        const bool should_window_close = g_runtime_global_context.m_window_system->shouldClose();
        return !should_window_close;
	}

    void Engine::run()
    {
		std::shared_ptr<WindowSystem> window_system = g_runtime_global_context.m_window_system;

		while(!window_system->shouldClose())
		{
			tickOneFrame();
		}
    }
}