/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : Agent.h
Description : Agents display various AI steering behaviours.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "SFML/Graphics.hpp"
#include "Gizmos.h"

class CAgent
{
public:
	/// <summary>
	/// Creates an agent with a default position of (0.0f, 0.0f).
	/// </summary>
	CAgent();

	/// <summary>
	/// Creates an agent with a set starting position.
	/// </summary>
	/// <param name="_v2fStartPosition:">The start position of the agent.</param>
	CAgent(sf::Vector2f _v2fStartPosition);

	~CAgent();

	/// <summary>
	/// Active every frame if enabled. Checks to see if any steering behaviours should be applied to its movement, moves the agent, and checks
	/// to see if the agent has left the boundary space.
	/// </summary>
	void Update();

	/// <summary>
	/// Active every frame after Update if enabled. Allows the drawing of all gizmos currently enabled and attached to this agent.
	/// </summary>
	void LateUpdate();

	/// <summary>
	/// Active every frame after LateUpdate if enabled. Draws the agent to the render window.
	/// </summary>
	void Render();

	/// <summary>
	/// Sets the enabled state of the agent. Determines if its Update, LateUpdate, and Render functions are run.
	/// </summary>
	/// <param name="_bEnabled:">The new value of the enabled state.</param>
	void SetEnabled(bool _bEnabled);

	/// <summary>
	/// Sets the position of the agent.
	/// </summary>
	/// <param name="_v2fPosition:">The new position of the agent.</param>
	void SetPosition(sf::Vector2f _v2fPosition);

	/// <summary>
	/// Returns the current position of the agent.
	/// </summary>
	/// <returns>The current position of the agent.</returns>
	sf::Vector2f GetPosition();

	/// <summary>
	/// Resets the agent's velocity to (0.0f, 0.0f).
	/// </summary>
	void ResetVelocity();

private:
	sf::RectangleShape m_oShape;
	sf::Texture m_oTexture;

	CGizmos m_oGizmos;

	float m_fMaxSpeed = 10.0f;

	sf::Vector2f m_v2fVelocity;
	sf::Vector2f m_v2fArrivalDesiredVelocity;
	sf::Vector2f m_v2fSeekDesiredVelocity;

	sf::Vector2f m_v2fCohesionCenterOfMass;

	float m_fWanderAngle = 0.0f;
	float m_fWanderAdjustmentTimer = 0.0f;
	float m_fTargetWanderAngle = 0.0f;

	bool m_bEnabled = true;

	/// <summary>
	/// Performs the Arrival behaviour. Causes the agent to move towards a target where it will slow down upon entering
	/// its slowing/stopping radius.
	/// </summary>
	void Arrival();

	/// <summary>
	/// Performs the Seek behaviour. Causes the agent to move towards a target.
	/// </summary>
	void Seek(sf::Vector2f _v2fTargetPosition);

	/// <summary>
	/// Performs the Wander behaviour. Causes the agent to move smoothly around as it acquires new randomized directions. 
	/// </summary>
	void Wander();

	/// <summary>
	/// Performs the Separation behaviour. Causes the agent to veer away from other agents that enter the Separation Neighbourhood Radius.
	/// </summary>
	void Separation();

	/// <summary>
	/// Performs the Cohesion behaviour. Causes the agent to move closer to other agents that enter the Cohesion Neighbourhood Radius.
	/// </summary>
	void Cohesion();

	/// <summary>
	/// Performs the Alignment behaviour. Causes the agent to copy/share the same velocity of nearby agents that enter the Alignment 
	/// Neighbourhood Radius.
	/// </summary>
	void Alignment();

	/// <summary>
	/// Updates the position and rotation of the agent according to changes to its velocity.
	/// </summary>
	void Translate();

	/// <summary>
	/// Moves the agent to the opposite end of the boundary if it crosses over an edge.
	/// </summary>
	void CheckBoundary();

	/// <summary>
	/// Calcuates the steer force and velocity for the agent.
	/// </summary>
	void CalculateSteerVelocity(sf::Vector2f _v2fDesiredVelocity, float _fMaxSteerForce, float _fStrength, float _fWeighting);
};