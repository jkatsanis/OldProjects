#pragma once

#include <iostream>	
#include <vector>
#include <animation.h>
#include <stime.h>

namespace s2d
{
	class Sprite;
	class Animator
	{
	public:
		bool exists;
		Sprite* ptr_attachedSprite;
		std::vector<Animation> animations;

		Animator();
		Animator(Sprite* ptr_attachedSprite);

		void createAnimation(std::string name, std::string path, std::string path2, float delay);

		void play(std::string name);

		void update();

		void resetComponent();
	};
}

