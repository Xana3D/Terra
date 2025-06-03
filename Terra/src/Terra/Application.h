#pragma once

#include "Core.h"

namespace Terra {

	class TERRA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

