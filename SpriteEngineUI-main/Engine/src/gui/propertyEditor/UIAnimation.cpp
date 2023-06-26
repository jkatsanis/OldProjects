#include "UIAnimation.h"

s2d::UIAnimation::UIAnimation()
{
	this->m_file_name = "<name>";
}
 
//Public functions

void s2d::UIAnimation::createUIAnimationWindow()
{
	if (s2d::UIInfo::srenderAssetFolder || s2d::UIHirachy::selectedSprite == nullptr)
	{
		return;
	}
	ImGui::Begin("##Animations", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
	
	ImGui::Text("Animations");
	ImGui::SameLine();
	ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX() + 300, ImGui::GetCursorPosY()));

	//Close button
	if (ImGui::Button("x"))
	{
		s2d::UIInfo::srenderAssetFolder = true;
	}

	this->getFileNameInput();
	this->displayAnimations();
	this->addAnimationsToAnimator();

	ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize);
	ImGui::SetWindowSize(ImVec2(500, 500));

	ImGui::End();
}

//Private functions

void s2d::UIAnimation::getFileNameInput()
{
	//Open popup
	if (ImGui::Button(ICON_FA_PLUS))
	{
		ImGui::OpenPopup("Lol");
	}

	ImGui::SameLine();
	ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 2);
	ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize - 0.2f);
	ImGui::Text("Add animations");
	ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize);

	ImVec2 animation_pos = ImGui::GetCursorScreenPos();
	ImGui::SetNextWindowPos(ImVec2(animation_pos.x + 22, animation_pos.y + 50));

	//Popup input
	if (ImGui::BeginPopup("Lol"))
	{
		ImGui::InputText("##addFile", const_cast<char*>(this->m_file_name.c_str()), size_t(6));

		ImGui::EndPopup();
	}
}

void s2d::UIAnimation::displayAnimations()
{
	for (s2d::Animation anim : s2d::UIHirachy::selectedSprite->animator.animations)
	{
		ImGui::MenuItem(anim.name.c_str());
	}
}

void s2d::UIAnimation::addAnimationsToAnimator()
{
	auto add = [](std::string& file_name)
	{
		if (file_name != "<name>")
		{
			s2d::UIHirachy::selectedSprite->animator.createAnimation(file_name, "d", "d", 500);

			//int animation_count = s2d::UIHirachy::selectedSprite->animator.animations.size();
		}

		file_name = "<name>";
	};

	if (!ImGui::IsPopupOpen("Lol"))
	{
		add(this->m_file_name);
	}

	if (ImGui::IsPopupOpen("Lol") && ImGui::IsKeyReleased(ImGuiKey_Enter))
	{
		add(this->m_file_name);
	}	
}
