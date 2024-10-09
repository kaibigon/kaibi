#include "Application.h"
#include <spdlog/spdlog.h>

namespace KAIBI
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

    void Application::Run()
    {
        spdlog::info("Running Application");
    }
}