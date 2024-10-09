#include <iostream>
#include <spdlog/spdlog.h>
#include "log/logger.h"

int main(int argc, char* argv[]) 
{
    KAIBI::Logger::Init();
    LOG_INFO("Welcome to kaibigon's kaibi Engine!");
    LOG_WARN("This is a warning message!");
    LOG_ERROR("This is a error message!");

    auto app = KAIBI::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

// #ifdef KB_PLATFORM_WINDOWS

extern KAIBI::Application* KAIBI::CreateApplication();



// #endif