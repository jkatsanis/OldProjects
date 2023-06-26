#include "Testing.h"

//User classes

void Testing::start()
{
	this->m_spriteSpeed = 2000;

	//Crash because we tried to acces a nullptr
	thisSprite = s2d::Sprite::getSpriteByName("Sprite 1");
	camera = &s2d::GameObject::camera;

	//User classes
}

void Testing::update()
{
	if (s2d::Input::isKeyPressing(s2d::Input::KeyCode::A))
	{
		thisSprite->transform.position.x -= m_spriteSpeed * s2d::Time::deltaTime;
	}
	if (s2d::Input::isKeyPressing(s2d::Input::KeyCode::D))
	{
		thisSprite->transform.position.x += m_spriteSpeed * s2d::Time::deltaTime;
	}
	if (s2d::Input::isKeyPressing(s2d::Input::KeyCode::W))
	{
		thisSprite->transform.position.y += m_spriteSpeed * s2d::Time::deltaTime;
	}
	if (s2d::Input::isKeyPressing(s2d::Input::KeyCode::S))
	{
		thisSprite->transform.position.y -= m_spriteSpeed * s2d::Time::deltaTime;
	}
	
	if (s2d::Input::isKeyPressed(s2d::Input::KeyCode::P))
	{
		s2d::Sprite::activeSprites[1]->transform.position.y += 100;
	}
	//Only 1 static camera
	camera->setPosition(thisSprite->transform.position);

	//Almost like in unity 
}
 