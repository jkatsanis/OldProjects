#pragma once

#include <ImGui.h>
#include <UIInfo.h>
#include <icons.h>
#include <iostream>
#include <sprite.h>
#include <UIHirachy.h>

namespace s2d
{
	class UIAnimation
	{
	private:
		//add frames 
		
		std::string m_current_sprite;
		std::string m_file_name;

		void getFileNameInput();
		void displayAnimations();
		void addAnimationsToAnimator();

	public:

		UIAnimation();

		void createUIAnimationWindow();
	};
}

