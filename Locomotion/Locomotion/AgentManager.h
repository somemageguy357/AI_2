#pragma once
#include "Agent.h"

#include <vector>

class CAgentManager
{
public:
	static void Update(bool _bIsClicking);

	static void LateUpdate();

	static void Render();

	static void InitAgentManager();

	static void SpawnAgents(unsigned int _uiCount);

	static std::vector<CAgent*>* GetAgents();

	static sf::RectangleShape* GetBoundary();

	static void Destroy();

private:
	static sf::RectangleShape m_oBoundary;

	static std::vector<CAgent*> m_oVecAgentPtrs;

	static unsigned int m_uiActiveAgents;

	CAgentManager() = delete;
	~CAgentManager() = delete;

	static void PositionAgents(int _iCount);

	static void SpawnSingleAgent(sf::Vector2f _v2fPosition);
};