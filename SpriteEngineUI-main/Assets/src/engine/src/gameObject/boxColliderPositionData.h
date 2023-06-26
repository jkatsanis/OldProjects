#include <vector2.h>

namespace s2d
{
	class BoxColliderPositionData
	{
	public:
		BoxColliderPositionData();

		enum Position
		{
			Unknown = -1,
			Down = 0,
			Left,
			Right,
			Up
		};

		//Why 4? because we can collide with 4 collider surrounding us
		Position position[4];

		void resetPosition();	
		bool isEverythingUnknown();
		bool isEqual(s2d::BoxColliderPositionData::Position p);
	};
}