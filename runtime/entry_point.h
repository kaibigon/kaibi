#include <iostream>
#include "engine.h"

int main(int argc, char* argv[]) 
{
    auto app = KAIBI::CreateEngine();

    KAIBI::Engine* engine = new KAIBI::Engine();

    engine->startEngine();

    engine->run();

    engine->shutdownEngine();

    delete engine;

    return 0;
}

// #ifdef KB_PLATFORM_WINDOWS

extern KAIBI::Engine* KAIBI::CreateEngine();



// #endif