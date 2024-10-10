#include "kaibi.h"

class Sandbox : public KAIBI::Engine
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{

	}
};

KAIBI::Engine* KAIBI::CreateEngine()
{
    return new Sandbox();
}
