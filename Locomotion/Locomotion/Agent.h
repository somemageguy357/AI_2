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

	void Render();

	void SetEnabled(bool _bEnabled);

	void SetPosition(sf::Vector2f _v2fPosition);

	sf::Vector2f GetPosition();

private:
	sf::RectangleShape m_oShape;
	sf::Texture m_oTexture;

	CGizmos m_oGizmos;

	float m_fSpeed = 200.0f;
	sf::Vector2f m_v2fMoveDir;
	sf::Vector2f m_v2fSeekDesiredVelocity;

	bool m_bEnabled = true;

	void Seek();

	void Translate();

	void CheckBoundary();
};