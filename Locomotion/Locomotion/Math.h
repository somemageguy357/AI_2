#pragma once
#include "SFML/Graphics.hpp"

class CMath
{
public:
	static float RandomRange(float _fMin, float _fMax);

	static sf::Vector2f CenterPoint(sf::Vector2f _v2fPoint1, sf::Vector2f _v2fPoint2);

	static void Normalize(sf::Vector2f* _v2fVector);

	static sf::Vector2f Normalize(const sf::Vector2f _kv2fVector);

	static float Distance(sf::Vector2f _v2fPoint1, sf::Vector2f _v2fPoint2);

	static float Abs(float _fValue);

	static const float PI();

	static const float DegToRad();

	static const float RadToDeg();

	static float Clamp(float _fValue, float _fMin, float _fMax);

	static float ClampMin(float _fValue, float _fMin);

	static sf::Vector2f ClampMagnitude(sf::Vector2f _v2fVector, float _fMax);

	static float Lerp(float _fA, float _fB, float _fT);

private:
	static const float m_fPI;
	static const float m_fDegToRad;
	static const float m_fRadToDeg;

	CMath() = delete;
	~CMath() = delete;
};