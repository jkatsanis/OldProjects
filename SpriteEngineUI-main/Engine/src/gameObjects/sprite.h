#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <spriteData.h>
#include <stdExtension.h>
#include <gameObject.h>
#include <boxCollider.h>
#include <SFML/Graphics.hpp>
#include <physicsBody.h>
#include <animator.h>

namespace s2d
{
	class Sprite
	{
	private:
		sf::Sprite m_sprite;
		sf::Texture m_texture;
		int m_vectorPosition;
		int m_id;
		int m_parentId;
		int m_childCount;
		int m_listPos;

		void initVariables(std::string name, s2d::Vector2 spawnPos, std::string path);
		void setTextureSize();

	public:
		
		// General info
		std::string name;
		std::string path;
		int sortingLayerIndex;

		// Components
		s2d::BoxCollider collider;
		s2d::PhsysicsBody physicsBody;
		s2d::Transform transform;
		s2d::Animator animator;

		//Parent / child infos
		std::vector<s2d::Sprite*> childs;
		s2d::Sprite* parent;

		Sprite();
		Sprite(std::string name, s2d::Vector2 spawnPosition, std::string path);
		Sprite(std::string name, s2d::Vector2 spawnPosition, std::string path, bool addToWindowByConstruction);

		void resetChildData();
		void updateTransformPosition();
		void setSpriteTexture(std::string path);
		void setParent(s2d::Sprite* sprite);
		void addSpriteToScene();
		bool containsChild(s2d::Sprite* child);
		s2d::Vector2 getOrigininalPosition();
	
	public:

		void setId(const int id) { this->m_id = id; }
		void setVectorPosition(const int vec) { this->m_vectorPosition = vec; }

		int getId() const { return this->m_id; }
		int getParentId() const { return this->m_parentId; }
		int getChildCount() const { return this->m_childCount; }
		int getChildListPosition() const { return this->m_listPos; }

		int getVectorPosition() { return this->m_vectorPosition; }
		sf::Sprite& getSprite() { return this->m_sprite; }																

	public:
		static void initActiveSprites();
		static int getMaxNumber(std::vector<s2d::Sprite*>& vec);
		static void updateHightestLayerIndex();
		static s2d::Sprite* getSpriteById(int id);

		static int highestLayerIndex;

		//Pointers getting deletet in gameWindow.cpp ~
		static std::vector<s2d::Sprite*> activeSprites;
	};
}

