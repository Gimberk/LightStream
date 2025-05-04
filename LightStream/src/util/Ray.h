#pragma once

#include "glm/glm.hpp"

struct Ray {	
public:
	Ray(glm::vec3 origin, glm::vec3 direction) : origin(origin), direction(direction) {}
	Ray(glm::vec3 origin) : origin(origin), direction(glm::vec3(0.0f)) {}

	/// <summary>
	/// Returns a point on the ray at a specified value t
	/// </summary>
	/// <param name="t">Place where the point is located</param>
	/// <returns></returns>
	glm::vec3 at(const float t) const {
		// based on the ray formula R(t) = o + dt
		return origin + direction * t;
	}

	glm::vec3 origin, direction;
};