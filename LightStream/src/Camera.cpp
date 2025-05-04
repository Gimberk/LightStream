#include "Camera.h"

const void Camera::OnResize(uint32_t width, uint32_t height) {
	viewportWidth = width; viewportHeight = height;
}