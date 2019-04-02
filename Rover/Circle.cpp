#include "Circle.h"


Circle::Circle(GLdouble radius, GLdouble angle, Param axis):
	Part()
{
	this->radius = radius;
	this->angle = angle;
	this->axis = axis;
}

Circle::Circle(GLdouble radius, GLdouble angle, Param axis, GLdouble posD[3]) :
	Part(posD)
{
	this->radius = radius;
	this->angle = angle;
	this->axis = axis;
}

Circle::~Circle()
{
}

void Circle::draw()
{

	//with angle=0 draw like O;
	GLdouble posD[3],
		alpha, a, h;
	posD[Param::x] = pos[Param::x];
	posD[Param::y] = pos[Param::y];
	posD[Param::z] = pos[Param::z];

	glPushMatrix();
	//glRotated(angle, 1, 0, 0);
	switch (axis)
	{
	case Param::x:
		glRotated(angle, 1, 0, 0);
		break;
	case Param::y:
		glRotated(angle, 0, 1, 0);
		break;
	case Param::z:
		glRotated(angle, 0, 0, 1);
		break;
	}

	glBegin(GL_TRIANGLE_FAN);
	glVertex3dv(posD);
	for (GLint degree = 0; degree <= 360; degree++)
	{
		alpha = degToRad(degree);
		a = radius * cos(alpha);
		h = radius * sin(alpha);
		glVertex3d(posD[Param::x] - a, posD[Param::y] - h, posD[Param::z]);
	}
	glEnd();
	glPopMatrix();
}
