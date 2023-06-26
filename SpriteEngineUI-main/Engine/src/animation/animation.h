#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Time.h"

namespace s2d
{
	class Sprite;
	class Animation
	{
	private:
		sf::Texture m_base;
		sf::Texture m_sec;

	public:
		std::string name;
		int currentFrame;
		float delay;
		float timePassed;

		bool isPlaying;

		Sprite* ptr_appliedSprite;

		Animation(Sprite* ptr_appliedSprite, std::string name, std::string basePath, std::string secondPath, float delay);

		void play();
		void update();
		void stop();
	};
}

