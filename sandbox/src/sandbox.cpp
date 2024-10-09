#include "kaibi.h"

class Sandbox : public KAIBI::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{

	}
};

KAIBI::Application* KAIBI::CreateApplication()
{
    return new Sandbox();
}


// int main(int argc, char* argv[]) 
// {
//     auto app = KAIBI::CreateApplication();
//     app->Run();
//     delete app;
//     return 0;
// }
