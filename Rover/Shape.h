#pragma once
#include "Entity.h"


enum ShapeType
{
	Line,
	Traingle,
	TriangleStrip,
	TriangleFan
};

class Shape : public Entity
{
	Shape(ShapeType shapeType, Vec3 pos) {};
	ShapeType shapeType;

	virtual void draw() {}

	void create()
	{
		switch (shapeType)
		{
		case: ShapeType::Line

		};
	}
};