#pragma once
#include "Shape.h"

class Rect : public Shape
{
public:
	Rect(ColorF color = BLACK, int hSteps = 10, int wSteps = 10)
	{
		this->Type = TriangleStrip;
		this->Color = color;
		this->Origin = Vec3(0, 0, 0);
		float height = 1, width = 1;
		
		Vec3 sPoint = Vec3(this->Origin.X - width/2,
							   this->Origin.Y + height/2,
							   this->Origin.Z);
		
		for (int h = 0; h<hSteps-1; h++)
			for (int w = 0; w < wSteps; w++)
			{
				Vec3 a = Vec3(
					sPoint.X + w * width / wSteps,
					sPoint.Y - h * height / hSteps,
					sPoint.Z);

				Vec3 b = Vec3(
					sPoint.X + w * width / wSteps,
					sPoint.Y - (h+1) * height / hSteps,
					sPoint.Z);
					
				this->AddPoint(a, UP, Vec2(0, 0));
				this->AddPoint(b, UP, Vec2(0, 0));
			}
	}
};