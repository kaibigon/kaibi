#include "engine.h"
#include "core/log/logger.h"
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
	}

	void Engine::shutdownEngine()
	{
		g_runtime_global_context.shutdownSystems();
	}

    void Engine::run()
    {
		g_runtime_global_context.m_log_system->Log(LogLevel::Info, "Engine is running!");
    }
}