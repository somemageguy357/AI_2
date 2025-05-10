#pragma once
#include "SFML/Graphics.hpp"
#include "Gizmos.h"

class CAgent
{
public:
	CAgent();
	CAgent(sf::Vector2f _v2fStartPosition);
	~CAgent();

	void Update();

	void LateUpdate();

	void Render();

	void SetEnabled(bool _bEnabled);

	void SetPosition(sf::Vector2f _v2fPosition);

	sf::Vector2f GetPosition();

	void ResetVelocity();

	void SetPursuitTarget(bool _bIsTarget);

private:
	sf::RectangleShape m_oShape;
	sf::Texture m_oTexture;

	CGizmos m_oGizmos;

	float m_fMaxSpeed = 10.0f;

	sf::Vector2f m_v2fVelocity;
	sf::Vector2f m_v2fArrivalDesiredVelocity;
	sf::Vector2f m_v2fSeekDesiredVelocity;

	sf::Vector2f m_v2fCohesionCenterOfMass;

	float m_fWanderAngle = 0.0f;
	float m_fWanderAdjustmentTimer = 0.0f;
	float m_fTargetWanderAngle = 0.0f;

	bool m_bPursuitTarget = false;

	bool m_bEnabled = true;

	void Arrival();

	void Seek(sf::Vector2f _v2fTargetPosition);

	void Pursuit();

	void Wander();

	void Separation();

	void Cohesion();

	void Alignment();

	void Translate();

	void CheckBoundary();
};