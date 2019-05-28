#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include <Windows.h>
#include <gl\gl.h>              // OpenGL
#include <gl\glu.h>             // GLU library
#include <iostream>

enum Param : unsigned int { x, y, z };
enum Color : unsigned int { r, g, b, a };

class Part
{
public:
	Part(GLdouble x = 0, GLdouble y = 0, GLdouble z = 0, GLdouble angle = 0, Param axis = Param::x);
	Part(GLdouble pos[3], GLdouble angle = 0, Param axis = Param::x);
	~Part();

	virtual void draw();
	virtual void move(GLdouble posM[3]);

	inline void setX(GLdouble x) {
		pos[Param::x] = x;
	}

	GLdouble pos[3];
	GLdouble color[4];
	GLdouble angle;
	Param axis;

protected:

};

inline GLdouble degToRad(GLdouble deg) {
	return deg * M_PI / 180;
}