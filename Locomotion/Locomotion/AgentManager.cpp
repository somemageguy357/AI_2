#include "AgentManager.h"
#include "WindowManager.h"

sf::RectangleShape CAgentManager::m_oBoundary;
std::vector<CAgent*> CAgentManager::m_oVecAgentPtrs;

void CAgentManager::Update()
{
	for (size_t i = 0; i < m_oVecAgentPtrs.size(); i++)
	{
		m_oVecAgentPtrs[i]->Update();
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

void CAgentManager::SpawnAgents(int _iCount)
{
	for (size_t i = m_oVecAgentPtrs.size(); i < _iCount; i++)
	{
		CAgent* poAgent = new CAgent();
		m_oVecAgentPtrs.push_back(poAgent);
	}

	if (m_oVecAgentPtrs.size() > _iCount)
	{
		for (size_t i = _iCount; i < m_oVecAgentPtrs.size(); i++)
		{
			m_oVecAgentPtrs[i]->SetEnabled(false);
		}
	}

	PositionAgents(_iCount);
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
	int iMinX = m_oBoundary.getGlobalBounds().left + 15;
	int iMaxX = m_oBoundary.getGlobalBounds().left + m_oBoundary.getGlobalBounds().width - 15;
	int iMinY = m_oBoundary.getGlobalBounds().top + 15;
	int iMaxY = m_oBoundary.getGlobalBounds().top + m_oBoundary.getGlobalBounds().height - 15;

	for (size_t i = 0; i < _iCount; i++)
	{
		v2fRandPos.x = rand() % (iMaxX - iMinX) + iMinX;
		v2fRandPos.y = rand() % (iMaxY - iMinY) + iMinY;

		m_oVecAgentPtrs[i]->SetPosition(v2fRandPos);
	}
}