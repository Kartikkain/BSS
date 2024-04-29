#include <BSS.h>

class ExampleLayer :public BSS::Layer
{
public:
	ExampleLayer()
		:Layer("Example"){}

	void OnUpdate() override
	{
		BSS_CORE_INFO("ExampleLayer::Update");
	}

	void OnEvent(BSS::Event& e)
	{
		BSS_CLIENT_TRACE("{0}", e);
	}
};
class Sandbox : public BSS::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new BSS::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

BSS::Application* BSS::CreateApplication()
{
	return new Sandbox();
}