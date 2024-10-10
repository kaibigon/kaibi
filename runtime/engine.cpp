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
		g_runtime_global_context.m_log_system->Log(LogLevel::Info, "Engine Tick One Frame!");
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