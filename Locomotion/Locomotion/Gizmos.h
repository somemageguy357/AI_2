#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class CAgent; //forward declaration.

class CGizmos
{
public:
	CGizmos() {};
	~CGizmos();

	void Update(CAgent* _poOwningAgent, std::vector<CAgent*>* _poVecAgentPtrs);

	static void ToggleGizmos();

	static bool GetGizmosEnabled();

	void Seek(sf::Vector2f _v2fPosition, sf::Vector2f _v2fVelocity, sf::Vector2f _v2fSeekDesiredVelocity);

	void Wander(sf::Vector2f _v2fCirclePosition, sf::Vector2f _v2fEndDirection, float _fRadius);

private:
	std::vector<sf::RectangleShape*> m_oVecLinePtrs;
	std::vector<sf::CircleShape*> m_oVecCirclePtrs;

	std::vector<sf::RectangleShape*> m_oVecRenderedLinePtrs;
	std::vector<sf::CircleShape*> m_oVecRenderedCirclePtrs;

	static bool m_bEnabled;

	void Render();

	void CreateLine();

	void CreateCircle();

	void RepositionLine(sf::RectangleShape* _poLine, sf::Vector2f _v2fStart, sf::Vector2f _v2fEnd);

	void RepositionCircle(sf::CircleShape* _poCircle, sf::Vector2f _v2fPosition, float _fRadius);
};