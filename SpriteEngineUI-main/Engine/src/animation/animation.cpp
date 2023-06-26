#include "Animation.h"
#include "Sprite.h"

s2d::Animation::Animation(Sprite* ptr_appliedSprite, std::string name, std::string basePath, std::string secondPath, float delay)
{
	this->timePassed = 0.0f;
	this->delay = delay;
	this->currentFrame = -1;
	this->name = name;
	this->ptr_appliedSprite = ptr_appliedSprite;
	this->m_base.loadFromFile(basePath);
	this->m_sec.loadFromFile(secondPath);
}

//This method will start the animation and will set the current framt to zero
void s2d::Animation::play()
{
	this->currentFrame = 0;
	this->isPlaying = true;
}

//This methods updates the animation with the delay
void s2d::Animation::update()
{
	this->timePassed += Time::deltaTime;

	if (timePassed >= delay / 100)
	{
		this->timePassed = 0;
		if (this->currentFrame == 0)
		{
			this->ptr_appliedSprite->getSprite().setTexture(m_base);
		}
		else if (this->currentFrame == 1)
		{
			this->ptr_appliedSprite->getSprite().setTexture(m_sec);
			this->currentFrame = -1;
		}
		this->currentFrame++;
	}
}

