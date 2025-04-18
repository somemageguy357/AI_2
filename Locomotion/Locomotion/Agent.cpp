#include "Agent.h"
#include "WindowManager.h"
#include "AgentManager.h"

CAgent::CAgent() 
{
	m_oTexture.loadFromFile("Textures/WhiteArrow.png");
	m_oShape.setTexture(&m_oTexture);

	m_oShape.setSize({ 20.0f, 20.0f });

	m_oShape.setOrigin
	(
		m_oShape.getGlobalBounds().left + (m_oShape.getGlobalBounds().width / 2),
		m_oShape.getGlobalBounds().top + (m_oShape.getGlobalBounds().height / 2)
	);

	//m_oShape.setPosition(_v2fStartPosition);
	m_oShape.setFillColor(sf::Color::White);
}

CAgent::CAgent(sf::Vector2f _v2fStartPosition)
{
	m_oTexture.loadFromFile("Textures/WhiteArrow.png");
	m_oShape.setTexture(&m_oTexture);

	m_oShape.setSize({ 20.0f, 20.0f });

	m_oShape.setOrigin
	(
		m_oShape.getGlobalBounds().left + (m_oShape.getGlobalBounds().width / 2),
		m_oShape.getGlobalBounds().top + (m_oShape.getGlobalBounds().height / 2)
	);

	m_oShape.setPosition(_v2fStartPosition);
	m_oShape.setFillColor(sf::Color::White);
}

CAgent::~CAgent() {}

void CAgent::Update()
{
	if (m_bEnabled == true)
	{
		//perform behaviour

		m_oGizmos.Update(this, CAgentManager::GetInstance()->GetAgents());
	}
}

void CAgent::Render()
{
	if (m_bEnabled == true)
	{
		CWindowManager::GetWindow()->draw(m_oShape);

		m_oGizmos.Render();
	}
}

void CAgent::SetEnabled(bool _bEnabled)
{
	m_bEnabled = _bEnabled;
}

void CAgent::SetPosition(sf::Vector2f _v2fPosition)
{
	m_oShape.setPosition(_v2fPosition);
}

sf::Vector2f CAgent::GetPosition()
{
	return m_oShape.getPosition();
}
