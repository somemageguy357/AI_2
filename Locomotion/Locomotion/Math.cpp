#include "Math.h"

#include <iostream>

const float CMath::m_fPI = 3.14159f;
const float CMath::m_fDegToRad = PI() / 180;
const float CMath::m_fRadToDeg = 180 / PI();

float CMath::RandomRange(float _fMin, float _fMax)
{
	float fRange = _fMax - _fMin;

	float fValue = rand() % ((int)fRange * 1000) + ((int)_fMin * 1000);

	fValue /= 1000;

	return fValue;
}

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

sf::Vector2f CMath::Normalize(const sf::Vector2f _kv2fVector)
{
	float fMag = sqrt(pow(_kv2fVector.x, 2) + pow(_kv2fVector.y, 2));

	if (fMag == 0)
	{
		return { 0.0f, 0.0f };
	}

	sf::Vector2f v2fNormalizedVector = _kv2fVector / fMag;

	return v2fNormalizedVector;
}

float CMath::GetMagnitude(sf::Vector2f _v2fVector)
{
	return sqrt(pow(_v2fVector.x, 2) + pow(_v2fVector.y, 2));
}

float CMath::Distance(sf::Vector2f _v2fPoint1, sf::Vector2f _v2fPoint2)
{
	return sqrt(pow(_v2fPoint1.x - _v2fPoint2.x, 2) + pow(_v2fPoint1.y - _v2fPoint2.y, 2));
}

sf::Vector2f CMath::TargetDirection(sf::Vector2f _v2fTargetPos, sf::Vector2f _v2fSelfPos)
{
	sf::Vector2f v2fTargetDirection = _v2fTargetPos - _v2fSelfPos;

	return v2fTargetDirection;
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

const float CMath::PI()
{
	return m_fPI;
}

const float CMath::DegToRad()
{
	return m_fDegToRad;
}

const float CMath::RadToDeg()
{
	return m_fRadToDeg;
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

float CMath::ClampMin(float _fValue, float _fMin)
{
	float fValue = _fValue;

	if (fValue < _fMin)
	{
		fValue = _fMin;
	}

	return fValue;
}

sf::Vector2f CMath::ClampMagnitude(sf::Vector2f _v2fVector, float _fMax)
{
	sf::Vector2f v2fClamped = { Clamp(_v2fVector.x, -_fMax, _fMax), Clamp(_v2fVector.y, -_fMax, _fMax) };

	return v2fClamped;
}

float CMath::Lerp(float _fA, float _fB, float _fT)
{
	float fValue = _fA + (_fB - _fA) * _fT;

	return fValue;
}