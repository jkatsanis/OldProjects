#include "Input.h"

bool s2d::Input::isKeyPressed(KeyCode key)
{
	sf::Keyboard::Key keyd = static_cast<sf::Keyboard::Key>(static_cast<KeyCode>(key));

	if (s2d::Input::ptr_event_engine->type == sf::Event::KeyReleased)
	{
		keyIsPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(keyd) && !keyIsPressed)
	{
		s2d::Input::keyIsPressed = true;
		return true;
	}
	return false;
}

bool s2d::Input::isKeyPressing(KeyCode key)
{
	sf::Keyboard::Key keyd = static_cast<sf::Keyboard::Key>(static_cast<KeyCode>(key));
	return sf::Keyboard::isKeyPressed(keyd);
}


void s2d::Input::setWindow(sf::Event* window)
{
	s2d::Input::ptr_event_engine = window;
}

sf::Event* s2d::Input::ptr_event_engine = nullptr;
bool s2d::Input::keyIsPressed = false;
