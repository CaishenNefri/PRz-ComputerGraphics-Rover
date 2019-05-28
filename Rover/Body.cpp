#include "Body.h"

Body::Body(GLdouble w, GLdouble h, GLdouble d,
	GLdouble bX, GLdouble bY, GLdouble bZ) :
	Part(bX, bY, bZ)
{
	width = w;
	height = h;
	depth = d;

	color[Color::r] = 1.0;
	color[Color::g] = 0.0;
	color[Color::b] = 0.0;
	color[Color::a] = 1.0;
}

Body::~Body()
{
}

void Body::draw()
{
	GLdouble posD[3];
	posD[Param::x] = pos[Param::x] - width / 2;
	posD[Param::y] = pos[Param::y] - height / 2;
	posD[Param::z] = pos[Param::z] + depth / 2;

	glColor4dv(color);

	//front wall
	glBegin(GL_TRIANGLE_STRIP);
	for (int x = 0; x <= width; x++) {
		glVertex3d(posD[Param::x] + x, posD[Param::y] + height, posD[Param::z]);
		glVertex3d(posD[Param::x] + x, posD[Param::y], posD[Param::z]);
	}
	glEnd();

	//rear wall
	glBegin(GL_TRIANGLE_STRIP);
	for (int x = 0; x <= width; x++) {
		glVertex3d(posD[Param::x] + x, posD[Param::y], posD[Param::z] - depth);
		glVertex3d(posD[Param::x] + x, posD[Param::y] + height, posD[Param::z] - depth);

	}
	glEnd();

	//top wall
	glBegin(GL_TRIANGLE_STRIP);
	for (int x = 0; x <= width; x++) {
		glVertex3d(posD[Param::x] + x, posD[Param::y] + height, posD[Param::z] - depth);
		glVertex3d(posD[Param::x] + x, posD[Param::y] + height, posD[Param::z]);
	}
	glEnd();

	//bottom wall
	glBegin(GL_TRIANGLE_STRIP);
	for (int x = 0; x <= width; x++) {
		glVertex3d(posD[Param::x] + x, posD[Param::y], posD[Param::z]);
		glVertex3d(posD[Param::x] + x, posD[Param::y], posD[Param::z] - depth);
	}
	glEnd();

	//right wall
	glBegin(GL_TRIANGLE_STRIP);
	for (int y = 0; y <= height; y++) {
		glVertex3d(posD[Param::x] + width, posD[Param::y] + y, posD[Param::z]);
		glVertex3d(posD[Param::x] + width, posD[Param::y] + y, posD[Param::z] - depth);
	}
	glEnd();

	//TODO: Change to sphere
	//left wall
	glBegin(GL_TRIANGLE_STRIP);
	for (int y = 0; y <= height; y++) {
		glVertex3d(posD[Param::x], posD[Param::y] + y, posD[Param::z] - depth);
		glVertex3d(posD[Param::x], posD[Param::y] + y, posD[Param::z]);
	}
	glEnd();
}
