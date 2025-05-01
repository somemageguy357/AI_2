#pragma once
#include "SFML/Graphics.hpp"

class CMouseCircle
{
public:
	static CMouseCircle* GetInstance()
	{
		if (m_poInstance == nullptr)
		{
			m_poInstance = new CMouseCircle(10.0f);
		}

		return m_poInstance;
	}

	void Update();

	void Render();

	sf::Vector2f GetPosition();

private:
	static CMouseCircle* m_poInstance;

	sf::CircleShape m_oCircle;

	CMouseCircle(float _fRadius);
	~CMouseCircle();
};