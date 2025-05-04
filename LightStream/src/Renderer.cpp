#include "Renderer.h"
#include "Walnut/Random.h"

#include <execution>

const uint32_t ToRGBA(glm::vec4 color) {

}

const void Renderer::OnResize(uint32_t width, uint32_t height) {
	if (img) {
		if (img->GetWidth() == width && img->GetHeight() == height)
			return;
		img->Resize(width, height);
	}
	else
		img = std::make_shared<Walnut::Image>(width, height, Walnut::ImageFormat::RGBA);

	if (imageData) delete[] imageData;
	imageData = new uint32_t[width * height];

	imageRowIterator.resize(width);
	imageColumnIterator.resize(height);
	for (uint32_t i = 0; i < width; i++) imageRowIterator[i] = i;
	for (uint32_t i = 0; i < height; i++) imageColumnIterator[i] = i;
}

void Renderer::Render(const Camera& camera) {
	this->camera = &camera;

	std::for_each(std::execution::par, imageColumnIterator.begin(), imageColumnIterator.end(),
		[this](uint32_t y) {
			std::for_each(std::execution::par, imageRowIterator.begin(), imageRowIterator.end(),
				[this, y](uint32_t x) {
					size_t index = y * img->GetWidth() + x;

					glm::vec4 color = PerPixel(x, y);

					imageData[index] = glm::
				});
		});

	img->SetData(imageData);
}

glm::vec4 Renderer::PerPixel(uint32_t x, uint32_t y) {

}