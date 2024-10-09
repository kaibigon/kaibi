#include <iostream>
#include <spdlog/spdlog.h>
#include "Logger.h"

int main(int argc, char* argv[]) 
{
    KAIBI::Logger::Init();
    KAIBI::Logger::GetCoreLogger()->info("Welcome to kaibigon's kaibi Engine!");

    auto app = KAIBI::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

// #ifdef KB_PLATFORM_WINDOWS

extern KAIBI::Application* KAIBI::CreateApplication();



// #endif