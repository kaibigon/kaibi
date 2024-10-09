#pragma once
#include "Core.h"

namespace KAIBI 
{
	class KAIBI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run(); // core game loop

	};

    Application* CreateApplication();
}