#include "engine.h"
#include "pch.h"
#include "core/log/log_system.h"
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

    void Engine::run()
    {
		while(true)
		{

		}
    }
}