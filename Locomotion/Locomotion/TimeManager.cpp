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