#pragma once

#include <stransform.h>
#include <vector2.h>
#include <line.h>
#include "SFML/Graphics.hpp"
#include <camera.h>	

namespace s2d
{
	class GameObject
	{
	public:
		GameObject() = delete;

	public:
		static std::vector<s2d::Line> lines;
		static std::vector <sf::RectangleShape> rects;

		//Pointer to the camera in "UIRealTimeEditor"
		static s2d::Camera* ptr_camera_tRealTimeEditor;
	};
}
