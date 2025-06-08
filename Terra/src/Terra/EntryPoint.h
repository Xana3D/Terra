#pragma once

#ifdef TA_PLATFORM_WINDOWS

extern Terra::Application* Terra::CreateApplication();

int main(int argc, char** argv)
{
	Terra::Log::Init();
	TA_CORE_WARN("Initialized Log!");
	int a = 5;
	TA_INFO("Hello! Var={0}", a);


	auto app = Terra::CreateApplication();
	app->Run();
	delete app;
}

#endif
