#pragma once

#include "glm\glm.hpp"

namespace Rendering
{
	struct VertexFormat
	{
		glm::vec4 position;
		glm::vec4 color;

		VertexFormat(const glm::vec4 &pos, const glm::vec4 &rgba)
		{
			position = pos;
			color = rgba;
		}

		VertexFormat() {}
	};
}