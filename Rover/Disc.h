#pragma once
#include "Shape.h"

class Disc : public Shape
{
public:
	Disc(ColorF color, int steps = 10)
	{
		this->Type = TriangleFan;
		this->Color = color;

		this->AddPoint(Vec3(0, 0, 0), UP, Vec2(0.5, 0.5));

		auto f = 2 * M_PI / steps;
		for (auto i = 0; i <= steps; i++) {
			auto x = cos(i * f);
			auto y = sin(i * f);
			auto p = Vec3(x, y, 0);
			auto t = Vec2(x, y) / 2 + Vec2(0.5, 0.5);
			this->AddPoint(p, UP, t);
		}
	}
};