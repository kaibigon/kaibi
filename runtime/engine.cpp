#include "pch.h"
#include "engine.h"
#include "core/log/log_system.h"
#include "function/render/window_system.h"
#include "function/global/global_context.h"

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
		g_runtime_global_context.startSystems();
		g_runtime_global_context.m_log_system->Log(LogLevel::Info, "Engine Start Systems!");

		// TODO: callback test, remove me
		g_runtime_global_context.m_window_system->registerOnKeyFunc([](int key, int scancode, int action, int mods)
		{
			LOG_INFO("Key: %c, Scancode: %d, Action: %d, Mods: %d", (char)key, scancode, action, mods);
		});
	}

	void Engine::shutdownEngine()
	{
		g_runtime_global_context.shutdownSystems();
	}

	void Engine::tickOneFrame()
	{
		// logic tick
		
		// fps

		// render tick

		// window poll event
		g_runtime_global_context.m_window_system->pollEvents();
        const bool should_window_close = g_runtime_global_context.m_window_system->shouldClose();
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