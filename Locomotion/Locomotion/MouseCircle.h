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

	void SetEnabled(bool _bEnabled);

private:
	static CMouseCircle* m_poInstance;

	sf::CircleShape m_oCircle;

	bool m_bEnabled = false;

	CMouseCircle(float _fRadius);
	~CMouseCircle();
};