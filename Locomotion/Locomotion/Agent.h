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

private:
	sf::RectangleShape m_oShape;
	sf::Texture m_oTexture;

	CGizmos m_oGizmos;

	float m_fSpeed = 2.0f;
	sf::Vector2f m_v2fVelocity;

	sf::Vector2f m_v2fSeekDesiredVelocity;

	float m_fWanderAngle = 0.0f;
	float m_fWanderAdjustmentTimer = 0.0f;
	float m_fTargetWanderAngle = 0.0f;

	bool m_bEnabled = true;

	void Seek();

	void Wander();

	void Translate();

	void CheckBoundary();
};