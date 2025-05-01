#include "Gizmos.h"
#include "Agent.h"
#include "WindowManager.h"
#include "Math.h"

bool CGizmos::m_bEnabled = false;

void CGizmos::Update(CAgent* _poOwningAgent, std::vector<CAgent*>* _poVecAgentPtrs)
{
	if (m_bEnabled == true)
	{
		if (m_oVecLinePtrs.size() < _poVecAgentPtrs->size() - 1)
		{
			for (size_t i = m_oVecLinePtrs.size(); i < _poVecAgentPtrs->size() - 1; i++)
			{
				CreateLine();
			}
		}

		int iLine = 0;

		for (size_t iCycle = 0; iCycle < _poVecAgentPtrs->size(); iCycle++)
		{
			if ((*_poVecAgentPtrs)[iCycle] != _poOwningAgent)
			{
				RepositionLine(m_oVecLinePtrs[iLine], _poOwningAgent->GetPosition(), (*_poVecAgentPtrs)[iCycle]->GetPosition());
				iLine += 1;
			}
		}
	}
}

void CGizmos::Render()
{
	if (m_bEnabled == true)
	{
		for (size_t i = 0; i < m_oVecLinePtrs.size(); i++)
		{
			CWindowManager::GetWindow()->draw(*m_oVecLinePtrs[i]);
		}

		for (size_t i = 0; i < m_oVecCirclePtrs.size(); i++)
		{
			CWindowManager::GetWindow()->draw(*m_oVecCirclePtrs[i]);
		}
	}
}

void CGizmos::ToggleGizmos()
{
	m_bEnabled = !m_bEnabled;
}

bool CGizmos::GetGizmosEnabled()
{
	return m_bEnabled;
}

void CGizmos::Seek(sf::Vector2f _v2fPosition, sf::Vector2f _v2fVelocity, sf::Vector2f _v2fSeekDesiredVelocity)
{
	if (m_bEnabled == true)
	{
		while (m_oVecLinePtrs.size() < 2)
		{
			CreateLine();
		}

		RepositionLine(m_oVecLinePtrs[0], _v2fPosition, _v2fPosition + CMath::Normalize(_v2fVelocity) * 100.0f);
		RepositionLine(m_oVecLinePtrs[1], _v2fPosition, _v2fPosition + CMath::Normalize(_v2fSeekDesiredVelocity) * 100.0f);
		m_oVecLinePtrs[1]->setFillColor(sf::Color::Red);
	}
}

void CGizmos::CreateLine()
{
	sf::RectangleShape* poLine = new sf::RectangleShape();
	poLine->setFillColor(sf::Color::Green);

	poLine->setOrigin
	(
		poLine->getGlobalBounds().left,
		poLine->getGlobalBounds().height / 2
	);

	m_oVecLinePtrs.push_back(poLine);
}

void CGizmos::CreateCircle()
{

}

void CGizmos::RepositionLine(sf::RectangleShape* _poLine, sf::Vector2f _v2fStart, sf::Vector2f _v2fEnd)
{
	_poLine->setSize({ CMath::Distance(_v2fStart, _v2fEnd), 1.0f });

	_poLine->setPosition(_v2fStart);

	float fX = _v2fEnd.x - _v2fStart.x;
	float fY = _v2fEnd.y - _v2fStart.y;

	_poLine->setRotation(atan2(fY, fX) * (180 / CMath::PI()));
}

void CGizmos::RepositionCircle(sf::Vector2f _v2fPosition, float _fRadius)
{

}