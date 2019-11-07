#pragma once
class TimeManager
{
	friend class Framework;
private:
	static float deltaTime;
	static void UpdateTime();
public:
	static float GetDeltaTime();
};

