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

		if (CAgentBehaviourValues::GetArrivalWeighting() > 0.01f)
		{
			Arrival();
		}

		if (CAgentBehaviourValues::GetSeekWeighting() > 0.01f)
		{
			Seek(CMouseCircle::GetInstance()->GetPosition());
		}

		if (CAgentBehaviourValues::GetWanderWeighting() > 0.01f)
		{
			Wander();
		}

		if (CAgentBehaviourValues::GetSeparationWeighting() > 0.01f)
		{
			Separation();
		}

		if (CAgentBehaviourValues::GetCohesionWeighting() > 0.01f)
		{
			Cohesion();
		}

		if (CAgentBehaviourValues::GetAlignmentWeighting() > 0.01f)
		{
			Alignment();
		}

		Translate();

		CheckBoundary();
	}
}

void CAgent::LateUpdate()
{
	if (m_bEnabled == true)
	{
		if (CAgentBehaviourValues::GetArrivalWeighting() > 0.0f)
		{
			m_oGizmos.Arrival(m_oShape.getPosition(), m_v2fVelocity, m_v2fArrivalDesiredVelocity, CMouseCircle::GetInstance()->GetPosition(), CAgentBehaviourValues::GetArrivalStoppingRadius());
		}

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

void CAgent::ResetVelocity()
{
	m_v2fVelocity = { 0.0f, 0.0f };
}

void CAgent::SetPursuitTarget(bool _bIsTarget)
{
	m_bPursuitTarget = _bIsTarget;

	if (m_bPursuitTarget == true)
	{
		m_oShape.setFillColor(sf::Color::Cyan);
	}

	else
	{
		m_oShape.setFillColor(sf::Color::White);
	}
}

void CAgent::Arrival()
{
	sf::Vector2f v2fTargetPosition = CMouseCircle::GetInstance()->GetPosition();

	m_v2fArrivalDesiredVelocity = v2fTargetPosition - m_oShape.getPosition();

	float fDistance = CMath::GetMagnitude(m_v2fArrivalDesiredVelocity);
	float fStoppingRadius = CAgentBehaviourValues::GetArrivalStoppingRadius();

	if (fDistance < fStoppingRadius)
	{
		m_v2fArrivalDesiredVelocity = CMath::Normalize(m_v2fArrivalDesiredVelocity) * m_fMaxSpeed * (fDistance / fStoppingRadius);
	}

	else
	{
		m_v2fArrivalDesiredVelocity = CMath::Normalize(m_v2fArrivalDesiredVelocity) * m_fMaxSpeed;
	}

	sf::Vector2f v2fSteerForce = m_v2fArrivalDesiredVelocity - m_v2fVelocity;

	v2fSteerForce = CMath::ClampMagnitude(v2fSteerForce, CAgentBehaviourValues::GetArrivalMaxSteerForce());

	m_v2fVelocity += v2fSteerForce * CAgentBehaviourValues::GetArrivalStrength() * CAgentBehaviourValues::GetArrivalWeighting() * CTimeManager::GetDeltaTime();
	m_v2fVelocity = CMath::ClampMagnitude(m_v2fVelocity, m_fMaxSpeed);
}

void CAgent::Seek(sf::Vector2f _v2fTargetPosition)
{
	sf::Vector2f v2fOffset = _v2fTargetPosition - m_oShape.getPosition();

	m_v2fSeekDesiredVelocity = CMath::Normalize(v2fOffset) * m_fMaxSpeed;

	//--

	sf::Vector2f v2fSteerForce = m_v2fSeekDesiredVelocity - m_v2fVelocity;

	v2fSteerForce = CMath::ClampMagnitude(v2fSteerForce, CAgentBehaviourValues::GetSeekMaxSteerForce());

	m_v2fVelocity += v2fSteerForce * CAgentBehaviourValues::GetSeekStrength() * CAgentBehaviourValues::GetSeekWeighting() * CTimeManager::GetDeltaTime();
	m_v2fVelocity = CMath::ClampMagnitude(m_v2fVelocity, m_fMaxSpeed);
}

void CAgent::Pursuit()
{
	sf::Vector2f v2fEstimatedPos = { 0.0f, 0.0f };
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
	sf::Vector2f v2fSteerForce = v2fActualTarget - m_oShape.getPosition();

	//--

	v2fSteerForce -= m_v2fVelocity;
	v2fSteerForce = CMath::ClampMagnitude(v2fSteerForce, CAgentBehaviourValues::GetWanderMaxSteerForce());

	m_v2fVelocity += v2fSteerForce * CAgentBehaviourValues::GetWanderStrength() * CAgentBehaviourValues::GetWanderWeighting() * CTimeManager::GetDeltaTime();
	m_v2fVelocity = CMath::ClampMagnitude(m_v2fVelocity, m_fMaxSpeed * 10.0f);
}

void CAgent::Separation()
{
	sf::Vector2f v2fSelfPos = m_oShape.getPosition();
	sf::Vector2f v2fDifAve = { 0.0f, 0.0f };
	int iCount = 0;

	std::vector<CAgent*>* poVecAgentPtrs = CAgentManager::GetAgents();

	for (size_t i = 0; i < poVecAgentPtrs->size(); i++)
	{
		if ((*poVecAgentPtrs)[i] == this)
		{
			continue;
		}

		sf::Vector2f v2fOtherPos = (*poVecAgentPtrs)[i]->GetPosition();
		sf::Vector2f v2fPosDif = v2fSelfPos - v2fOtherPos;

		float fDistance = CMath::GetMagnitude(v2fPosDif);

		if (fDistance < CAgentBehaviourValues::GetSeparationNeighbourhoodRadius())
		{
			sf::Vector2f v2fNormDif = CMath::Normalize(v2fPosDif);
			v2fNormDif /= fDistance * 2.0f;
			v2fDifAve += v2fNormDif;
			iCount += 1;
		}
	}

	if (iCount > 0)
	{
		v2fDifAve /= (float)iCount;
		v2fDifAve = CMath::Normalize(v2fDifAve) * m_fMaxSpeed;
	}

	//--

	sf::Vector2f v2fSteerForce = v2fDifAve - m_v2fVelocity;
	v2fSteerForce = CMath::ClampMagnitude(v2fSteerForce, CAgentBehaviourValues::GetSeparationMaxSteerForce());

	m_v2fVelocity += v2fSteerForce * CAgentBehaviourValues::GetSeparationStrength() * CAgentBehaviourValues::GetSeparationWeighting() * CTimeManager::GetDeltaTime();
	m_v2fVelocity = CMath::ClampMagnitude(m_v2fVelocity, m_fMaxSpeed);
}

void CAgent::Cohesion()
{
	sf::Vector2f v2fSelfPos = m_oShape.getPosition();
	sf::Vector2f v2fPosAve = { 0.0f, 0.0f };
	int iCount = 0;

	std::vector<CAgent*>* poVecAgentPtrs = CAgentManager::GetAgents();

	for (size_t i = 0; i < poVecAgentPtrs->size(); i++)
	{
		if ((*poVecAgentPtrs)[i] == this && CAgentBehaviourValues::GetCohesionIncludeSelf() == false)
		{
			continue;
		}

		sf::Vector2f v2fOtherPos = (*poVecAgentPtrs)[i]->GetPosition();

		float fDistance = CMath::GetMagnitude(v2fOtherPos - v2fSelfPos);

		if (fDistance < CAgentBehaviourValues::GetCohesionNeighbourhoodRadius())
		{
			v2fPosAve += v2fOtherPos;
			iCount += 1;
		}
	}

	if (iCount > 0)
	{
		m_v2fCohesionCenterOfMass = v2fPosAve /= (float)iCount;
		sf::Vector2f v2fDesiredVelocity = CMath::Normalize(m_v2fCohesionCenterOfMass - v2fSelfPos) * m_fMaxSpeed;

		//--

		sf::Vector2f v2fSteerForce = v2fDesiredVelocity - m_v2fVelocity;
		v2fSteerForce = CMath::ClampMagnitude(v2fSteerForce, CAgentBehaviourValues::GetCohesionMaxSteerForce());

		m_v2fVelocity += v2fSteerForce * CAgentBehaviourValues::GetCohesionStrength() * CAgentBehaviourValues::GetCohesionWeighting() * CTimeManager::GetDeltaTime();
		m_v2fVelocity = CMath::ClampMagnitude(m_v2fVelocity, m_fMaxSpeed);
	}

	else
	{
		m_v2fCohesionCenterOfMass = m_oShape.getPosition();
	}
}

void CAgent::Alignment()
{
	sf::Vector2f v2fSelfPos = m_oShape.getPosition();
	sf::Vector2f v2fVelocityAve = { 0.0f, 0.0f };
	int iCount = 0;

	std::vector<CAgent*>* poVecAgentPtrs = CAgentManager::GetAgents();

	for (size_t i = 0; i < poVecAgentPtrs->size(); i++)
	{
		if ((*poVecAgentPtrs)[i] == this)
		{
			continue;
		}

		sf::Vector2f v2fOtherVelocity = (*poVecAgentPtrs)[i]->m_v2fVelocity;
		sf::Vector2f v2fOtherPos = (*poVecAgentPtrs)[i]->GetPosition();

		float fDistance = CMath::GetMagnitude(v2fOtherPos - v2fSelfPos);

		if (fDistance < CAgentBehaviourValues::GetAlignmentNeighbourhoodRadius())
		{
			v2fVelocityAve += v2fOtherVelocity;
			iCount += 1;
		}
	}

	if (iCount > 0)
	{
		v2fVelocityAve /= (float)iCount;
		v2fVelocityAve = CMath::Normalize(v2fVelocityAve) * m_fMaxSpeed;

		//--

		sf::Vector2f v2fSteerForce = v2fVelocityAve - m_v2fVelocity;
		v2fSteerForce = CMath::ClampMagnitude(v2fSteerForce, CAgentBehaviourValues::GetAlignmentMaxSteerForce());

		m_v2fVelocity += v2fSteerForce * CAgentBehaviourValues::GetAlignmentStrength() * CAgentBehaviourValues::GetAlignmentWeighting() * CTimeManager::GetDeltaTime();
		m_v2fVelocity = CMath::ClampMagnitude(m_v2fVelocity, m_fMaxSpeed);
	}
}

void CAgent::Translate()
{
	//std::cout << "velocity: " << m_v2fVelocity.x << ", " << m_v2fVelocity.y << std::endl;
	//Update position.
	m_oShape.setPosition(m_oShape.getPosition() + (m_v2fVelocity * CAgentBehaviourValues::GetAgentSpeedMultiplier() * CTimeManager::GetDeltaTime()));

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