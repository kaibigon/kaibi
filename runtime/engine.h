#pragma once
#include "core/base/core.h"

namespace KAIBI 
{
	class KAPI Engine
	{
	public:
		Engine();
		virtual ~Engine();

		void startEngine();
		void shutdownEngine();
		void run(); // core game loop

		// Add delta time
		void tickOneFrame();

	};

    Engine* CreateEngine();
}