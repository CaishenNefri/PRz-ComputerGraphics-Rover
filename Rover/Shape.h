#pragma once

#include "Entity.h"
#include "ColorF.h"
#include <vector>

enum ShapeType
{
	Line,
	LineStrip,
	Triangle,
	TrangleStrip,
	TriangleFan,
	Quad,
	QuadStrip
};

class Shape : public Entity
{
public:
	ColorF Color = BLACK;
	ShapeType Type = LineStrip;


	Shape() = default;


	Shape* WithColor(ColorF color) {
		this->Color = color;
		return this;
	}

	Shape* WithType(ShapeType type) {
		this->Type = type;
		return this;
	}
};