#include <Terra.h>

class Sandbox : public Terra::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Terra::Application* Terra::CreateApplication()
{
	return new Sandbox();
}