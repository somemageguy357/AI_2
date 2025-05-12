/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : MouseCircle.cpp
Description : Contains function definitions for MouseCircle.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "MouseCircle.h"
#include "WindowManager.h"
#include "AgentManager.h"

CMouseCircle* CMouseCircle::m_poInstance = nullptr;

CMouseCircle::CMouseCircle(float _fRadius)
{
	m_oCircle = sf::CircleShape(_fRadius);
	m_oCircle.setOrigin({ _fRadius, _fRadius });

	//Sets the circle position to the middle of the screen.
	sf::FloatRect oBoundary = CAgentManager::GetBoundary()->getGlobalBounds();
	m_oCircle.setPosition({ oBoundary.left + (oBoundary.width / 2), oBoundary.top + (oBoundary.height / 2) });
}

CMouseCircle::~CMouseCircle() {}

void CMouseCircle::Update()
{
	if (m_bEnabled == true)
	{
		//Updates the position of the circle to the mouse position if it is within the boundary.
		sf::Vector2i v2iMousePosition = sf::Mouse::getPosition(*CWindowManager::GetWindow());
		sf::FloatRect oBoundary = CAgentManager::GetBoundary()->getGlobalBounds();

		if (v2iMousePosition.x <= oBoundary.left + oBoundary.width &&
			v2iMousePosition.x >= oBoundary.left &&
			v2iMousePosition.y <= oBoundary.top + oBoundary.height &&
			v2iMousePosition.y >= oBoundary.top)
		{
			m_oCircle.setPosition({ (float)v2iMousePosition.x, (float)(v2iMousePosition.y) });
		}
	}
}

void CMouseCircle::Render()
{
	if (m_bEnabled == true)
	{
		CWindowManager::GetWindow()->draw(m_oCircle);
	}
}

sf::Vector2f CMouseCircle::GetPosition()
{
	return m_oCircle.getPosition();
}

void CMouseCircle::SetEnabled(bool _bEnabled)
{
	m_bEnabled = _bEnabled;
}