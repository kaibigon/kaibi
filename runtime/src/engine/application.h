#pragma once
#include "core/core.h"

namespace KAIBI 
{
	class KAPI Application
	{
	public:
		Application();
		virtual ~Application();

		void Run(); // core game loop

	};

    Application* CreateApplication();
}