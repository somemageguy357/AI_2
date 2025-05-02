#pragma once
#include "Agent.h"

#include <vector>

class CAgentManager
{
public:
	static void Update();

	static void LateUpdate();

	static void Render();

	static void InitAgentManager();

	static void SpawnAgents(int _iCount);

	static std::vector<CAgent*>* GetAgents();

	static sf::RectangleShape* GetBoundary();

	static void Destroy();

private:
	static sf::RectangleShape m_oBoundary;

	static std::vector<CAgent*> m_oVecAgentPtrs;

	CAgentManager() = delete;
	~CAgentManager() = delete;

	static void PositionAgents(int _iCount);
};