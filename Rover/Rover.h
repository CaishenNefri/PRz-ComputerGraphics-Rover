#pragma once
#include "Wheel.h"
#include "Body.h"

class Rover
{
public:
	Rover();
	~Rover();

	void draw();

	GLdouble pos[3];
	GLint amountWheels;
	GLdouble sizeWheel, depthWheel, width, heigth, depth;

	Wheel *wheelL1;
	Wheel *wheelL2;
	Wheel *wheelL3;
	
	Wheel *wheelR1;
	Wheel *wheelR2;
	Wheel *wheelR3;

	Wheel *suspensionL1;
	Wheel *suspensionL2;
	Wheel *suspensionL3;

	Wheel *suspensionR1;
	Wheel *suspensionR2;
	Wheel *suspensionR3;

	Body *body;
};

