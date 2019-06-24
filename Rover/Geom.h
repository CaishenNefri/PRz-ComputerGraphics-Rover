#pragma once
#include "Shape.h"

class Geom : public Entity
{
public:
	std::vector<Shape*> Shapes;  // geom builds of shapes
	std::vector<Geom*> Children; //geom build of geoms

	
	Geom() = default;

	void SetShapesOrigin(const Vec3 newOrigin) {
		for (auto shape : Shapes)
			shape->Origin = newOrigin;
	}
	void AddShapesOrigin(const Vec3 newOrigin) {
		for (auto shape : Shapes)
			shape->Origin += newOrigin;
	}

	void SetShapesRotation(const Quat newRotataion) {
		for (auto shape : Shapes)
			shape->Rotation = newRotataion;
	}
	void AddShapesRotation(const Quat newRotataion) {
		for (auto shape : Shapes)
			shape->Rotation += newRotataion;
	}

	Geom* WithPosition(Vec3 pos) {
		this->Origin = pos;
		return this;
	}

	Geom* WithScale(Vec3 scale) {
		this->Scale = scale;
		return this;
	}

	Geom* WithScale(float scale) {
		this->Scale = Vec3(scale, scale, scale);
		return this;
	}

	Geom* WithRotation(Quat rotation) {
		this->Rotation = rotation;
		return this;
	}
};