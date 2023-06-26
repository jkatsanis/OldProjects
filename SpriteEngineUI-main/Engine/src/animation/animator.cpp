#include "Animator.h"
#include "Sprite.h"

s2d::Animator::Animator()
{
	this->exists = false;
	this->ptr_attachedSprite = nullptr;
}

s2d::Animator::Animator(Sprite* ptr_attachedSprite)
{
	this->exists = false;
	this->ptr_attachedSprite = ptr_attachedSprite;
}

void s2d::Animator::createAnimation(std::string name, std::string path, std::string path2, float delay)
{
	animations.push_back(Animation(ptr_attachedSprite, name, path, path2, delay));
}

void s2d::Animator::play(std::string name)
{
	for (Animation& anim : animations)
	{
		if (anim.name == name)
		{
			anim.play();
		}
	}
}

void s2d::Animator::update()
{
	for (Animation& anim : this->ptr_attachedSprite->animator.animations)
	{
		if (anim.isPlaying)
			anim.update();
	}
}

void s2d::Animator::resetComponent()
{
	this->ptr_attachedSprite = nullptr;
	this->exists = false;
	this->animations.clear();
}
