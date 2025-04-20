/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : main.cpp
Description : Performs the main loop that runs the program.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "WindowManager.h"
#include "UIManager.h"
#include "AgentManager.h"

void main()
{
	srand(time(NULL));

	sf::RenderWindow* poMainWindow = CWindowManager::GetWindow({ 1280, 720 });

	CUIManager::InitUI();
	CAgentManager::InitAgentManager();

	while (poMainWindow != nullptr && poMainWindow->isOpen() == true)
	{
		sf::Event oMainEvent;
		bool bIsClicking = false;

		while (poMainWindow != nullptr && poMainWindow->pollEvent(oMainEvent))
		{
			//Gets mouse left mouse click.
			if (oMainEvent.type == sf::Event::MouseButtonPressed && oMainEvent.mouseButton.button == sf::Mouse::Left)
			{
				bIsClicking = true;
			}

			if (oMainEvent.type == sf::Event::Closed)
			{
				poMainWindow = nullptr;
			}
		}

		if (poMainWindow != nullptr)
		{
			poMainWindow->clear();
			
			//----------UPDATE----------
			CUIManager::Update(bIsClicking);
			CAgentManager::Update();

			//----------RENDER----------
			CUIManager::Render();
			CAgentManager::Render();

			poMainWindow->display();
		}
	}

	CAgentManager::Destroy();
	CUIManager::Destroy();
}