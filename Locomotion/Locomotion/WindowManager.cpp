/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : WindowManager.cpp
Description : Contains function definitions for WindowManager.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "WindowManager.h"

sf::RenderWindow* CWindowManager::m_poWindow = nullptr;

sf::RenderWindow* CWindowManager::GetWindow()
{
	//Create a default window if one doesn't exist.
	if (m_poWindow == nullptr)
	{
		m_poWindow = new sf::RenderWindow(sf::VideoMode(1280, 720), "AI Locomotion");
	}

	return m_poWindow;
}

sf::RenderWindow* CWindowManager::GetWindow(sf::Vector2i _v2iWindowSize)
{
	//Creates the window if it doesn't exist.
	if (m_poWindow == nullptr)
	{
		m_poWindow = new sf::RenderWindow(sf::VideoMode(_v2iWindowSize.x, _v2iWindowSize.y), "AI Locomotion");
	}

	return m_poWindow;
}