#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class CAgent; //forward declaration.

class CGizmos
{
public:
	CGizmos() {};
	~CGizmos() {};

	void Update(CAgent* _poOwningAgent, std::vector<CAgent*>* _poVecAgentPtrs);

	void Render();

private:
	std::vector<sf::RectangleShape*> m_oVecLinePtrs;
	std::vector<sf::CircleShape*> m_oVecCirclePtrs;

	void CreateLine();

	void CreateCircle();

	void RepositionLine(sf::RectangleShape* _poLine, sf::Vector2f _v2fStart, sf::Vector2f _v2fEnd);

	void RepositionCircle(sf::Vector2f _v2fPosition, float _fRadius);
};