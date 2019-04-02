#include "Cylinder.h"
#include "Circle.h"



Cylinder::Cylinder(GLdouble radius, GLdouble height,
	GLdouble bX, GLdouble bY, GLdouble bZ) :
	Part(bX, bY, bZ)
{
	this->radius = radius;
	this->height = height;
}

Cylinder::~Cylinder()
{
}

void Cylinder::draw()
{
	GLdouble posD[3],
		alpha, a, h;
	posD[Param::x] = pos[Param::x];
	posD[Param::y] = pos[Param::y] - height / 2;
	posD[Param::z] = pos[Param::z];

	auto bottomCircle = new Circle(radius, 90, Param::x, posD);
	bottomCircle->draw();
	/*bottomCircle->pos[Param::y] + height;
	bottomCircle->draw();*/

	////bottom basis
	//glPushMatrix();
	//glRotated(90, 1, 0, 0);
	//	
	//glBegin(GL_TRIANGLE_FAN);
	//glVertex3dv(posD);
	//for (GLint degree = 0; degree <= 360; degree++)
	//{
	//	alpha = degToRad(degree);
	//	a = radius * cos(alpha);
	//	h = radius * sin(alpha);
	//	glVertex3d(posD[Param::x] - a, posD[Param::y] - h, posD[Param::z]);
	//}
	//glEnd();
	//glPopMatrix();
}
