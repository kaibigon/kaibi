#include <iostream>
#include "engine.h"

int main(int argc, char* argv[]) 
{
    // auto app = KAIBI::CreateEngine();

    KAIBI::Engine* engine = new KAIBI::Engine();

    engine->startEngine();

    engine->run();

    engine->shutdownEngine();

    std::cout << "start delete engine!" << std::endl;
    delete engine;
    std::cout << "finish delete engine!" << std::endl;

    return 0;
}

// #ifdef KB_PLATFORM_WINDOWS

extern KAIBI::Engine* KAIBI::CreateEngine();



// #endif