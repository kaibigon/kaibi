#include "kaibi.h"

class Testbed : public KAIBI::Engine
{
public:
	Testbed()
	{
	}

	~Testbed()
	{

	}
};

KAIBI::Engine* KAIBI::CreateEngine()
{
    return new Testbed();
}
