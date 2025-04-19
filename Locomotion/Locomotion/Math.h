#pragma once
#include "SFML/Graphics.hpp"

class CMath
{
public:
	static sf::Vector2f CenterPoint(sf::Vector2f _v2fPoint1, sf::Vector2f _v2fPoint2);

	static float Distance(sf::Vector2f _v2fPoint1, sf::Vector2f _v2fPoint2);

	static float Abs(float _fValue);

	static float PI();

	static float Clamp(float _fValue, float _fMin, float _fMax);

private:
	CMath() = delete;
	~CMath() = delete;
};