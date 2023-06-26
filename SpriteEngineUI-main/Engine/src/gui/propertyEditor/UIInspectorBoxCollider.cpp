#include "UIInspectorBoxCollider.h"

s2d::UIInspectorBoxCollider::UIInspectorBoxCollider()
{
}

void s2d::UIInspectorBoxCollider::edit(float& x, float& y)
{
	ImGui::SetCursorPosX(x += 10);
	ImGui::Text("Edit");
	ImGui::SetCursorPos(ImVec2(x += 73.5f, y -= 2.5f));
	ImGui::Button(ICON_FA_EDIT);

	x -= 12.5f;
}

void s2d::UIInspectorBoxCollider::solid(float& x, float& y, s2d::Sprite* sprite)
{
	ImGui::SetCursorPosX(x -= 60.4f);
	ImGui::Text("Solid");
	ImGui::SameLine();
	ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize);
	ImGui::Checkbox("##Solid", &sprite->collider.isSolid);
	ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize);
	ImGui::Dummy(ImVec2(0, 5));

	y += 40;
}

void s2d::UIInspectorBoxCollider::width(float x, float y, s2d::Sprite* sprite)
{
	ImGui::SetCursorPosX(x -= 11);
	ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize + 0.1f);
	if (ImGui::TreeNode("Width"))
	{
		ImGui::SetCursorPos(ImVec2(x += 30, y += 80));
		ImGui::Text("L");

		ImGui::SetCursorPos(ImVec2(x += 30, y));
		ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize - 0.5f);
		ImGui::SliderFloat("##WidthL", &sprite->collider.boxColliderWidthLeftOrRight.x, -500, 500);
		ImGui::SameLine();
		if (ImGui::Button(ICON_FA_RETWEET))
		{
			sprite->collider.boxColliderWidthLeftOrRight.x = 0;
		}
		ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize);

		ImGui::SetCursorPos(ImVec2(x -= 28.4f, y += 40));
		ImGui::Text("R");

		ImGui::SetCursorPos(ImVec2(x += 29, y));
		ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize - 0.5f);
		ImGui::SliderFloat("##WidthR", &sprite->collider.boxColliderWidthLeftOrRight.y, -500, 500);
		ImGui::SameLine();
		if (ImGui::Button(ICON_FA_RETWEET " "))
		{
			sprite->collider.boxColliderWidthLeftOrRight.y = 0;
		}
		ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize);
		ImGui::TreePop();
	}
	ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize);
}

void s2d::UIInspectorBoxCollider::height(s2d::Sprite* sprite)
{
	float x = ImGui::GetCursorPosX();
	float y = ImGui::GetCursorPosY();
	ImGui::SetCursorPosX(x -= 1.5f);

	ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize + 0.07f);
	if (ImGui::TreeNodeEx("Height"))
	{
		ImGui::SetCursorPos(ImVec2(x += 33.5f, y += 35));
		ImGui::Text("U");

		ImGui::SetCursorPos(ImVec2(x += 30, y));
		ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize - 0.5f);
		ImGui::SliderFloat("##up", &sprite->collider.boxColliderHeightUpOrDown.x, -500, 500);
		ImGui::SameLine();
		if (ImGui::Button(ICON_FA_RETWEET))
		{
			sprite->collider.boxColliderHeightUpOrDown.x = 0;
		}
		ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize);

		ImGui::SetCursorPos(ImVec2(x -= 28.4f, y += 40));
		ImGui::Text("D");

		ImGui::SetCursorPos(ImVec2(x += 28, y));
		ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize - 0.5f);
		ImGui::SliderFloat("##down", &sprite->collider.boxColliderHeightUpOrDown.y, -500, 500);
		ImGui::SameLine();
		if (ImGui::Button(ICON_FA_RETWEET " "))
		{
			sprite->collider.boxColliderHeightUpOrDown.y = 0;
		}
		ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize);
		ImGui::TreePop();
	}
	ImGui::SetWindowFontScale(s2d::UIInfo::sdefaultFontSize);
}

void s2d::UIInspectorBoxCollider::drawBoxCollider(s2d::Sprite* sprite)
{
	sf::Vector2f size = sf::Vector2f(sprite->transform.scale.x + (-sprite->collider.boxColliderWidthLeftOrRight.x + sprite->collider.boxColliderWidthLeftOrRight.y),
		sprite->transform.scale.y + (-sprite->collider.boxColliderHeightUpOrDown.x + sprite->collider.boxColliderHeightUpOrDown.y));

	s2d::GameObject::rects[1].setSize(size);
	s2d::GameObject::rects[1].setOutlineColor(sf::Color(124, 252, 0));
	s2d::GameObject::rects[1].setOutlineThickness(3.5f);
	s2d::GameObject::rects[1].setPosition(sf::Vector2f(sprite->getOrigininalPosition().x + sprite->collider.boxColliderWidthLeftOrRight.x, sprite->getOrigininalPosition().y + sprite->collider.boxColliderHeightUpOrDown.x));

	if (texture.loadFromFile("EngineAssets/Sprites/transparent.png"))
	{
		s2d::GameObject::rects[1].setTexture(&texture);
	}
}
