#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"
#include "Walnut/Random.h"
#include "Walnut/Timer.h"

#include "Renderer.h"

using namespace Walnut;

class MainLayer : public Layer
{
public:
	MainLayer() : camera() {}

	virtual void OnUIRender() override {
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("Viewport");
		
		viewportWidth = ImGui::GetContentRegionAvail().x;
		viewportHeight = ImGui::GetContentRegionAvail().y;

		std::shared_ptr<Image> img = renderer.GetFinalImage();
		if (img)
			ImGui::Image(img->GetDescriptorSet(), { (float)img->GetWidth(), (float)img->GetHeight() });

		ImGui::End();
		ImGui::PopStyleVar();


		ImGui::Begin("Scene");
		ImGui::Text("Render Time: %0.2fms", renderTime);
		if (ImGui::Button("Render"))
			Render();
		ImGui::End();
	}

	void Render() {
		Timer timer;

		renderer.OnResize(viewportWidth, viewportHeight);
		camera.OnResize(viewportWidth, viewportHeight);

		renderer.Render(camera);
		renderTime = timer.ElapsedMillis();
	}
private:
	uint32_t viewportWidth = 0, viewportHeight = 0;

	Camera camera;
	Renderer renderer;

	float renderTime = 0.0f;
};

Application* Walnut::CreateApplication(int argc, char** argv)
{
	ApplicationSpecification spec;
	spec.Name = "LightStream";

	Application* app = new Application(spec);
	app->PushLayer<MainLayer>();
	return app;
}