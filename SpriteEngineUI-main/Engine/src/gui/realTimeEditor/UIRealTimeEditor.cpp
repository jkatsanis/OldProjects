#include "UIRealTimeEditor.h"

//Constructor

s2d::UIRealTimeEditor::UIRealTimeEditor() 
{ 
	this->m_isAnyUIWindowHovered = nullptr;
	this->m_ptr_event_engine = nullptr;
	this->m_ptr_renderWindow = nullptr; 
	this->m_arrowSpeed = 0.0f;
	this->m_scrollSpeed = 0.0f;
}

s2d::UIRealTimeEditor::UIRealTimeEditor(sf::RenderWindow& window, sf::Event* event, bool* isAnyUIWindowHovered)
{
	this->m_ptr_renderWindow = &window;
	this->m_camera = s2d::Camera(&window);
	this->m_isAnyUIWindowHovered = isAnyUIWindowHovered;
	this->m_ptr_event_engine = event;
	this->m_arrowSpeed = 200;
	this->m_scrollSpeed = 0.005f;

	//Loading camera settings from file
	this->loadCameraSettingsFromFile();
}

//Public functions

void s2d::UIRealTimeEditor::update()
{
	if (*this->m_isAnyUIWindowHovered) return;
	s2d::GameObject::ptr_camera_tRealTimeEditor = &this->m_camera;

	this->navigateRightClick();
	this->navigateScrollWheel();
	this->navigateArrows();

	//Camera update
	this->m_camera.update();
}

//Private functions

void s2d::UIRealTimeEditor::navigateRightClick()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(*this->m_ptr_renderWindow);

		float x = float(mousePos.x) - 960.0f;
		float y = float(mousePos.y) - 540.0f;
		this->m_camera.transform.position.x = x;
		this->m_camera.transform.position.y = y;
	}
}

void s2d::UIRealTimeEditor::navigateScrollWheel()
{
	if (this->m_ptr_event_engine->type == sf::Event::MouseWheelScrolled && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		if (this->m_ptr_event_engine->mouseWheel.x < 0)
		{
			if (this->m_camera.cameraZoom + this->m_scrollSpeed < 10)
			{
				calculateScrollWheelSpeed();

				this->m_camera.cameraZoom += this->m_scrollSpeed;
			}
		}
		else 
		{
			if (this->m_camera.cameraZoom - this->m_scrollSpeed > 0.04)
			{
				calculateScrollWheelSpeed();

				this->m_camera.cameraZoom -= this->m_scrollSpeed;
			}
		}
	}
}


void s2d::UIRealTimeEditor::calculateScrollWheelSpeed()
{
	sf::Vector2f size = this->m_camera.cameraView.getSize();

	if (size.x > 1500)
	{
		this->m_scrollSpeed = 0.006f;
	}
	else if (size.x > 1000)
	{
		this->m_scrollSpeed = 0.005f;
	}
	else if (size.x > 750)
	{
		this->m_scrollSpeed = 0.004f;
	}
	else
	{
		this->m_scrollSpeed = 0.0008f;
	}
}

void s2d::UIRealTimeEditor::loadCameraSettingsFromFile()
{
	std::fstream cameraFile;

	//opening the file where all sprite data is
	cameraFile.open("saves\\camera.txt", std::ios::in);
	if (cameraFile.is_open())
	{
		std::string line;
		int cnt = 0;
		while (std::getline(cameraFile, line))
		{
			cnt++;
			//First line is the header so we dont need to check for it
			if (cnt == 1)
			{
				continue;
			}

			//Splitting line
			std::string delimiter = ";";
			std::string* propertys = std::splitString(line, delimiter);

			//INITIIALIZING PROPS
			this->m_camera.transform.position.x = std::stof(propertys[0].c_str());
			this->m_camera.transform.position.y = std::stof(propertys[1].c_str());
			this->m_camera.cameraZoom = std::stof(propertys[2].c_str());
		}
		cameraFile.close();
	}
}


void s2d::UIRealTimeEditor::navigateArrows()
{
	if (s2d::Input::isKeyPressing(s2d::Input::Left))
	{
		this->m_camera.transform.position.x += this->m_arrowSpeed * s2d::Time::deltaTime;
	}
	if (s2d::Input::isKeyPressing(s2d::Input::Right))
	{
		this->m_camera.transform.position.x -= this->m_arrowSpeed * s2d::Time::deltaTime;
	}
	if (s2d::Input::isKeyPressing(s2d::Input::Up))
	{
		this->m_camera.transform.position.y -= this->m_arrowSpeed * s2d::Time::deltaTime;
	}
	if (s2d::Input::isKeyPressing(s2d::Input::Down))
	{
		this->m_camera.transform.position.y += this->m_arrowSpeed * s2d::Time::deltaTime;
	}
}