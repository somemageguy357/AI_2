/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : AgentManager.h
Description : Static class that contains all agents, calls their Update and Render functions, and contains the boundary.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "Agent.h"

#include <vector>

class CAgentManager
{
public:
	/// <summary>
	/// Calls Update() for every agent. Also allows agents to be created by clicking in the boundary (during Wander only).
	/// </summary>
	/// <param name="_bIsClicking:">If the LMB has been pressed this frame.</param>
	static void Update(bool _bIsClicking);

	/// <summary>
	/// Calls LateUpdate() for every agent. Occurs after Update().
	/// </summary>
	static void LateUpdate();

	/// <summary>
	/// Calls Render() for every agent.
	/// </summary>
	static void Render();

	/// <summary>
	/// Sets up the boundary.
	/// </summary>
	static void InitAgentManager();

	/// <summary>
	/// Checks the pool of agents and enables any that are required depending on the given count value. If there are no
	/// agents available in the pool: new ones will be created.
	/// </summary>
	/// <param name="_uiCount:">The number of agents to have enabled.</param>
	static void SpawnAgents(unsigned int _uiCount);

	/// <summary>
	/// Returns a pointer to the vector containing all agents.
	/// </summary>
	/// <returns>A pointer to the vector containing all agents.</returns>
	static std::vector<CAgent*>* GetAgents();

	/// <summary>
	/// Returns a pointer to the boundary shape.
	/// </summary>
	/// <returns></returns>
	static sf::RectangleShape* GetBoundary();

	/// <summary>
	/// Destroys/deletes all agents.
	/// </summary>
	static void Destroy();

private:
	static sf::RectangleShape m_oBoundary;

	static std::vector<CAgent*> m_oVecAgentPtrs;

	static unsigned int m_uiActiveAgents;

	CAgentManager() = delete;
	~CAgentManager() = delete;

	/// <summary>
	/// Randomly positions agents within the boundary.
	/// </summary>
	/// <param name="_iCount:">The number of agents to reposition.</param>
	static void PositionAgents(int _iCount);

	/// <summary>
	/// Spawns a single agent if one is not available in the pool. Otherwise enables one. Repositions the agent to the given value.
	/// </summary>
	/// <param name="_v2fPosition:">The starting position of the newly created agent.</param>
	static void SpawnSingleAgent(sf::Vector2f _v2fPosition);
};