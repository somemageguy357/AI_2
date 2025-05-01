#include "Math.h"

sf::Vector2f CMath::CenterPoint(sf::Vector2f _v2fPoint1, sf::Vector2f _v2fPoint2)
{
	return { (_v2fPoint1.x + _v2fPoint2.x) / 2, (_v2fPoint1.y + _v2fPoint2.y) / 2 };
}

void CMath::Normalize(sf::Vector2f* _v2fVector)
{
	sf::Vector2f v2fCopy = *_v2fVector;

	float fMag = sqrt(pow(_v2fVector->x, 2) + pow(_v2fVector->y, 2));

	if (fMag == 0)
	{
		return;
	}

	*_v2fVector = v2fCopy / fMag;
}

sf::Vector2f CMath::Normalize(const sf::Vector2f _v2fVector)
{
	float fMag = sqrt(pow(_v2fVector.x, 2) + pow(_v2fVector.y, 2));

	if (fMag == 0)
	{
		return { 0.0f, 0.0f };
	}

	sf::Vector2f v2fNormalizedVector = _v2fVector / fMag;

	return v2fNormalizedVector;
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

sf::Vector2f CMath::ClampMagnitude(sf::Vector2f _v2fVector, float _fMax)
{
	sf::Vector2f v2fClamped = _v2fVector;

	float fMag = Clamp(sqrt(pow(_v2fVector.x, 2) + pow(_v2fVector.y, 2)), 0.0f, _fMax);

	if (fMag == 0)
	{
		return v2fClamped;
	}

	v2fClamped = _v2fVector / fMag;

	return v2fClamped;
}