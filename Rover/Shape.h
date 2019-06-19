#pragma once
#include "Entity.h"
#include "ColorF.h"


enum ShapeType
{
	Line,
	Traingle,
	TriangleStrip,
	TriangleFan,
	Quad,
	QuadStrip
};

class Shape : public Entity
{
	Shape() = default;
	Shape(ShapeType shapeType) : Type(shapeType) {}
	Shape(ShapeType shapeType, ColorF color) : Type(shapeType), Color(color) {}
	
	ShapeType Type = Line;
	ColorF Color = BLACK;


	Shape* WithPosition(Vec3 pos) {
		this->Origin = pos;
		return this;
	}

	Shape* WithScale(Vec3 scale) {
		this->Scale = scale;
		return this;
	}

	Shape* WithScale(float scale) {
		this->Scale = Vec3(scale, scale, scale);
		return this;
	}

	Shape* WithRotation(Quat rotation) {
		this->Rotation = rotation;
		return this;
	}

	Shape* WithColor(ColorF color) {
		this->Color = color;
		return this;
	}

	Shape* WithType(ShapeType type) {
		this->Type = type;
		return this;
	}
};