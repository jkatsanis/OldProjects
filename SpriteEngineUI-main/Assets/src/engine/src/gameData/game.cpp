#include "game.h"

s2d::Game::Game()
{
	this->m_timePassed = 2.0f;
	this->windowEvent.type = sf::Event::GainedFocus;
	this->ptr_renderWindow = nullptr;
}

s2d::Game::~Game()
{
	for (s2d::Sprite* sprite : s2d::Sprite::activeSprites)
	{
		delete sprite;
	}
}


bool s2d::Game::isGameRunning()
{
	return this->ptr_renderWindow->isOpen();
}

void s2d::Game::pollEngineEvents()
{
	for (s2d::Sprite* ptr_sprite : s2d::Sprite::activeSprites)
	{
		if (ptr_sprite->transform.position != ptr_sprite->transform.nextPos)
		{
			//Fire on pos event
			Transform::onPositionChange(ptr_sprite);
		}
	}
}


void s2d::Game::pollEvents()
{
	while (this->ptr_renderWindow->pollEvent(this->windowEvent))
	{
		if (this->windowEvent.type == sf::Event::Closed)
		{
			this->ptr_renderWindow->close();
		}
	}
}

void s2d::Game::render()
{
	float x = s2d::FileData::windowBackground.x;
	float y = s2d::FileData::windowBackground.y;
	float z = s2d::FileData::windowBackground.z;

	this->ptr_renderWindow->clear(sf::Color(sf::Uint8(x), sf::Uint8(y), sf::Uint8(z)));
	this->draw();
	this->ptr_renderWindow->display();
}

void s2d::Game::draw()
{
	this->drawSprites();
}

void s2d::Game::drawSprites()
{  
	//2s passed we can update out hightest layer index
	if (m_timePassed > 2)
	{
		s2d::Sprite::updateHightestLayerIndex();
		m_timePassed = 0;
	}
	for (int i = 0; i < s2d::Sprite::highteLayerIndex + 1; i++)
	{
		for (s2d::Sprite* sprite : s2d::Sprite::activeSprites)
		{
			if (sprite->sortingLayerIndex == i)
			{
				sprite->setSpritePosition();
				this->ptr_renderWindow->draw(sprite->getSprite());
			}
		}
	}
}

void s2d::Game::update()
{
	//User update!
	testing.update();

	//Engine update
	s2d::Time::update();
	//s2d::BoxCollider::checkCollisions();
	s2d::Physics::update();

	this->m_timePassed += s2d::Time::deltaTime;

	//Renderer / Events
	this->pollEvents();
	//Engine event
	this->pollEngineEvents();
	this->render();
}

void s2d::Game::start()
{
	//Engine 
	s2d::Sprite::initActiveSprites();
	s2d::Input::setWindow(&this->windowEvent);
	s2d::FileData::setWindowBackground();

	//User start!
	testing.start();

	//Engine 
	this->windowEvent.type = sf::Event::GainedFocus;
	this->ptr_renderWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), s2d::GameData::name, sf::Style::Default);

	s2d::GameObject::camera = s2d::Camera(*this->ptr_renderWindow);
}

