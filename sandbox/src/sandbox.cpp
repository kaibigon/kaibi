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
