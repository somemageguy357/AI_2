/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : Gizmos.h
Description : Used to display agent behaviours. Draws lines and circles representing their current and steering directions.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class CAgent; //forward declaration.

class CGizmos
{
public:
	CGizmos() {};

	~CGizmos();

	/// <summary>
	/// Enables/disables the rendering of all gizmos.
	/// </summary>
	static void ToggleGizmos();

	/// <summary>
	/// Returns the current enabled state of gizmos.
	/// </summary>
	/// <returns>The current enabled state.</returns>
	static bool GetGizmosEnabled();

	/// <summary>
	/// Creates and renders gizmos relevant to the Arrival behaviour.
	/// </summary>
	/// <param name="_v2fPosition:">The agent's position.</param>
	/// <param name="_v2fVelocity:">The direction of the agent's velocity.</param>
	/// <param name="_v2fDesiredVelocity:">The direction of the agent's desired velocity.</param>
	/// <param name="_v2fStopPoint:">The position of the target.</param>
	/// <param name="_fStopRadius:">The stopping radius.</param>
	void Arrival(sf::Vector2f _v2fPosition, sf::Vector2f _v2fVelocity, sf::Vector2f _v2fDesiredVelocity, sf::Vector2f _v2fStopPoint, float _fStopRadius);

	/// <summary>
	/// Creates and renders gizmos relevant to the Seek behaviour.
	/// </summary>
	/// <param name="_v2fPosition:">The agent's position.</param>
	/// <param name="_v2fVelocity:">The direction of the agent's velocity.</param>
	/// <param name="_v2fDesiredVelocity:">The direction of the agent's desired velocity.</param>
	void Seek(sf::Vector2f _v2fPosition, sf::Vector2f _v2fVelocity, sf::Vector2f _v2fDesiredVelocity);

	/// <summary>
	/// Creates and renders gizmos relevant to the Wander behaviour.
	/// </summary>
	/// <param name="_v2fCirclePosition:">The agent's position.</param>
	/// <param name="_v2fEndDirection:">The wander direction.</param>
	/// <param name="_fRadius:">The wander radius.</param>
	void Wander(sf::Vector2f _v2fCirclePosition, sf::Vector2f _v2fEndDirection, float _fRadius);

private:
	//Pool of all gizmos that have been created.
	std::vector<sf::RectangleShape*> m_oVecLinePtrs;
	std::vector<sf::CircleShape*> m_oVecCirclePtrs;

	//Gizmos that are to be rendered.
	std::vector<sf::RectangleShape*> m_oVecRenderedLinePtrs;
	std::vector<sf::CircleShape*> m_oVecRenderedCirclePtrs;

	static bool m_bEnabled;

	void Render();

	void CreateLine();

	void CreateCircle();

	void RepositionLine(sf::RectangleShape* _poLine, sf::Vector2f _v2fStart, sf::Vector2f _v2fEnd);

	void RepositionCircle(sf::CircleShape* _poCircle, sf::Vector2f _v2fPosition, float _fRadius);
};