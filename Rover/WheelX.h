#pragma once
#include "Geom.h"
#include "Disc.h"

class WheelX : public Geom
{
public:
	float R, H;
	Shape* wheelTrimF;
	Shape* wheelTrimR;

	WheelX(float r, float h) : R{ r }, H{ h }
	{
		int steps = 15;
		float f 2 * M_PI / steps;
		float r2 = r * 0.8;

		
		wheelTrimF = new Disc(BLUE);
		wheelTrimR = new Disc(BLUE);

		this->Shapes.push_back(wheelTrimF
			->WithPosition(Vec3(h / 3, 0, 0))
			->WithScale(r * 0.9)
			->WithRotation(Quat::FromAngleAxis(Deg2Rad(90), Vec3::Forward())));

		this->Shapes.push_back(wheelTrimR
			->WithPosition(Vec3(-h / 3, 0, 0))
			->WithScale(r * 0.9)
			->WithRotation(Quat::FromAngleAxis(Deg2Rad(90), Vec3::Forward())));
	}
};