/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : MouseCircle.h
Description : An sf::CircleShape that follows the mouse position when enabled. Used to represent the target for an agent during
				Arrival and Seek behaviours. Disabled by default.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

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

	/// <summary>
	/// Updates the position of the circle, provided it is enabled and within the boundary.
	/// </summary>
	void Update();

	/// <summary>
	/// Renders the circle to the render window, provided it is enabled.
	/// </summary>
	void Render();

	/// <summary>
	/// Returns the position of the circle.
	/// </summary>
	/// <returns>The position of the circle.</returns>
	sf::Vector2f GetPosition();

	/// <summary>
	/// Sets the enabled state of the circle.
	/// </summary>
	/// <param name="_bEnabled:">The new enabled state.</param>
	void SetEnabled(bool _bEnabled);

private:
	static CMouseCircle* m_poInstance;

	sf::CircleShape m_oCircle;

	bool m_bEnabled = false; //Disabled by default.

	CMouseCircle(float _fRadius);

	~CMouseCircle();
};