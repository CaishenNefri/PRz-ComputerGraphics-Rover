#pragma once
#include "Shape.h"

class Cuboid : public Shape
{
public:
	Cuboid(ColorF color = BLUE)
	{
		this->Type = Quad
	}
};