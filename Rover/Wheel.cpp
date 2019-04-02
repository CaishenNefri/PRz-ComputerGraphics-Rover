#include "Wheel.h"

Wheel::Wheel(GLdouble radius, GLdouble depth,
	GLdouble bX, GLdouble bY, GLdouble bZ) :
	Part(bX, bY, bZ)
{
	this->radius = radius;
	this->depth = depth;

	color[Color::r] = 0.0;
	color[Color::g] = 0.0;
	color[Color::b] = 0.0;
	color[Color::a] = 1.0;
}

Wheel::~Wheel()
{
}

void Wheel::draw()
{
	GLdouble posD[3],
		alpha, a, h;
	posD[Param::x] = pos[Param::x];
	posD[Param::y] = pos[Param::y];
	posD[Param::z] = pos[Param::z] + depth / 2;

	glColor3dv(color);
	//front wheel
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

	//rear wheel
	posD[Param::z] -= depth;
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

	//wall wheel
	glBegin(GL_TRIANGLE_FAN);
	for (GLint degree = 0; degree <= 360; degree++)
	{
		alpha = degToRad(degree);
		a = radius * cos(alpha);
		h = radius * sin(alpha);
		glVertex3d(posD[Param::x] - a, posD[Param::y] - h, posD[Param::z]);
		glVertex3d(posD[Param::x] - a, posD[Param::y] - h, posD[Param::z]+depth);
	}
	glEnd();
}	