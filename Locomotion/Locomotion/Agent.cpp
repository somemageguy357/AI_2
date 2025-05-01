#include "Agent.h"
#include "WindowManager.h"
#include "AgentManager.h"
#include "AgentBehaviourValues.h"
#include "TimeManager.h"
#include "Math.h"
#include "MouseCircle.h"

CAgent::CAgent() 
{
	m_oTexture.loadFromFile("Textures/WhiteArrow.png");
	m_oShape.setTexture(&m_oTexture);

	m_oShape.setSize({ 20.0f, 20.0f });

	m_oShape.setOrigin
	(
		m_oShape.getGlobalBounds().width / 2,
		m_oShape.getGlobalBounds().height / 2
	);

	m_oShape.setFillColor(sf::Color::White);
}

CAgent::CAgent(sf::Vector2f _v2fStartPosition)
{
	m_oTexture.loadFromFile("Textures/WhiteArrow.png");
	m_oShape.setTexture(&m_oTexture);

	m_oShape.setSize({ 20.0f, 20.0f });

	m_oShape.setOrigin
	(
		m_oShape.getGlobalBounds().width / 2,
		m_oShape.getGlobalBounds().height / 2
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

		if (CAgentBehaviourValues::GetSeekWeighting() > 0.0f)
		{
			Seek();
		}

		Translate();

		CheckBoundary();

		if (CAgentBehaviourValues::GetSeekWeighting() > 0.0f)
		{
			//m_oGizmos.Update(this, CAgentManager::GetAgents());
			m_oGizmos.Seek(m_oShape.getPosition(), m_v2fMoveDir, m_v2fSeekDesiredVelocity);
		}
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

void CAgent::Seek()
{
	sf::Vector2f v2fTargetPosition = CMouseCircle::GetInstance()->GetPosition();

	sf::Vector2f v2fOffset = { v2fTargetPosition.x - m_oShape.getPosition().x, v2fTargetPosition.y - m_oShape.getPosition().y };

	m_v2fSeekDesiredVelocity = CMath::Normalize(v2fOffset) * 1.0f;

	//--

	sf::Vector2f v2fSteerForce = m_v2fSeekDesiredVelocity - m_v2fMoveDir;

	v2fSteerForce = CMath::ClampMagnitude(v2fSteerForce, CAgentBehaviourValues::GetSeekMaxSteerForce());

	m_v2fMoveDir += v2fSteerForce * CAgentBehaviourValues::GetSeekStrength() * CAgentBehaviourValues::GetSeekWeighting() * CTimeManager::GetDeltaTime();
	m_v2fMoveDir = CMath::ClampMagnitude(m_v2fMoveDir, 1.0f);
}

void CAgent::Translate()
{
	//sf::Vector2f v2fPosition = m_oShape.getPosition();

	//CMath::Normalize(&m_v2fMoveDir);

	//Update position.
	m_oShape.setPosition(m_oShape.getPosition() + (m_v2fMoveDir * m_fSpeed * CTimeManager::GetDeltaTime()));

	//Update rotation.
	if (m_v2fMoveDir.x != 0.0f || m_v2fMoveDir.y != 0.0f)
	{
		m_oShape.setRotation(atan2(m_v2fMoveDir.y, m_v2fMoveDir.x) * (180.0f / CMath::PI()) + 90.0f);
	}
}

void CAgent::CheckBoundary()
{
	sf::Vector2f v2fPosition = m_oShape.getPosition();
	sf::FloatRect oBoundary = CAgentManager::GetBoundary()->getGlobalBounds();

	//Right
	if (v2fPosition.x > oBoundary.left + oBoundary.width)
	{
		m_oShape.setPosition({ oBoundary.left, v2fPosition.y });
	}

	//Left
	if (v2fPosition.x < oBoundary.left)
	{
		m_oShape.setPosition({ oBoundary.left + oBoundary.width, v2fPosition.y });
	}

	//Bottom
	if (v2fPosition.y > oBoundary.top + oBoundary.height)
	{
		m_oShape.setPosition({ v2fPosition.x, oBoundary.top });
	}

	//Top
	if (v2fPosition.y < oBoundary.top)
	{
		m_oShape.setPosition({ v2fPosition.x, oBoundary.top + oBoundary.height });
	}
}