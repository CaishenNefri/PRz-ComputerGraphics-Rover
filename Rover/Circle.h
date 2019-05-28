#pragma once
#include "Part.h"
class Circle :
	public Part
{
public:
	Circle(GLdouble radius, GLdouble angle, Param axis);
	Circle(GLdouble radius, GLdouble angle, Param axis, GLdouble posD[3]);
	~Circle();

	void draw();
protected:
	GLdouble radius, height, angle;
	Param axis;
};

