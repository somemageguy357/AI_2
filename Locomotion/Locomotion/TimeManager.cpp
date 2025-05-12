/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : TimeManager.cpp
Description : Contains function definitions for TimeManager.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "TimeManager.h"

sf::Clock CTimeManager::m_oClock;
float CTimeManager::m_fDeltaTime;

void CTimeManager::Update()
{
	m_fDeltaTime = m_oClock.getElapsedTime().asSeconds();
	m_oClock.restart();
}

float CTimeManager::GetDeltaTime()
{
	return m_fDeltaTime;
}