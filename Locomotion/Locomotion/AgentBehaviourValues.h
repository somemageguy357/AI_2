#pragma once

class CAgentBehaviourValues
{
public:
	enum class EBehaviour
	{
		Arrival,
		Flock,
		Seek,
		Wander,
		Pursuit,
	};

	static void InitBehaviour(EBehaviour _eBehaviour);

	#pragma region Get/Set
	static float GetAgentSpeedMultiplier();

	static void SetArrivalWeighting(float _fWeighting);
	static float GetArrivalWeighting();
	static void SetArrivalStrength(float _fStrength);
	static float GetArrivalStrength();
	static void SetArrivalMaxSteerForce(float _fMaxSteerForce);
	static float GetArrivalMaxSteerForce();
	static void SetArrivalStoppingRadius(float _fRadius);
	static float GetArrivalStoppingRadius();

	static void SetSeekWeighting(float _fWeighting);
	static float GetSeekWeighting();
	static void SetSeekStrength(float _fStrength);
	static float GetSeekStrength();
	static void SetSeekMaxSteerForce(float _fMaxSteerForce);
	static float GetSeekMaxSteerForce();

	static void SetFleeWeighting(float _fWeighting);
	static float GetFleeWeighting();
	static void SetFleeStrength(float _fStrength);
	static float GetFleeStrength();
	static void SetFleeMaxSteerForce(float _fMaxSteerForce);
	static float GetFleeMaxSteerForce();

	static void SetWanderWeighting(float _fWeighting);
	static float GetWanderWeighting();
	static void SetWanderStrength(float _fStrength);
	static float GetWanderStrength();
	static void SetWanderMaxSteerForce(float _fMaxSteerForce);
	static float GetWanderMaxSteerForce();
	static void SetWanderRadius(float _fRadius);
	static float GetWanderRadius();
	static void SetWanderDistance(float _fDistance);
	static float GetWanderDistance();

	static void SetSeparationWeighting(float _fWeighting);
	static float GetSeparationWeighting();
	static void SetSeparationStrength(float _fStrength);
	static float GetSeparationStrength();
	static void SetSeparationMaxSteerForce(float _fMaxSteerForce);
	static float GetSeparationMaxSteerForce();
	static void SetSeparationNeighbourhoodRadius(float _fNeighbourhoodRadius);
	static float GetSeparationNeighbourhoodRadius();

	static void SetCohesionWeighting(float _fWeighting);
	static float GetCohesionWeighting();
	static void SetCohesionStrength(float _fStrength);
	static float GetCohesionStrength();
	static void SetCohesionMaxSteerForce(float _fMaxSteerForce);
	static float GetCohesionMaxSteerForce();
	static void SetCohesionNeighbourhoodRadius(float _fNeighbourhoodRadius);
	static float GetCohesionNeighbourhoodRadius();
	static void SetCohesionIncludeSelf(bool _bIncludeSelf);
	static bool GetCohesionIncludeSelf();

	static void SetAlignmentWeighting(float _fWeighting);
	static float GetAlignmentWeighting();
	static void SetAlignmentStrength(float _fStrength);
	static float GetAlignmentStrength();
	static void SetAlignmentMaxSteerForce(float _fMaxSteerForce);
	static float GetAlignmentMaxSteerForce();
	static void SetAlignmentNeighbourhoodRadius(float _fNeighbourhoodRadius);
	static float GetAlignmentNeighbourhoodRadius();
	#pragma endregion

private:
	static float m_fAgentSpeedMultiplier;

	static float m_fArrivalWeighting;
	static float m_fArrivalStrength;
	static float m_fArrivalMaxSteerForce;
	static float m_fArrivalStoppingRadius;

	static float m_fSeekWeighting;
	static float m_fSeekStrength;
	static float m_fSeekMaxSteerForce;

	static float m_fFleeWeighting;
	static float m_fFleeStrength;
	static float m_fFleeMaxSteerForce;

	static float m_fWanderWeighting;
	static float m_fWanderStrength;
	static float m_fWanderMaxSteerForce;
	static float m_fWanderRadius;
	static float m_fWanderDistance;

	static float m_fSeparationWeighting;
	static float m_fSeparationStrength;
	static float m_fSeparationMaxSteerForce;
	static float m_fSeparationNeighbourhoodRadius;

	static float m_fCohesionWeighting;
	static float m_fCohesionStrength;
	static float m_fCohesionMaxSteerForce;
	static float m_fCohesionNeighbourhoodRadius;
	static bool m_bCohesionIncludeSelf;

	static float m_fAlignmentWeighting;
	static float m_fAlignmentStrength;
	static float m_fAlignmentMaxSteerForce;
	static float m_fAlignmentNeighbourhoodRadius;

	static void ResetAllValues();

	static void InitArrivalBehaviour();

	static void InitFlockBehaviour();

	static void InitSeekBehaviour();

	static void InitWanderBehaviour();
};