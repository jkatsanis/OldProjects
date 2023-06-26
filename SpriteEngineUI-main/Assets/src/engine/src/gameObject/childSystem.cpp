#include "childSystem.h"
#include <sprite.h>

void s2d::ChildSystem::updatePositionToParent(s2d::Sprite* child)
{
	if (child->parent != nullptr)
	{
		s2d::Vector2 distance = s2d::Vector2(child->parent->transform.position - child->transform.position);
		child->transform.positionToParent = distance;
	}
}

void s2d::ChildSystem::updateChildPositionRecursivly(s2d::Sprite* parent)
{
	for (s2d::Sprite* child : parent->childs)
	{
		child->transform.position = parent->transform.position - child->transform.positionToParent;
		s2d::Vector2 distance = s2d::Vector2(parent->transform.position - child->transform.position);
		child->transform.positionToParent = distance;

		updateChildPositionRecursivly(child);
	}
}

void s2d::ChildSystem::resetPositionWhenChildIsColliding(s2d::Sprite* child)
{
	if (child->parent == nullptr)
	{
		return;
	}
	if (child->collider.positionData.isEqual(s2d::BoxColliderPositionData::Down))
	{
		//Basicly the we setting the parent that its colliding with a colldier under it even tho it deosnt but it wont move down like this
		s2d::Sprite* parent = child->parent;
		parent->collider.positionData.position[0] = s2d::BoxColliderPositionData::Down;			
	}
	if (child->collider.positionData.isEqual(s2d::BoxColliderPositionData::Left))
	{
		//Basicly the we setting the parent that its colliding with a colldier under it even tho it deosnt but it wont move left like this
		s2d::Sprite* parent = child->parent;
		parent->collider.positionData.position[0] = s2d::BoxColliderPositionData::Left;
	}	
if (child->collider.positionData.isEqual(s2d::BoxColliderPositionData::Right))
	{
		//Basicly the we setting the parent that its colliding with a colldier under it even tho it deosnt but it wont move down rigjt this
		s2d::Sprite* parent = child->parent;
		parent->collider.positionData.position[0] = s2d::BoxColliderPositionData::Right;
	}	
	if (child->collider.positionData.isEqual(s2d::BoxColliderPositionData::Up))
	{
		//Basicly the we setting the parent that its colliding with a colldier under it even tho it deosnt but it wont move up like this
		s2d::Sprite* parent = child->parent;
		parent->collider.positionData.position[0] = s2d::BoxColliderPositionData::Up;
	}

}
