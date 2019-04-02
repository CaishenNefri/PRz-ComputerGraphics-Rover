#pragma once
#include "Part.h"
class Body : public Part
{
public:
	Body(GLdouble w, GLdouble h, GLdouble d,
		GLdouble bX = 0, GLdouble bY = 0, GLdouble bZ = 0);
	~Body();

	void draw();

protected:
	GLdouble height, width, depth;

};

