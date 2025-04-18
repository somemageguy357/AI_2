#pragma once
#include "SFML/Graphics.hpp"
#include "Gizmos.h"

class CAgentManager; //forward declaration.

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

	bool m_bEnabled = true;
};