/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : WindowManager.h
Description : Manages the render window.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>

//Manages the render window.
class CWindowManager
{
public:
	/// <summary>
	/// Gets a pointer to the render window. Creates one of size 1280x720 if one does not exist.
	/// </summary>
	/// <returns>A pointer to the render window.</returns>
	static sf::RenderWindow* GetWindow();

	/// <summary>
	/// Creates a render window with the given size if it does not already exist and returns it.
	/// </summary>
	/// <param name="_v2iWindowSize:">The size of the window.</param>
	/// <returns>A pointer to the render window.</returns>
	static sf::RenderWindow* GetWindow(sf::Vector2i _v2iWindowSize);

private:
	static sf::RenderWindow* m_poWindow;

	CWindowManager() = delete;
	~CWindowManager() = delete;
};