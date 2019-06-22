#pragma once
#include <Windows.h>

const int keyboardInputStateArraySize = 256;

enum KeyState {
	StillReleased,
	JustPressed,
	StillPressed,
	JustReleased
};

class InputManager
{
private:
	InputManager() = default;
	bool keyboardStateCurrent[keyboardInputStateArraySize];

public:
	static InputManager& GetInstance()
	{
		static InputManager* instance = new InputManager();
		return *instance;
	}

	void Update()
	{
		for (int i = 0; i < keyboardInputStateArraySize; i++)
			keyboardStateCurrent[i] = GetAsyncKeyState(i) < 0;
	}

	inline bool IsDown(const unsigned char key)
	{
		return keyboardStateCurrent[key];
	}
};