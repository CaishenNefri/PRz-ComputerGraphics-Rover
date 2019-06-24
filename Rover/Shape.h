#pragma once

#include "Entity.h"
#include "ColorF.h"
#include <vector>
#include "Vertex.h"

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
	std::vector<Vertex> Vertices;


	Shape() = default;


	void AddPoint(Vec3 p) { AddPoint(Vertex(p, UP, Vec2(0.5, 0.5))); }
	void AddPoint(Vec3 p, Vec3 n) { AddPoint(Vertex(p, n, Vec2(0.5, 0.5))); }
	void AddPoint(Vertex v) { Vertices.push_back(v); }
	void AddPoint(Vec3 p, Vec2 t) { AddPoint(Vertex(p, Vec3::Zero(), t)); }
	void AddPoint(Vec3 p, Vec3 n, Vec2 t) { AddPoint(Vertex(p, n, t)); }


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