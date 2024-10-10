#include "pch.h"
#include "engine.h"
#include "core/log/log_system.h"
#include "function/render/window_system.h"
#include "function/render/imgui_system.h"
#include "function/global/global_context.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include "glad/glad.h"

namespace KAIBI	
{
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

		glClearColor(1.0f, 0.5f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// imgui
		g_runtime_global_context.m_imgui_system->newFrame();
		g_runtime_global_context.m_imgui_system->render();

		g_runtime_global_context.m_window_system->pollEvents();

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