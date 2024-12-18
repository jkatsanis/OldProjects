#pragma once

#include <vector2.h>

namespace s2d
{
	class Sprite;
	class PhsysicsBody
	{
	public:

		float mass;
		float gravity;
		bool exists;
		s2d::Vector2 velocity;

		s2d::Sprite* ptr_attachedSprite;

		PhsysicsBody();
		PhsysicsBody(s2d::Sprite* ptr_attachedSprite);

		void resetPhysicsBody();

		void fixedUpdate();
	};
}