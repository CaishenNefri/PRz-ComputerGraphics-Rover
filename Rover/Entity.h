#pragma once
#include <corecrt_math_defines.h>
#include "Quat.h"

class Entity
{
public:
	virtual ~Entity() = default;
	Vec3 Origin = Vec3::Zero();
	Quat Rotation = Quat::Identity();
	Vec3 Scale = Vec3::One();

	virtual void Init() {}
	virtual void PreRender() {}
	virtual void PostRender() {}

	virtual void Update(float frametime) {}

	template <class T>
	T* WithPosition(Vec3 pos) {
		this->Origin = pos;
		return this;
	}

	template <class T>
	T* WithScale(Vec3 scale) {
		this->Scale = scale;
		return this;
	}

	template <class T>
	T* WithScale(float scale) {
		this->Scale = Vec3(scale,scale, scale);
		return this;
	}

	template <class T>
	T* WithRotation(Quat rotation) {
		this->Rotation = rotation;
		return this;
	}
};

inline float Deg2Rad(const float deg) { return deg * M_PI / 180; }
inline float Rad2Deg(const float rad) { return rad * 180 / M_PI; }
inline float D2R(const float deg) { return Deg2Rad(deg); }
inline float R2D(const float rad) { return Rad2Deg(rad); }
