#pragma once

#include <SFML/Graphics.hpp>
#include <vector2.h>
#include <boxColliderPositionData.h>
#include <iostream>

namespace s2d
{
	class Sprite;
	class BoxCollider
	{
	private:
		int m_start = -5;
		int m_end = 5;

		void checkPositions(const BoxCollider& other, const int jIndex);
		bool checkUpPosition(const s2d::BoxCollider& other);
		bool checkDownPosition(const s2d::BoxCollider& other);
		bool checkRightPosition(const s2d::BoxCollider& other);
		bool checkLeftPosition(const s2d::BoxCollider& other);

	private:
		static bool checkIAndJPCollisions(int i, int j);

	public:
		bool isSolid;
		bool canCollide;
		bool exists;
		bool isInCollision;

		s2d::BoxColliderPositionData positionData;
		s2d::Sprite* sprite;
		s2d::Sprite* collidingSprite;

		Vector2 boxColliderWidthLeftOrRight;
		Vector2 boxColliderHeightUpOrDown;

		BoxCollider();

		//Giving it a pointer, so we dont have to update it consistently
		BoxCollider(s2d::Sprite* sprite);

		//what is the j index? Eventually we collide we a object two times and so we need to push the object 
		//In two directions. When we We pushed it we reset the array and check for new collisions
		bool checkCollision(s2d::BoxCollider& other, const int jIndex);

	public:
		static void checkCollisions();
	};
}

