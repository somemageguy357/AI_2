#include "Math.h"

sf::Vector2f CMath::CenterPoint(sf::Vector2f _v2fPoint1, sf::Vector2f _v2fPoint2)
{
	return { (_v2fPoint1.x + _v2fPoint2.x) / 2, (_v2fPoint1.y + _v2fPoint2.y) / 2 };
}

float CMath::Distance(sf::Vector2f _v2fPoint1, sf::Vector2f _v2fPoint2)
{
	return sqrt(pow(_v2fPoint1.x - _v2fPoint2.x, 2) + pow(_v2fPoint1.y - _v2fPoint2.y, 2));
}

float CMath::Abs(float _fValue)
{
	float fAbsValue = _fValue;

	if (fAbsValue < 0.0f)
	{
		fAbsValue *= -1;
	}

	return fAbsValue;
}

float CMath::PI()
{
	return 3.14159f;
}

float CMath::Clamp(float _fValue, float _fMin, float _fMax)
{
	float fValue = _fValue;

	if (fValue > _fMax)
	{
		fValue = _fMax;
	}

	else if (fValue < _fMin)
	{
		fValue = _fMin;
	}

	return fValue;
}