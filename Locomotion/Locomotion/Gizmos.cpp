#include "Gizmos.h"
#include "Agent.h"
#include "WindowManager.h"
#include "Math.h"

bool CGizmos::m_bEnabled = false;

CGizmos::~CGizmos()
{
	for (size_t i = 0; i < m_oVecLinePtrs.size(); i++)
	{
		delete m_oVecLinePtrs[i];
	}

	for (size_t i = 0; i < m_oVecCirclePtrs.size(); i++)
	{
		delete m_oVecCirclePtrs[i];
	}
}

void CGizmos::Update(CAgent* _poOwningAgent, std::vector<CAgent*>* _poVecAgentPtrs)
{
	//if (m_bEnabled == true)
	//{
	//	if (m_oVecLinePtrs.size() < _poVecAgentPtrs->size() - 1)
	//	{
	//		for (size_t i = m_oVecLinePtrs.size(); i < _poVecAgentPtrs->size() - 1; i++)
	//		{
	//			CreateLine();
	//		}
	//	}

	//	int iLine = 0;

	//	for (size_t iCycle = 0; iCycle < _poVecAgentPtrs->size(); iCycle++)
	//	{
	//		if ((*_poVecAgentPtrs)[iCycle] != _poOwningAgent)
	//		{
	//			RepositionLine(m_oVecLinePtrs[iLine], _poOwningAgent->GetPosition(), (*_poVecAgentPtrs)[iCycle]->GetPosition());
	//			iLine += 1;
	//		}
	//	}
	//}
}

void CGizmos::Render()
{
	for (size_t i = 0; i < m_oVecRenderedLinePtrs.size(); i++)
	{
		CWindowManager::GetWindow()->draw(*m_oVecRenderedLinePtrs[i]);
	}

	for (size_t i = 0; i < m_oVecRenderedCirclePtrs.size(); i++)
	{
		CWindowManager::GetWindow()->draw(*m_oVecRenderedCirclePtrs[i]);
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
		//Create the needed number of gizmos.
		while (m_oVecLinePtrs.size() < 2)
		{
			CreateLine();
		}

		//Position the gizmos.
		RepositionLine(m_oVecLinePtrs[0], _v2fPosition, _v2fPosition + CMath::Normalize(_v2fVelocity) * 100.0f);
		m_oVecLinePtrs[0]->setFillColor(sf::Color::Green);
		RepositionLine(m_oVecLinePtrs[1], _v2fPosition, _v2fPosition + CMath::Normalize(_v2fSeekDesiredVelocity) * 100.0f);
		m_oVecLinePtrs[1]->setFillColor(sf::Color::Red);

		//Set up the gizmos that are to be rendered.
		m_oVecRenderedLinePtrs.resize(2);
		m_oVecRenderedLinePtrs[0] = m_oVecLinePtrs[0];
		m_oVecRenderedLinePtrs[1] = m_oVecLinePtrs[1];

		//Render the gizmos and clear the vector containing them incase more gizmos are to be rendered.
		Render();
		m_oVecRenderedLinePtrs.clear();
	}
}

void CGizmos::Wander(sf::Vector2f _v2fCirclePosition, sf::Vector2f _v2fEndDirection, float _fRadius)
{
	if (m_bEnabled == true)
	{
		while (m_oVecLinePtrs.size() < 1)
		{
			CreateLine();
		}

		while (m_oVecCirclePtrs.size() < 1)
		{
			CreateCircle();
		}

		//Position the gizmos.
		RepositionCircle(m_oVecCirclePtrs[0], _v2fCirclePosition, _fRadius);
		m_oVecCirclePtrs[0]->setOutlineColor(sf::Color::Green);
		RepositionLine(m_oVecLinePtrs[0], _v2fCirclePosition, _v2fCirclePosition + _v2fEndDirection * _fRadius);
		m_oVecLinePtrs[0]->setFillColor(sf::Color::Red);

		//Set up the gizmos that are to be rendered.
		m_oVecRenderedLinePtrs.resize(1);
		m_oVecRenderedLinePtrs[0] = m_oVecLinePtrs[0];

		m_oVecRenderedCirclePtrs.resize(1);
		m_oVecRenderedCirclePtrs[0] = m_oVecCirclePtrs[0];

		//Render the gizmos and clear the vector containing them incase more gizmos are to be rendered.
		Render();
		m_oVecRenderedLinePtrs.clear();
		m_oVecRenderedCirclePtrs.clear();
	}
}

void CGizmos::CreateLine()
{
	sf::RectangleShape* poLine = new sf::RectangleShape();

	poLine->setOrigin(poLine->getGlobalBounds().left, poLine->getGlobalBounds().height / 2);

	m_oVecLinePtrs.push_back(poLine);
}

void CGizmos::CreateCircle()
{
	sf::CircleShape* poCircle = new sf::CircleShape(1.0f);
	poCircle->setFillColor(sf::Color::Transparent);
	poCircle->setOutlineThickness(-1.0f);
	m_oVecCirclePtrs.push_back(poCircle);
}

void CGizmos::RepositionLine(sf::RectangleShape* _poLine, sf::Vector2f _v2fStart, sf::Vector2f _v2fEnd)
{
	_poLine->setSize({ CMath::Distance(_v2fStart, _v2fEnd), 1.0f });
	_poLine->setPosition(_v2fStart);

	float fX = _v2fEnd.x - _v2fStart.x;
	float fY = _v2fEnd.y - _v2fStart.y;

	_poLine->setRotation(atan2(fY, fX) * CMath::RadToDeg());
}

void CGizmos::RepositionCircle(sf::CircleShape* _poCircle, sf::Vector2f _v2fPosition, float _fRadius)
{
	_poCircle->setRadius(_fRadius);
	_poCircle->setOrigin({ _fRadius, _fRadius });
	_poCircle->setPosition(_v2fPosition);
}