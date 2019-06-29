#pragma once
#include "Geom.h"
#include "Rect.h"

class BodyX : public Geom
{
private:
	Shape* faceF;
	Shape* faceB;
	Shape* faceL;
	Shape* faceR;
	Shape* faceU;
	Shape* faceD;
public:
	BodyX(ColorF color = BLACK, float width = 30, float height = 10,
		float depth = 20)
	{
		this->Origin = Vec3(0, 0, 0);
		//this->WithScale(Vec3(width, height, depth));
		faceF = new Rect();
		faceB = new Rect();
		faceL = new Rect();
		faceR = new Rect();
		faceU = new Rect();
		faceD = new Rect();

		faceF->WithPosition(Vec3(0, 0, -depth / 2))
			 ->WithScale(Vec3(width,height,0));

		faceB->WithPosition(Vec3(0, 0, depth / 2))
			->WithScale(Vec3(width, height, 0));


		this->Shapes.push_back(faceF);
		this->Shapes.push_back(faceB);
	
	}
};