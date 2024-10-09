#include "Application.h"
#include <spdlog/spdlog.h>

namespace KAIBI
{
	KAIBI_API Application::Application()
	{
	}

	KAIBI_API Application::~Application()
	{
	}

    KAIBI_API void Application::Run()
    {
        while (true)
        {
            spdlog::info("Welcome to Kaibi Engine!");
        }
    }
}