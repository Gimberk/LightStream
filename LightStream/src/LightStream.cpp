#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"
#include "Walnut/Random.h"

using namespace Walnut;

class ExampleLayer : public Layer
{
public:
	virtual void OnUIRender() override {
		ImGui::Begin("Scene");
		if (ImGui::Button("Render"))
			Render();
		ImGui::End();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("Viewport");
		
		viewportWidth = ImGui::GetContentRegionAvail().x;
		viewportHeight = ImGui::GetContentRegionAvail().y;

		if (img)
			ImGui::Image(img->GetDescriptorSet(), { (float)img->GetWidth(), (float)img->GetHeight() });

		ImGui::End();
		ImGui::PopStyleVar();
	}

	void Render() {
		if (!img || viewportWidth != img->GetWidth() || viewportHeight != img->GetHeight()) {
			img = std::make_shared<Image>(viewportWidth, viewportHeight, ImageFormat::RGBA);
			delete[] imageData;
			imageData = new uint32_t[viewportWidth * viewportHeight];
		}

		for (uint32_t i = 0; i < viewportWidth * viewportHeight; i++) {
			imageData[i] = Random::UInt();
			imageData[i] |= 0xffff00ff;
		}

		img->SetData(imageData);
	}
private:
	std::shared_ptr<Image> img;
	uint32_t* imageData = nullptr;

	uint32_t viewportWidth = 0, viewportHeight = 0;
};

Application* Walnut::CreateApplication(int argc, char** argv)
{
	ApplicationSpecification spec;
	spec.Name = "LightStream";

	Application* app = new Application(spec);
	app->PushLayer<ExampleLayer>();
	return app;
}