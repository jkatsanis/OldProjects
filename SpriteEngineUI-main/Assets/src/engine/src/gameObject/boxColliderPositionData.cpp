#include "boxColliderPositionData.h"

s2d::BoxColliderPositionData::BoxColliderPositionData()
{
	resetPosition();
}

void s2d::BoxColliderPositionData::resetPosition()
{
	for (int i = 0; i < 4; i++)
	{
		this->position[i] = s2d::BoxColliderPositionData::Position::Unknown;
	}
}

bool s2d::BoxColliderPositionData::isEverythingUnknown()
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		if (this->position[i] == s2d::BoxColliderPositionData::Position::Unknown)
		{
			cnt++;
		}
	}
	return cnt == 4;
}

bool s2d::BoxColliderPositionData::isEqual(s2d::BoxColliderPositionData::Position p)
{
	for (int i = 0; i < 4; i++)
	{
		if (position[i] == p)
		{
			return true;
		}
	}
	return false;
}
