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

private:
	sf::RectangleShape m_oShape;
	sf::Texture m_oTexture;

	CGizmos m_oGizmos;

	sf::Vector2f m_v2fVelocity;

	sf::Vector2f m_v2fArrivalDesiredVelocity;

	sf::Vector2f m_v2fSeekDesiredVelocity;

	float m_fWanderAngle = 0.0f;
	float m_fWanderAdjustmentTimer = 0.0f;
	float m_fTargetWanderAngle = 0.0f;

	bool m_bEnabled = true;

	void Arrival();

	void Seek();

	void Wander();

	void Translate();

	void CheckBoundary();
};