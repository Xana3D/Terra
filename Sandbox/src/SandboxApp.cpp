#include <Terra.h>

class ExampleLayer : public Terra::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		TA_INFO("ExampleLayer::Update");
	}

	void OnEvent(Terra::Event& event) override
	{
		TA_TRACE("{0}", event);
	}
};

class Sandbox : public Terra::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Terra::Application* Terra::CreateApplication()
{
	return new Sandbox();
}