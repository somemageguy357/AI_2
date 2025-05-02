#include "AgentBehaviourValues.h"
#include "AgentManager.h"
#include "UIManager.h"
#include "Math.h"
#include "MouseCircle.h"

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

//---------------------------------------------------------------------------------------------BEHAVIOURS
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

	CUIManager::PositionPanels();
}

void CAgentBehaviourValues::ResetAllValues()
{
	CUIManager::CloseAllPanels();
	CMouseCircle::GetInstance()->SetEnabled(false);

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
	//----------------------------------------------------------WANDER
	//m_fSeekWeighting = 1.0f;
	//m_fSeekStrength = 2.0f;
	//m_fSeekMaxSteerForce = 2.0f;

	//CUISeekPanel* poWanderPanel = CUIManager::GetSeekPanel();
	//poWanderPanel->SetEnabled(true);
	//poWanderPanel->SetWeightText(m_fSeekWeighting);
	//poWanderPanel->SetStrengthText(m_fSeekStrength);
	//poWanderPanel->SetMaxSteerForceText(m_fSeekMaxSteerForce);

	//----------------------------------------------------------SEPARATION
	m_fSeparationWeighting = 1.0f;
	m_fSeparationStrength = 2.0f;
	m_fSeparationMaxSteerForce = 2.0f;
	m_fSeparationNeighbourhoodRadius = 2.0f;

	CUISeparationPanel* poSeparationPanel = CUIManager::GetSeparationPanel();
	poSeparationPanel->SetEnabled(true);
	poSeparationPanel->SetWeightText(m_fSeparationWeighting);
	poSeparationPanel->SetStrengthText(m_fSeparationStrength);
	poSeparationPanel->SetMaxSteerForceText(m_fSeparationMaxSteerForce);
	poSeparationPanel->SetNeighbourhoodRadiusText(m_fSeparationMaxSteerForce);

	//----------------------------------------------------------COHESION
	m_fCohesionWeighting = 0.5f;
	m_fCohesionStrength = 2.0f;
	m_fCohesionMaxSteerForce = 2.0f;
	m_fCohesionNeighbourhoodRadius = 2.0f;
	m_bCohesionIncludeSelf = false;

	CUICohesionPanel* poCohesionPanel = CUIManager::GetCohesionPanel();
	poCohesionPanel->SetEnabled(true);
	poCohesionPanel->SetWeightText(m_fCohesionWeighting);
	poCohesionPanel->SetStrengthText(m_fCohesionStrength);
	poCohesionPanel->SetMaxSteerForceText(m_fCohesionMaxSteerForce);
	poCohesionPanel->SetNeighbourhoodRadiusText(m_fCohesionMaxSteerForce);
	poCohesionPanel->SetIncludeSelfText(m_bCohesionIncludeSelf);

	//----------------------------------------------------------ALIGNMENT
	m_fAlignmentWeighting = 0.2f;
	m_fAlignmentStrength = 2.0f;
	m_fAlignmentMaxSteerForce = 2.0f;
	m_fAlignmentNeighbourhoodRadius = 2.0f;

	CUIAlignmentPanel* poAlignmentPanel = CUIManager::GetAlignmentPanel();
	poAlignmentPanel->SetEnabled(true);
	poAlignmentPanel->SetWeightText(m_fAlignmentWeighting);
	poAlignmentPanel->SetStrengthText(m_fAlignmentStrength);
	poAlignmentPanel->SetMaxSteerForceText(m_fAlignmentMaxSteerForce);
	poAlignmentPanel->SetNeighbourhoodRadiusText(m_fAlignmentMaxSteerForce);

	CAgentManager::SpawnAgents(50);
}

void CAgentBehaviourValues::InitSeekBehaviour()
{
	m_fSeekWeighting = 1.0f;
	m_fSeekStrength = 8.0f;
	m_fSeekMaxSteerForce = 1.0f;

	CUISeekPanel* poSeekPanel = CUIManager::GetSeekPanel();
	poSeekPanel->SetEnabled(true);
	poSeekPanel->SetWeightText(m_fSeekWeighting);
	poSeekPanel->SetStrengthText(m_fSeekStrength);
	poSeekPanel->SetMaxSteerForceText(m_fSeekMaxSteerForce);

	CMouseCircle::GetInstance()->SetEnabled(true);

	CAgentManager::SpawnAgents(1);
}

void CAgentBehaviourValues::InitWanderBehaviour()
{
	m_fWanderWeighting = 1.0f;
	m_fWanderStrength = 5.0f;
	m_fWanderMaxSteerForce = 10.0f;
	m_fWanderRadius = 50.0f;
	m_fWanderDistance = m_fWanderRadius + 10.0f;
	//m_fWanderAdjustmentInterval = 0.0f;
	//m_fWanderAngleRandomStrength = 0.0f;
	//m_fWanderAngleLerpSpeed = 0.0f;

	CUIWanderPanel* poWanderPanel = CUIManager::GetWanderPanel();
	poWanderPanel->SetEnabled(true);
	poWanderPanel->SetWeightText(m_fWanderWeighting);
	poWanderPanel->SetStrengthText(m_fWanderStrength);
	poWanderPanel->SetMaxSteerForceText(m_fWanderMaxSteerForce);
	poWanderPanel->SetRadiusText(m_fWanderRadius);
	poWanderPanel->SetDistanceText(m_fWanderDistance);

	CAgentManager::SpawnAgents(10);
}

//---------------------------------------------------------------------------------------------BEHAVIOUR VALUES

//---------------------------------------------------------------------------------------------SEEK
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
	m_fSeekStrength = CMath::ClampMin(_fStrength, 0.0f);

	CUIManager::GetSeekPanel()->SetStrengthText(m_fSeekStrength);
}

float CAgentBehaviourValues::GetSeekStrength()
{
	return m_fSeekStrength;
}

void CAgentBehaviourValues::SetSeekMaxSteerForce(float _fMaxSteerForce)
{
	m_fSeekMaxSteerForce = CMath::ClampMin(_fMaxSteerForce, 0.0f);

	CUIManager::GetSeekPanel()->SetMaxSteerForceText(m_fSeekMaxSteerForce);
}

float CAgentBehaviourValues::GetSeekMaxSteerForce()
{
	return m_fSeekMaxSteerForce;
}

//---------------------------------------------------------------------------------------------FLEE
void CAgentBehaviourValues::SetFleeWeighting(float _fWeighting)
{
	m_fFleeWeighting = CMath::Clamp(_fWeighting, 0.0f, 1.0f);
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

//---------------------------------------------------------------------------------------------WANDER
void CAgentBehaviourValues::SetWanderWeighting(float _fWeighting)
{
	m_fWanderWeighting = CMath::Clamp(_fWeighting, 0.0f, 1.0f);

	CUIManager::GetWanderPanel()->SetWeightText(m_fWanderWeighting);
}

float CAgentBehaviourValues::GetWanderWeighting()
{
	return m_fWanderWeighting;
}

void CAgentBehaviourValues::SetWanderStrength(float _fStrength)
{
	m_fWanderStrength = CMath::ClampMin(_fStrength, 0.0f);

	CUIManager::GetWanderPanel()->SetStrengthText(m_fWanderStrength);
}

float CAgentBehaviourValues::GetWanderStrength()
{
	return m_fWanderStrength;
}

void CAgentBehaviourValues::SetWanderMaxSteerForce(float _fMaxSteerForce)
{
	m_fWanderMaxSteerForce = CMath::ClampMin(_fMaxSteerForce, 0.0f);

	CUIManager::GetWanderPanel()->SetMaxSteerForceText(m_fWanderMaxSteerForce);
}

float CAgentBehaviourValues::GetWanderMaxSteerForce()
{
	return m_fWanderMaxSteerForce;
}

void CAgentBehaviourValues::SetWanderRadius(float _fRadius)
{
	m_fWanderRadius = CMath::ClampMin(_fRadius, 0.0f);

	CUIManager::GetWanderPanel()->SetRadiusText(m_fWanderRadius);
}

float CAgentBehaviourValues::GetWanderRadius()
{
	return m_fWanderRadius;
}

void CAgentBehaviourValues::SetWanderDistance(float _fDistance)
{
	m_fWanderDistance = CMath::ClampMin(_fDistance, 0.0f);

	CUIManager::GetWanderPanel()->SetDistanceText(m_fWanderDistance);
}

float CAgentBehaviourValues::GetWanderDistance()
{
	return m_fWanderDistance;
}

void CAgentBehaviourValues::SetWanderAdjustmentInterval(float _fAdjustmentInterval) //delete?
{
	m_fWanderAdjustmentInterval = _fAdjustmentInterval;
}

float CAgentBehaviourValues::GetWanderAdjustmentInterval() //delete?
{
	return m_fWanderAdjustmentInterval;
}

void CAgentBehaviourValues::SetWanderAngleRandomStrength(float _fAngleRandStrength) //delete?
{
	m_fWanderAngleRandomStrength = _fAngleRandStrength;
}

float CAgentBehaviourValues::GetWanderAngleRandomStrength() //delete?
{
	return m_fWanderAngleRandomStrength;
}

void CAgentBehaviourValues::SetWanderAngleLerpSpeed(float _fAngleLerpSpeed) //delete?
{
	m_fWanderAngleLerpSpeed = _fAngleLerpSpeed;
}

float CAgentBehaviourValues::GetWanderAngleLerpSpeed() //delete?
{
	return m_fWanderAngleLerpSpeed;
}

//---------------------------------------------------------------------------------------------SEPARATION
void CAgentBehaviourValues::SetSeparationWeighting(float _fWeighting)
{
	m_fSeparationWeighting = CMath::Clamp(_fWeighting, 0.0f, 1.0f);

	CUIManager::GetSeparationPanel()->SetWeightText(m_fSeparationWeighting);
}

float CAgentBehaviourValues::GetSeparationWeighting()
{
	return m_fSeparationWeighting;
}

void CAgentBehaviourValues::SetSeparationStrength(float _fStrength)
{
	m_fSeparationStrength = CMath::ClampMin(_fStrength, 0.0f);

	CUIManager::GetSeparationPanel()->SetStrengthText(m_fSeparationStrength);
}

float CAgentBehaviourValues::GetSeparationStrength()
{
	return m_fSeparationStrength;
}

void CAgentBehaviourValues::SetSeparationMaxSteerForce(float _fMaxSteerForce)
{
	m_fSeparationMaxSteerForce = CMath::ClampMin(_fMaxSteerForce, 0.0f);

	CUIManager::GetSeparationPanel()->SetMaxSteerForceText(m_fSeparationMaxSteerForce);
}

float CAgentBehaviourValues::GetSeparationMaxSteerForce()
{
	return m_fSeparationMaxSteerForce;
}

void CAgentBehaviourValues::SetSeparationNeighbourhoodRadius(float _fNeighbourhoodRadius)
{
	m_fSeparationNeighbourhoodRadius = CMath::ClampMin(_fNeighbourhoodRadius, 0.0f);

	CUIManager::GetSeparationPanel()->SetNeighbourhoodRadiusText(m_fSeparationNeighbourhoodRadius);
}

float CAgentBehaviourValues::GetSeparationNeighbourhoodRadius()
{
	return m_fSeparationNeighbourhoodRadius;
}

//---------------------------------------------------------------------------------------------COHESION
void CAgentBehaviourValues::SetCohesionWeighting(float _fWeighting)
{
	m_fCohesionWeighting = CMath::Clamp(_fWeighting, 0.0f, 1.0f);

	CUIManager::GetCohesionPanel()->SetWeightText(m_fCohesionWeighting);
}

float CAgentBehaviourValues::GetCohesionWeighting()
{
	return m_fCohesionWeighting;
}

void CAgentBehaviourValues::SetCohesionStrength(float _fStrength)
{
	m_fCohesionStrength = CMath::ClampMin(_fStrength, 0.0f);

	CUIManager::GetCohesionPanel()->SetStrengthText(m_fCohesionStrength);
}

float CAgentBehaviourValues::GetCohesionStrength()
{
	return m_fCohesionStrength;
}

void CAgentBehaviourValues::SetCohesionMaxSteerForce(float _fMaxSteerForce)
{
	m_fCohesionMaxSteerForce = CMath::ClampMin(_fMaxSteerForce, 0.0f);

	CUIManager::GetCohesionPanel()->SetMaxSteerForceText(m_fCohesionMaxSteerForce);
}

float CAgentBehaviourValues::GetCohesionMaxSteerForce()
{
	return m_fCohesionMaxSteerForce;
}

void CAgentBehaviourValues::SetCohesionNeighbourhoodRadius(float _fNeighbourhoodRadius)
{
	m_fCohesionNeighbourhoodRadius = CMath::ClampMin(_fNeighbourhoodRadius, 0.0f);

	CUIManager::GetCohesionPanel()->SetNeighbourhoodRadiusText(m_fCohesionNeighbourhoodRadius);
}

float CAgentBehaviourValues::GetCohesionNeighbourhoodRadius()
{
	return m_fCohesionNeighbourhoodRadius;
}

void CAgentBehaviourValues::SetCohesionIncludeSelf(bool _bIncludeSelf)
{
	m_bCohesionIncludeSelf = _bIncludeSelf;

	CUIManager::GetCohesionPanel()->SetIncludeSelfText(m_bCohesionIncludeSelf);
}

bool CAgentBehaviourValues::GetCohesionIncludeSelf()
{
	return m_bCohesionIncludeSelf;
}

//---------------------------------------------------------------------------------------------ALIGNMENT
void CAgentBehaviourValues::SetAlignmentWeighting(float _fWeighting)
{
	m_fAlignmentWeighting = CMath::Clamp(_fWeighting, 0.0f, 1.0f);

	CUIManager::GetAlignmentPanel()->SetWeightText(m_fAlignmentWeighting);
}

float CAgentBehaviourValues::GetAlignmentWeighting()
{
	return m_fAlignmentWeighting;
}

void CAgentBehaviourValues::SetAlignmentStrength(float _fStrength)
{
	m_fAlignmentStrength = CMath::ClampMin(_fStrength, 0.0f);

	CUIManager::GetAlignmentPanel()->SetStrengthText(m_fAlignmentStrength);
}

float CAgentBehaviourValues::GetAlignmentStrength()
{
	return m_fAlignmentStrength;
}

void CAgentBehaviourValues::SetAlignmentMaxSteerForce(float _fMaxSteerForce)
{
	m_fAlignmentMaxSteerForce = CMath::ClampMin(_fMaxSteerForce, 0.0f);

	CUIManager::GetAlignmentPanel()->SetMaxSteerForceText(m_fAlignmentMaxSteerForce);
}

float CAgentBehaviourValues::GetAlignmentMaxSteerForce()
{
	return m_fAlignmentMaxSteerForce;
}

void CAgentBehaviourValues::SetAlignmentNeighbourhoodRadius(float _fNeighbourhoodRadius)
{
	m_fAlignmentNeighbourhoodRadius = CMath::ClampMin(_fNeighbourhoodRadius, 0.0f);

	CUIManager::GetAlignmentPanel()->SetNeighbourhoodRadiusText(m_fAlignmentNeighbourhoodRadius);
}

float CAgentBehaviourValues::GetAlignmentNeighbourhoodRadius()
{
	return m_fAlignmentNeighbourhoodRadius;
}