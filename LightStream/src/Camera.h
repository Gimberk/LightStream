#pragma once

#include "util/Ray.h"
/// <summary>
/// A world scene camera
/// </summary>
class Camera {
public:
	Camera() : center(glm::vec3()) {}
	Camera(glm::vec3 origin) : center(origin) {}

	/// <summary>
	/// Updates the viewport with the current size
	/// </summary>b
	/// <param name="width">New width</param>
	/// <param name="height">New Height</param>
	const void OnResize(uint32_t width, uint32_t height);
private:
	glm::vec3 center;

	float focalLength = 1.0f;

	uint32_t viewportWidth = 0, viewportHeight = 0;
};