#include "Agent.h"
#include "WindowManager.h"
#include "AgentManager.h"
#include "AgentBehaviourValues.h"
#include "TimeManager.h"
#include "Math.h"
#include "MouseCircle.h"

#include <iostream>

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

		if (CAgentBehaviourValues::GetWanderWeighting() > 0.0f)
		{
			Wander();
		}

		Translate();

		CheckBoundary();
	}
}

void CAgent::LateUpdate()
{
	if (m_bEnabled == true)
	{
		//m_oGizmos.Update(this, CAgentManager::GetAgents());

		if (CAgentBehaviourValues::GetSeekWeighting() > 0.0f)
		{
			m_oGizmos.Seek(m_oShape.getPosition(), m_v2fVelocity, m_v2fSeekDesiredVelocity);
		}

		if (CAgentBehaviourValues::GetWanderWeighting() > 0.0f)
		{
			sf::Vector2f v2fCirclePosition = m_oShape.getPosition() + CMath::Normalize(m_v2fVelocity) * CAgentBehaviourValues::GetWanderDistance();
			float fCalcAngle = m_fWanderAngle + CMath::PI() * 0.5f;
			sf::Vector2f v2fWanderDirection = { cos(fCalcAngle), sin(fCalcAngle) };

			m_oGizmos.Wander(v2fCirclePosition, v2fWanderDirection, CAgentBehaviourValues::GetWanderRadius());
		}
	}
}

void CAgent::Render()
{
	if (m_bEnabled == true)
	{
		CWindowManager::GetWindow()->draw(m_oShape);
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

	m_v2fSeekDesiredVelocity = CMath::Normalize(v2fOffset) * 10.0f;

	//--

	sf::Vector2f v2fSteerForce = m_v2fSeekDesiredVelocity - m_v2fVelocity;

	v2fSteerForce = CMath::ClampMagnitude(v2fSteerForce, CAgentBehaviourValues::GetSeekMaxSteerForce());

	m_v2fVelocity += v2fSteerForce * CAgentBehaviourValues::GetSeekStrength() * CAgentBehaviourValues::GetSeekWeighting() * CTimeManager::GetDeltaTime();
	m_v2fVelocity = CMath::ClampMagnitude(m_v2fVelocity, 10.0f);
}

void CAgent::Wander()
{
	m_fWanderAdjustmentTimer -= CTimeManager::GetDeltaTime();

	if (m_fWanderAdjustmentTimer < 0.0f)
	{
		m_fTargetWanderAngle += CMath::RandomRange(-1.0f, 1.0f) * /*CAgentBehaviourValues::GetWanderAngleRandomStrength()*/ 2.0f;
		m_fWanderAdjustmentTimer = 1.0f; //reset timer.
	}

	m_fWanderAngle = CMath::DegToRad() * CMath::Lerp(CMath::RadToDeg() * m_fWanderAngle, CMath::RadToDeg() * m_fTargetWanderAngle, CTimeManager::GetDeltaTime());

	sf::Vector2f v2fCirclePosition = m_oShape.getPosition() + CMath::Normalize(m_v2fVelocity) * CAgentBehaviourValues::GetWanderDistance();
	
	//--

	float fCalcAngle = m_fWanderAngle + CMath::PI() * 0.5f;
	sf::Vector2f v2fWanderDirection = { cos(fCalcAngle), sin(fCalcAngle) };

	//--

	sf::Vector2f v2fActualTarget = v2fCirclePosition + v2fWanderDirection * CAgentBehaviourValues::GetWanderRadius();
	sf::Vector2f v2fSteerForce = { v2fActualTarget.x - m_oShape.getPosition().x, v2fActualTarget.y - m_oShape.getPosition().y };

	//--

	v2fSteerForce -= m_v2fVelocity;
	v2fSteerForce = CMath::ClampMagnitude(v2fSteerForce, CAgentBehaviourValues::GetWanderMaxSteerForce());

	m_v2fVelocity += v2fSteerForce * CAgentBehaviourValues::GetWanderStrength() * CAgentBehaviourValues::GetWanderWeighting() * CTimeManager::GetDeltaTime();
	m_v2fVelocity = CMath::ClampMagnitude(m_v2fVelocity, 100.0f);
}

void CAgent::Translate()
{
	//std::cout << "velocity: " << m_v2fVelocity.x << ", " << m_v2fVelocity.y << std::endl;
	//Update position.
	m_oShape.setPosition(m_oShape.getPosition() + (m_v2fVelocity * m_fSpeed * CTimeManager::GetDeltaTime()));

	//Update rotation.
	if (m_v2fVelocity.x != 0.0f || m_v2fVelocity.y != 0.0f)
	{
		m_oShape.setRotation(atan2(m_v2fVelocity.y, m_v2fVelocity.x) * (CMath::RadToDeg()) + 90.0f);
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