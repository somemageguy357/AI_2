#include "MouseCircle.h"
#include "WindowManager.h"
#include "AgentManager.h"

CMouseCircle* CMouseCircle::m_poInstance = nullptr;

CMouseCircle::CMouseCircle(float _fRadius)
{
	m_oCircle = sf::CircleShape(_fRadius);
	m_oCircle.setOrigin({ _fRadius, _fRadius });

	sf::FloatRect oBoundary = CAgentManager::GetBoundary()->getGlobalBounds();
	m_oCircle.setPosition({ oBoundary.left + (oBoundary.width / 2), oBoundary.top + (oBoundary.height / 2) });
}

CMouseCircle::~CMouseCircle() {}

void CMouseCircle::Update()
{
	sf::Vector2i v2iMousePosition = sf::Mouse::getPosition(*CWindowManager::GetWindow());
	sf::FloatRect oBoundary = CAgentManager::GetBoundary()->getGlobalBounds();

	if (v2iMousePosition.x <= oBoundary.left + oBoundary.width &&
		v2iMousePosition.x >= oBoundary.left &&
		v2iMousePosition.y <= oBoundary.top + oBoundary.height &&
		v2iMousePosition.y >= oBoundary.top)
	{
		m_oCircle.setPosition({ (float)v2iMousePosition.x, (float)(v2iMousePosition.y) });
	}
}

void CMouseCircle::Render()
{
	CWindowManager::GetWindow()->draw(m_oCircle);
}

sf::Vector2f CMouseCircle::GetPosition()
{
	return m_oCircle.getPosition();
}
