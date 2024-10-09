#include <iostream>

#ifdef KB_PLATFORM_WINDOWS

extern KAIBI::Application* KAIBI::CreateApplication();

int main(int argc, char* argv[]) 
{
    std::cout << "Welcome to Kaibi Engine!" << std::endl;
    auto app = KAIBI::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif