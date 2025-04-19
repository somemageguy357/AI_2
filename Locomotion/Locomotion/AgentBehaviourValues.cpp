#include "AgentBehaviourValues.h"
#include "UIManager.h"
#include "UISeekPanel.h"
#include "Math.h"

#pragma region Static Variables
float CAgentBehaviourValues::m_fSeekWeighting = 0.0f;
float CAgentBehaviourValues::m_fSeekStrength = 0.0f;
float CAgentBehaviourValues::m_fSeekMaxSteerForce = 0.0f;

float CAgentBehaviourValues::m_fFleeWeighting = 0.0f;
float CAgentBehaviourValues::m_fFleeStrength = 0.0f;
float CAgentBehaviourValues::m_fFleeMaxSteerForce = 0.0f;

float CAgentBehaviourValues::m_fWanderWeighting = 0.0f;
float CAgentBehaviourValues::m_fWanderStrength = 0.0f;
float CAgentBehaviourValues::m_fWanderMaxSteerForce = 0.0f;
float CAgentBehaviourValues::m_fWanderRadius = 0.0f;
float CAgentBehaviourValues::m_fWanderDistance = 0.0f;
float CAgentBehaviourValues::m_fWanderAdjustmentInterval = 0.0f;
float CAgentBehaviourValues::m_fWanderAngleRandomStrength = 0.0f;
float CAgentBehaviourValues::m_fWanderAngleLerpSpeed = 0.0f;

float CAgentBehaviourValues::m_fSeparationWeighting = 0.0f;
float CAgentBehaviourValues::m_fSeparationStrength = 0.0f;
float CAgentBehaviourValues::m_fSeparationMaxSteerForce = 0.0f;
float CAgentBehaviourValues::m_fSeparationNeighbourhoodRadius = 0.0f;

float CAgentBehaviourValues::m_fCohesionWeighting = 0.0f;
float CAgentBehaviourValues::m_fCohesionStrength = 0.0f;
float CAgentBehaviourValues::m_fCohesionMaxSteerForce = 0.0f;
float CAgentBehaviourValues::m_fCohesionNeighbourhoodRadius = 0.0f;
bool CAgentBehaviourValues::m_bCohesionIncludeSelf = false;

float CAgentBehaviourValues::m_fAlignmentWeighting = 0.0f;
float CAgentBehaviourValues::m_fAlignmentStrength = 0.0f;
float CAgentBehaviourValues::m_fAlignmentMaxSteerForce = 0.0f;
float CAgentBehaviourValues::m_fAlignmentNeighbourhoodRadius = 0.0f;
#pragma endregion

void CAgentBehaviourValues::InitBehaviour(EBehaviour _eBehaviour)
{
	ResetAllValues();

	if (_eBehaviour == EBehaviour::Arrival)
	{
		InitArrivalBehaviour();
	}

	else if (_eBehaviour == EBehaviour::Flock)
	{
		InitFlockBehaviour();
	}

	else if (_eBehaviour == EBehaviour::Seek)
	{
		InitSeekBehaviour();
	}

	else if (_eBehaviour == EBehaviour::Wander)
	{
		InitWanderBehaviour();
	}
}

void CAgentBehaviourValues::ResetAllValues()
{
	m_fSeekWeighting = 0.0f;
	m_fSeekStrength = 0.0f;
	m_fSeekMaxSteerForce = 0.0f;

	m_fFleeWeighting = 0.0f;
	m_fFleeStrength = 0.0f;
	m_fFleeMaxSteerForce = 0.0f;

	m_fWanderWeighting = 0.0f;
	m_fWanderStrength = 0.0f;
	m_fWanderMaxSteerForce = 0.0f;
	m_fWanderRadius = 0.0f;
	m_fWanderDistance = 0.0f;
	m_fWanderAdjustmentInterval = 0.0f;
	m_fWanderAngleRandomStrength = 0.0f;
	m_fWanderAngleLerpSpeed = 0.0f;

	m_fSeparationWeighting = 0.0f;
	m_fSeparationStrength = 0.0f;
	m_fSeparationMaxSteerForce = 0.0f;
	m_fSeparationNeighbourhoodRadius = 0.0f;

	m_fCohesionWeighting = 0.0f;
	m_fCohesionStrength = 0.0f;
	m_fCohesionMaxSteerForce = 0.0f;
	m_fCohesionNeighbourhoodRadius = 0.0f;
	m_bCohesionIncludeSelf = false;

	m_fAlignmentWeighting = 0.0f;
	m_fAlignmentStrength = 0.0f;
	m_fAlignmentMaxSteerForce = 0.0f;
	m_fAlignmentNeighbourhoodRadius = 0.0f;
}

void CAgentBehaviourValues::InitArrivalBehaviour()
{
}

void CAgentBehaviourValues::InitFlockBehaviour()
{
}

void CAgentBehaviourValues::InitSeekBehaviour()
{
	m_fSeekWeighting = 1.0f;
	m_fSeekStrength = 2.0f;
	m_fSeekMaxSteerForce = 2.0f;

	CUISeekPanel* poSeekPanel = CUIManager::GetSeekPanel();
	poSeekPanel->SetEnabled(true);
	poSeekPanel->SetWeightText(m_fSeekWeighting);
	poSeekPanel->SetStrengthText(m_fSeekStrength);
	poSeekPanel->SetMaxSteerForceText(m_fSeekMaxSteerForce);
}

void CAgentBehaviourValues::InitWanderBehaviour()
{
	m_fWanderWeighting = 0.0f;
	m_fWanderStrength = 0.0f;
	m_fWanderMaxSteerForce = 0.0f;
	m_fWanderRadius = 0.0f;
	m_fWanderDistance = 0.0f;
	m_fWanderAdjustmentInterval = 0.0f;
	m_fWanderAngleRandomStrength = 0.0f;
	m_fWanderAngleLerpSpeed = 0.0f;
}

void CAgentBehaviourValues::SetSeekWeighting(float _fWeighting)
{
	m_fSeekWeighting = CMath::Clamp(_fWeighting, 0.0f, 1.0f);

	CUIManager::GetSeekPanel()->SetWeightText(m_fSeekWeighting);
}

float CAgentBehaviourValues::GetSeekWeighting()
{
	return m_fSeekWeighting;
}

void CAgentBehaviourValues::SetSeekStrength(float _fStrength)
{
	m_fSeekStrength = _fStrength;

	CUIManager::GetSeekPanel()->SetStrengthText(m_fSeekStrength);
}

float CAgentBehaviourValues::GetSeekStrength()
{
	return m_fSeekStrength;
}

void CAgentBehaviourValues::SetSeekMaxSteerForce(float _fMaxSteerForce)
{
	m_fSeekMaxSteerForce = _fMaxSteerForce;

	CUIManager::GetSeekPanel()->SetMaxSteerForceText(m_fSeekMaxSteerForce);
}

float CAgentBehaviourValues::GetSeekMaxSteerForce()
{
	return m_fSeekMaxSteerForce;
}

void CAgentBehaviourValues::SetFleeWeighting(float _fWeighting)
{
	m_fFleeWeighting = _fWeighting;
}

float CAgentBehaviourValues::GetFleeWeighting()
{
	return m_fFleeWeighting;
}

void CAgentBehaviourValues::SetFleeStrength(float _fStrength)
{
	m_fFleeStrength = _fStrength;
}

float CAgentBehaviourValues::GetFleeStrength()
{
	return m_fFleeStrength;
}

void CAgentBehaviourValues::SetFleeMaxSteerForce(float _fMaxSteerForce)
{
	m_fFleeMaxSteerForce = _fMaxSteerForce;
}

float CAgentBehaviourValues::GetFleeMaxSteerForce()
{
	return m_fFleeMaxSteerForce;
}

void CAgentBehaviourValues::SetWanderWeighting(float _fWeighting)
{
	m_fWanderWeighting = _fWeighting;
}

float CAgentBehaviourValues::GetWanderWeighting()
{
	return m_fWanderWeighting;
}

void CAgentBehaviourValues::SetWanderStrength(float _fStrength)
{
	m_fWanderStrength = _fStrength;
}

float CAgentBehaviourValues::GetWanderStrength()
{
	return m_fWanderStrength;
}

void CAgentBehaviourValues::SetWanderMaxSteerForce(float _fMaxSteerForce)
{
	m_fWanderMaxSteerForce = _fMaxSteerForce;
}

float CAgentBehaviourValues::GetWanderMaxSteerForce()
{
	return m_fWanderMaxSteerForce;
}

void CAgentBehaviourValues::SetWanderRadius(float _fRadius)
{
	m_fWanderRadius = _fRadius;
}

float CAgentBehaviourValues::GetWanderRadius()
{
	return m_fWanderRadius;
}

void CAgentBehaviourValues::SetWanderDistance(float _fDistance)
{
	m_fWanderDistance = _fDistance;
}

float CAgentBehaviourValues::GetWanderDistance()
{
	return m_fWanderDistance;
}

void CAgentBehaviourValues::SetWanderAdjustmentInterval(float _fAdjustmentInterval)
{
	m_fWanderAdjustmentInterval = _fAdjustmentInterval;
}

float CAgentBehaviourValues::GetWanderAdjustmentInterval()
{
	return m_fWanderAdjustmentInterval;
}

void CAgentBehaviourValues::SetWanderAngleRandomStrength(float _fAngleRandStrength)
{
	m_fWanderAngleRandomStrength = _fAngleRandStrength;
}

float CAgentBehaviourValues::GetWanderAngleRandomStrength()
{
	return m_fWanderAngleRandomStrength;
}

void CAgentBehaviourValues::SetWanderAngleLerpSpeed(float _fAngleLerpSpeed)
{
	m_fWanderAngleLerpSpeed = _fAngleLerpSpeed;
}

float CAgentBehaviourValues::GetWanderAngleLerpSpeed()
{
	return m_fWanderAngleLerpSpeed;
}

void CAgentBehaviourValues::SetSeparationWeighting(float _fWeighting)
{
	m_fSeparationWeighting = _fWeighting;
}

float CAgentBehaviourValues::GetSeparationWeighting()
{
	return m_fSeparationWeighting;
}

void CAgentBehaviourValues::SetSeparationStrength(float _fStrength)
{
	m_fSeparationStrength = _fStrength;
}

float CAgentBehaviourValues::GetSeparationStrength()
{
	return m_fSeparationStrength;
}

void CAgentBehaviourValues::SetSeparationMaxSteerForce(float _fMaxSteerForce)
{
	m_fSeparationMaxSteerForce = _fMaxSteerForce;
}

float CAgentBehaviourValues::GetSeparationMaxSteerForce()
{
	return m_fSeparationMaxSteerForce;
}

void CAgentBehaviourValues::SetSeparationNeighbourhoodRadius(float _fNeighbourhoodRadius)
{
	m_fSeparationNeighbourhoodRadius = _fNeighbourhoodRadius;
}

float CAgentBehaviourValues::GetSeparationNeighbourhoodRadius()
{
	return m_fSeparationNeighbourhoodRadius;
}

void CAgentBehaviourValues::SetCohesionWeighting(float _fWeighting)
{
	m_fCohesionWeighting = _fWeighting;
}

float CAgentBehaviourValues::GetCohesionWeighting()
{
	return m_fCohesionWeighting;
}

void CAgentBehaviourValues::SetCohesionStrength(float _fStrength)
{
	m_fCohesionStrength = _fStrength;
}

float CAgentBehaviourValues::GetCohesionStrength()
{
	return m_fCohesionStrength;
}

void CAgentBehaviourValues::SetCohesionMaxSteerForce(float _fMaxSteerForce)
{
	m_fCohesionMaxSteerForce = _fMaxSteerForce;
}

float CAgentBehaviourValues::GetCohesionMaxSteerForce()
{
	return m_fCohesionMaxSteerForce;
}

void CAgentBehaviourValues::SetCohesionNeighbourhoodRadius(float _fNeighbourhoodRadius)
{
	m_fCohesionNeighbourhoodRadius = _fNeighbourhoodRadius;
}

float CAgentBehaviourValues::GetCohesionNeighbourhoodRadius()
{
	return m_fCohesionNeighbourhoodRadius;
}

void CAgentBehaviourValues::SetCohesionIncludeSelf(bool _bIncludeSelf)
{
	m_bCohesionIncludeSelf = _bIncludeSelf;
}

bool CAgentBehaviourValues::GetCohesionIncludeSelf()
{
	return m_bCohesionIncludeSelf;
}

void CAgentBehaviourValues::SetAlignmentWeighting(float _fWeighting)
{
	m_fAlignmentWeighting = _fWeighting;
}

float CAgentBehaviourValues::GetAlignmentWeighting()
{
	return m_fAlignmentWeighting;
}

void CAgentBehaviourValues::SetAlignmentStrength(float _fStrength)
{
	m_fAlignmentStrength = _fStrength;
}

float CAgentBehaviourValues::GetAlignmentStrength()
{
	return m_fAlignmentStrength;
}

void CAgentBehaviourValues::SetAlignmentMaxSteerForce(float _fMaxSteerForce)
{
	m_fAlignmentMaxSteerForce = _fMaxSteerForce;
}

float CAgentBehaviourValues::GetAlignmentMaxSteerForce()
{
	return m_fAlignmentMaxSteerForce;
}

void CAgentBehaviourValues::SetAlignmentNeighbourhoodRadius(float _fNeighbourhoodRadius)
{
	m_fAlignmentNeighbourhoodRadius = _fNeighbourhoodRadius;
}

float CAgentBehaviourValues::GetAlignmentNeighbourhoodRadius()
{
	return m_fAlignmentNeighbourhoodRadius;
}