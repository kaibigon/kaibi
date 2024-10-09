#include <iostream>
#include <spdlog/spdlog.h>
#include "log/logger.h"

int main(int argc, char* argv[]) 
{
    KAIBI::Logger* logger = new KAIBI::Logger();
    std::cout << logger->GetTime() << std::endl;
    delete logger;
    // KAIBI::Logger::Init();
    // KAIBI::Logger::GetCoreLogger()->info("Welcome to kaibigon's kaibi Engine!");
    std::cout << "Welcome to kaibigon's ngine!" << std::endl;

    auto app = KAIBI::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

// #ifdef KB_PLATFORM_WINDOWS

extern KAIBI::Application* KAIBI::CreateApplication();



// #endif