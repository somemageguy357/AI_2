#pragma once
#include "SFML/System/Clock.hpp"

class CTimeManager
{
public:
	static void Update();

	static float GetDeltaTime();

private:
	static sf::Clock m_oClock;

	static float m_fDeltaTime;

	CTimeManager() = delete;
	~CTimeManager() = delete;
};