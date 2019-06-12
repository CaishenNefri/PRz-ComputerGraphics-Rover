#pragma once
#include "Entity.h"
#include <vector>
#include "Shape.h"

class Geom : public Entity
{


	std::vector<Shape> Shapes;
	std::vector<Geom> Geoms;
};