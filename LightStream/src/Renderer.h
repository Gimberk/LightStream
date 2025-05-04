#pragma once

#include "Walnut/Image.h"

#include "Camera.h"

#include <memory>
#include <vector>

class Renderer
{
public:
	/// <summary>
	/// Renders the scene into an image. Should be called before calling "GetFinalImage"
	/// </summary>
	/// <param name="camera">The scene camera</param>
	void Render(const Camera& camera);

	/// <summary>
	/// Updates the image data to the current size
	/// </summary>
	/// <param name="width">New width</param>
	/// <param name="height">New Height</param>
	const void OnResize(uint32_t width, uint32_t height);

	/// <summary>
	/// Returns the final image created by "Render"
	/// </summary>
	/// <returns>The Final Image Render</returns>
	std::shared_ptr<Walnut::Image> GetFinalImage() { return img; }
private:
	glm::vec4 PerPixel(uint32_t x, uint32_t y);
private:
	std::shared_ptr<Walnut::Image> img;
	uint32_t* imageData = nullptr;

	std::vector<uint32_t> imageRowIterator, imageColumnIterator;

	const Camera* camera = nullptr;
};