#pragma once

#ifdef TA_PLATFORM_WINDOWS

extern Terra::Application* Terra::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Terra::CreateApplication();
	app->Run();
	delete app;
}

#endif
