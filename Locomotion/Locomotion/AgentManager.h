#pragma once
#include "Agent.h"

#include <vector>

class CAgentManager
{
public:
	static CAgentManager* GetInstance()
	{
		if (m_poInstance == nullptr)
		{
			m_poInstance = new CAgentManager();
		}

		return m_poInstance;
	}

	void Update();

	void Render();

	void SpawnAgents(int _iCount);

	std::vector<CAgent*>* GetAgents();

private:
	static CAgentManager* m_poInstance;

	sf::RectangleShape m_oBoundary;

	std::vector<CAgent*> m_oVecAgentPtrs;

	CAgentManager();
	~CAgentManager();

	void PositionAgents(int _iCount);
};