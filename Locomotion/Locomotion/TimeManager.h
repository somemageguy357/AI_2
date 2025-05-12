/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : TimeManager.h
Description : Static class that contains DeltaTime.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "SFML/System/Clock.hpp"

class CTimeManager
{
public:
	/// <summary>
	/// Updates the value of DeltaTime.
	/// </summary>
	static void Update();

	/// <summary>
	/// Returns the value of DeltaTime.
	/// </summary>
	/// <returns>The value of DeltaTime.</returns>
	static float GetDeltaTime();

private:
	static sf::Clock m_oClock;

	static float m_fDeltaTime;

	CTimeManager() = delete;
	~CTimeManager() = delete;
};