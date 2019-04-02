#pragma once
#include "Part.h"


class Cylinder :
	public Part
{
public:
	Cylinder(GLdouble radius, GLdouble height,
		GLdouble bX = 0, GLdouble bY = 0, GLdouble bZ = 0);
	~Cylinder();

	void draw();

protected:
	GLdouble radius, height;
};

