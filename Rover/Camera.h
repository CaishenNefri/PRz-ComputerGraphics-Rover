#pragma once
#include "Geom.h"
#include "InputManager.h"

/*
	Do rozbudowania
	dodanie 2 trybów
	podazanie za lazikiem
	ruch swobodny

	dodanie operowania za pomoca myszki
*/

class Camera : public Geom
{
public:
	// CAMERA
	Vec3 cameraPos = Vec3(0, 0, 3);
	Vec3 cameraFront = Vec3(0, 0, -1);
	Vec3 cameraUp = Vec3(0, 1, 0);

	InputManager& inputManager = InputManager::GetInstance();

	Camera()
	{
	}

	void updateInputs(float frameTime)
	{
		if (inputManager.IsDown(VK_UP))
			cameraPos += cameraFront;
		if (inputManager.IsDown(VK_DOWN))
			cameraPos -= cameraFront;

		if (inputManager.IsDown(VK_LEFT))
			cameraPos -= Vec3::Normalized(Vec3::Cross(cameraFront, cameraUp));
		if (inputManager.IsDown(VK_RIGHT))
			cameraPos += Vec3::Normalized(Vec3::Cross(cameraFront, cameraUp));

		if (inputManager.IsDown('O'))
			cameraPos.Y += 100 * 2.5 * frameTime;
		if (inputManager.IsDown('L'))
			cameraPos.Y -= 100 * 2.5 * frameTime;
	}


	inline void setLookAt()
	{
		gluLookAt(cameraPos.X, cameraPos.Y, cameraPos.Z,
			cameraPos.X, cameraPos.Y, cameraPos.Z - 1,
			cameraUp.X, cameraUp.Y, cameraUp.Z);
	}
};