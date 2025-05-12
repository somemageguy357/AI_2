/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : Math.h
Description : Static class containing various math functions.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "SFML/Graphics.hpp"

class CMath
{
public:
	/// <summary>
	/// Returns a random float value between the given minimum and maximum values.
	/// </summary>
	/// <param name="_fMin:">The minimum value.</param>
	/// <param name="_fMax:">The maximum value.</param>
	/// <returns>A random float value between the given minimum and maximum values.</returns>
	static float RandomRange(float _fMin, float _fMax);

	/// <summary>
	/// Returns the center point between two vectors.
	/// </summary>
	/// <param name="_v2fPoint1:">The first vector.</param>
	/// <param name="_v2fPoint2:">The second vector.</param>
	/// <returns>The center point between two vectors.</returns>
	static sf::Vector2f CenterPoint(sf::Vector2f _v2fPoint1, sf::Vector2f _v2fPoint2);

	/// <summary>
	/// Normalizes the given vector.
	/// </summary>
	/// <param name="_v2fVector:">The vector to normalize.</param>
	static void Normalize(sf::Vector2f* _v2fVector);

	/// <summary>
	/// Returns a copy of the vector that is to be normalized.
	/// </summary>
	/// <param name="_kv2fVector:">The vector to create a copy from.</param>
	/// <returns>A copy of the vector that is to be normalized.</returns>
	static sf::Vector2f Normalize(const sf::Vector2f _kv2fVector);

	/// <summary>
	/// Returns the magnitude of the given vector.
	/// </summary>
	/// <param name="_v2fVector:">The vector to get the magnitude from.</param>
	/// <returns>The magnitude of the given vector.</returns>
	static float GetMagnitude(sf::Vector2f _v2fVector);

	/// <summary>
	/// Returns the distance between two vectors.
	/// </summary>
	/// <param name="_v2fPoint1:">The first vector.</param>
	/// <param name="_v2fPoint2:">The second vector.</param>
	/// <returns>The distance between two vectors.</returns>
	static float Distance(sf::Vector2f _v2fPoint1, sf::Vector2f _v2fPoint2);

	/// <summary>
	/// Returns a copy absolute value of the given float.
	/// </summary>
	/// <param name="_fValue:">The float to absolute.</param>
	/// <returns>A copy absolute value of the given float.</returns>
	static float Abs(float _fValue);

	/// <summary>
	/// Returns the value of PI.
	/// </summary>
	/// <returns>The value of PI.</returns>
	static const float PI();

	/// <summary>
	/// Returns the conversion value of degrees to radians.
	/// </summary>
	/// <returns>The conversion value of degrees to radians.</returns>
	static const float DegToRad();

	/// <summary>
	/// Returns the conversion value of radians to degrees.
	/// </summary>
	/// <returns>The conversion value of radians to degrees.</returns>
	static const float RadToDeg();

	/// <summary>
	/// Returns a clamped copy of the given float between the two values.
	/// </summary>
	/// <param name="_fValue:">The float value to clamp.</param>
	/// <param name="_fMin:">The min clamp value.</param>
	/// <param name="_fMax:">The max clamp value.</param>
	/// <returns>A clamped copy of the given float between the two values.</returns>
	static float Clamp(float _fValue, float _fMin, float _fMax);

	/// <summary>
	/// Returns a min clamped copy of the given float.
	/// </summary>
	/// <param name="_fValue:">The float value to clamp.</param>
	/// <param name="_fMin:">The min clamp value.</param>
	/// <returns>A min clamped copy of the given float.</returns>
	static float ClampMin(float _fValue, float _fMin);

	/// <summary>
	/// Returns a max clamped copy of the given vector's magnitude.
	/// </summary>
	/// <param name="_v2fVector:">The vector whose magnitude value is to be max clamped.</param>
	/// <param name="_fMax:">The max clamp value.</param>
	/// <returns>A max clamped copy of the given vector's magnitude.</returns>
	static sf::Vector2f ClampMagnitude(sf::Vector2f _v2fVector, float _fMax);

	/// <summary>
	/// Returns a float value equal to the value between A and B through T.
	/// </summary>
	/// <param name="_fA:">The start value.</param>
	/// <param name="_fB:">The end value.</param>
	/// <param name="_fT:">The current progress value.</param>
	/// <returns>A float value equal to the value between A and B through T.</returns>
	static float Lerp(float _fA, float _fB, float _fT);

private:
	static const float m_fPI;
	static const float m_fDegToRad;
	static const float m_fRadToDeg;

	CMath() = delete;
	~CMath() = delete;
};