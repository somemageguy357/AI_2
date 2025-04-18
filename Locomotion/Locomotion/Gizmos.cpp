#include "Gizmos.h"
#include "Agent.h"
#include "WindowManager.h"
#include "Math.h"

void CGizmos::Update(CAgent* _poOwningAgent, std::vector<CAgent*>* _poVecAgentPtrs)
{
	for (size_t i = 0; i < _poVecAgentPtrs->size(); i++)
	{
		i is counting up when skipping 'this' below. need to fix. 
		if (m_oVecLinePtrs.size() < _poVecAgentPtrs->size())
		{
			CreateLine();
		}

		if ((*_poVecAgentPtrs)[i] != _poOwningAgent)
		{
			RepositionLine(m_oVecLinePtrs[i], _poOwningAgent->GetPosition(), (*_poVecAgentPtrs)[i]->GetPosition());
		}
	}
}

void CGizmos::Render()
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

void CGizmos::CreateLine()
{
	sf::RectangleShape* poLine = new sf::RectangleShape({2.0f, 50.0f});
	poLine->setFillColor(sf::Color::Green);

	poLine->setOrigin
	(
		poLine->getGlobalBounds().left + (poLine->getGlobalBounds().width / 2),
		poLine->getGlobalBounds().top + (poLine->getGlobalBounds().height / 2)
	);

	m_oVecLinePtrs.push_back(poLine);
}

void CGizmos::CreateCircle()
{

}

void CGizmos::RepositionLine(sf::RectangleShape* _poLine, sf::Vector2f _v2fStart, sf::Vector2f _v2fEnd)
{
	//_poLine->setSize({ 1.0f, CMath::Distance(_v2fStart, _v2fEnd) });

	_poLine->setPosition(CMath::CenterPoint(_v2fStart, _v2fEnd));

	float fAdjacent = CMath::Abs(_v2fStart.x - _v2fEnd.x);
	float fYOpposite = CMath::Abs(_v2fStart.y - _v2fEnd.y);

	_poLine->setRotation(atan(fYOpposite / fAdjacent) * (180 / CMath::PI()));
}

void CGizmos::RepositionCircle(sf::Vector2f _v2fPosition, float _fRadius)
{

}