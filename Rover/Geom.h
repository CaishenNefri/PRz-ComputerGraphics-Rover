#pragma once
#include "Shape.h"

class Geom : public Entity
{
public:
	std::vector<Shape*> Shapes;  // geom builds of shapes
	std::vector<Geom*> Children; //geom build of geoms

	
	Geom() = default;

};