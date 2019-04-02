#include "Part.h"

Part::Part(GLdouble x, GLdouble y, GLdouble z, GLdouble angle, Param axis)
{
	this->pos[Param::x] = x;
	this->pos[Param::y] = y;
	this->pos[Param::z] = z;
	this->angle = angle;
	this->axis = axis;
}

Part::Part(GLdouble pos[3], GLdouble angle, Param axis)
{
	this->pos[Param::x] = pos[Param::x];
	this->pos[Param::y] = pos[Param::y];
	this->pos[Param::z] = pos[Param::z];
	this->angle = angle;
	this->axis = axis;
}

Part::~Part()
{
}

void Part::draw()
{
}

void Part::move(GLdouble posM[3])
{
	this->pos[Param::x] = posM[Param::x];
	this->pos[Param::y] = posM[Param::y];
	this->pos[Param::z] = posM[Param::z];
}
