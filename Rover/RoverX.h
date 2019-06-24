#include "Geom.h"
#include "WheelX.h"

class RoverX : public Geom
{
public:
	WheelX* wheel1L;
	WheelX* wheel1R;

	float WheelRadius = 13.5;
	RoverX()
	{
		this->Rotation *= Quat::FromAngleAxis(Deg2Rad(0), Vec3::Up());
		float h = 9;
		wheel1L = (WheelX*)(new WheelX(WheelRadius, h))->WithPosition(Vec3(-25, 30, 13));
		wheel1R = (WheelX*)(new WheelX(WheelRadius, h))->WithPosition(Vec3(25, 30, 13));

		this->Children.push_back(wheel1L);
		this->Children.push_back(wheel1R);		
	}
};