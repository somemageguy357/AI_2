/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : AgentManager.cpp
Description : Contains function definitions for AgentManager.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "AgentManager.h"
#include "WindowManager.h"
#include "AgentBehaviourValues.h"

#include <iostream>

unsigned int CAgentManager::m_uiActiveAgents = 0;

sf::RectangleShape CAgentManager::m_oBoundary;
std::vector<CAgent*> CAgentManager::m_oVecAgentPtrs;

void CAgentManager::Update(bool _bIsClicking)
{
	//Allows a new agent to be created within the boundary at the current mouse position. Only possible if the Wander behaviour has been selected.
	if (_bIsClicking == true && CAgentBehaviourValues::GetSelectedBehaviour() == CAgentBehaviourValues::EBehaviour::Wander)
	{
		sf::Vector2i v2iMousePosition = sf::Mouse::getPosition(*CWindowManager::GetWindow());

		if (v2iMousePosition.x >= m_oBoundary.getGlobalBounds().left &&
			v2iMousePosition.x <= m_oBoundary.getGlobalBounds().left + m_oBoundary.getGlobalBounds().width &&
			v2iMousePosition.y >= m_oBoundary.getGlobalBounds().top &&
			v2iMousePosition.y <= m_oBoundary.getGlobalBounds().top + m_oBoundary.getGlobalBounds().height)
		{
			SpawnSingleAgent({ (float)v2iMousePosition.x, (float)v2iMousePosition.y });
		}
	}

	//Updates all agents.
	for (size_t i = 0; i < m_oVecAgentPtrs.size(); i++)
	{
		m_oVecAgentPtrs[i]->Update();
	}
}

void CAgentManager::LateUpdate()
{
	for (size_t i = 0; i < m_oVecAgentPtrs.size(); i++)
	{
		m_oVecAgentPtrs[i]->LateUpdate();
	}
}

void CAgentManager::Render()
{
	for (size_t i = 0; i < m_oVecAgentPtrs.size(); i++)
	{
		m_oVecAgentPtrs[i]->Render();
	}

	CWindowManager::GetWindow()->draw(m_oBoundary);
}

void CAgentManager::InitAgentManager()
{
	m_oBoundary.setFillColor(sf::Color::Transparent);
	m_oBoundary.setOutlineColor(sf::Color::Red);
	m_oBoundary.setOutlineThickness(-1.0f);

	sf::Vector2f v2fWindowSize = { (float)CWindowManager::GetWindow()->getSize().x, (float)CWindowManager::GetWindow()->getSize().y };
	m_oBoundary.setSize({ v2fWindowSize.x - 130.0f, v2fWindowSize.y - 220 });
	m_oBoundary.setPosition({ 120.0f, 10.0f });
}

void CAgentManager::SpawnAgents(unsigned int _uiCount)
{
	m_uiActiveAgents = _uiCount;

	for (size_t i = m_oVecAgentPtrs.size(); i < _uiCount; i++)
	{
		CAgent* poAgent = new CAgent();
		m_oVecAgentPtrs.push_back(poAgent);
		std::cout << "New agent created.\n";
	}

	if (m_oVecAgentPtrs.size() > _uiCount)
	{
		for (size_t i = _uiCount; i < m_oVecAgentPtrs.size(); i++)
		{
			m_oVecAgentPtrs[i]->SetEnabled(false);
		}
	}

	else
	{
		for (size_t i = 0; i < m_oVecAgentPtrs.size(); i++)
		{
			m_oVecAgentPtrs[i]->SetEnabled(true);
		}
	}

	PositionAgents(_uiCount);
}

void CAgentManager::SpawnSingleAgent(sf::Vector2f _v2fPosition)
{
	m_uiActiveAgents += 1;

	if (m_oVecAgentPtrs.size() < m_uiActiveAgents)
	{
		for (size_t i = m_oVecAgentPtrs.size(); i < m_uiActiveAgents; i++)
		{
			CAgent* poAgent = new CAgent(_v2fPosition);
			m_oVecAgentPtrs.push_back(poAgent);
			std::cout << "New single agent created.\n";
		}
	}

	else
	{
		m_oVecAgentPtrs[m_uiActiveAgents - 1]->SetPosition(_v2fPosition);
		m_oVecAgentPtrs[m_uiActiveAgents - 1]->SetEnabled(true);
		std::cout << "Existing agent repositioned and enabled.\n";
	}
}

std::vector<CAgent*>* CAgentManager::GetAgents()
{
	return &m_oVecAgentPtrs;
}

sf::RectangleShape* CAgentManager::GetBoundary()
{
	return &m_oBoundary;
}

void CAgentManager::Destroy()
{
	for (size_t i = 0; i < m_oVecAgentPtrs.size(); i++)
	{
		delete m_oVecAgentPtrs[i];
	}
}

void CAgentManager::PositionAgents(int _iCount)
{
	sf::Vector2f v2fRandPos;
	int iMinX = (int)(m_oBoundary.getGlobalBounds().left + 15);
	int iMaxX = (int)(m_oBoundary.getGlobalBounds().left + m_oBoundary.getGlobalBounds().width - 15);
	int iMinY = (int)(m_oBoundary.getGlobalBounds().top + 15);
	int iMaxY = (int)(m_oBoundary.getGlobalBounds().top + m_oBoundary.getGlobalBounds().height - 15);

	for (int i = 0; i < _iCount; i++)
	{
		v2fRandPos.x = (float)(rand() % (iMaxX - iMinX) + iMinX);
		v2fRandPos.y = (float)(rand() % (iMaxY - iMinY) + iMinY);

		m_oVecAgentPtrs[i]->SetPosition(v2fRandPos);
		m_oVecAgentPtrs[i]->ResetVelocity();
	}
}