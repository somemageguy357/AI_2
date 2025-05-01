#pragma once
#include "SFML/Graphics.hpp"

class CMath
{
public:
	static sf::Vector2f CenterPoint(sf::Vector2f _v2fPoint1, sf::Vector2f _v2fPoint2);

	static void Normalize(sf::Vector2f* _v2fVector);

	static sf::Vector2f Normalize(const sf::Vector2f _v2fVector);

	static float Distance(sf::Vector2f _v2fPoint1, sf::Vector2f _v2fPoint2);

	static float Abs(float _fValue);

	static float PI();

	static float Clamp(float _fValue, float _fMin, float _fMax);

	static sf::Vector2f ClampMagnitude(sf::Vector2f _v2fVector, float _fMax);

private:
	CMath() = delete;
	~CMath() = delete;
};