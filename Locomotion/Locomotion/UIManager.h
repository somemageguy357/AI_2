/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIManager.h
Description : Static class that handles all UI elements and runs their Update and Render functions.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include <vector>
#include "UIButton.h"
#include "UIText.h"

//Static class that handles all UI elements and runs their Update and Render functions.
class CUIManager
{
public:
	/// <summary>
	/// Calls Update() in all UI elements.
	/// </summary>
	/// <param name="_bIsClicking:">If the left mouse button is down. Used for button clicks.</param>
	static void Update(bool _bIsClicking);

	/// <summary>
	/// Calls Render() in all UI elements.
	/// </summary>
	static void Render();

	/// <summary>
	/// Creates all UI elements and stores them.
	/// </summary>
	static void InitUI();

	/// <summary>
	/// Gets the font used for UI text elements.
	/// </summary>
	/// <returns></returns>
	static sf::Font* GetUIFont();

	/// <summary>
	/// Deletes all UI elements and calls their destructors.
	/// </summary>
	static void Destroy();

private:
	static std::vector<CUIButton*> m_oVecButtonPtrs;
	static std::vector<CUIText*> m_oVecTextPtrs;

	static sf::Font* m_poUIFont;

	/// <summary>
	/// Creates a UI button element.
	/// </summary>
	/// <param name="_v2fSize:">The size of the button.</param>
	/// <param name="_v2fPosition:">The position of the button (center-aligned).</param>
	/// <param name="_eButtonType:">Determines what event to perform when clicked.</param>
	/// <param name="_bEnabled:">Allows for updating and rendering if true.</param>
	static void CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, bool _bEnabled);

	/// <summary>
	/// Creates a UI button element with text in the middle.
	/// </summary>
	/// <param name="_v2fSize:">The size of the button.</param>
	/// <param name="_v2fPosition:">The position of the button (center-aligned).</param>
	/// <param name="_eButtonType:">Determines what event to perform when clicked.</param>
	/// <param name="_sButtonText:">The text that is displayed on the button.</param>
	/// <param name="_bEnabled:">Allows for updating and rendering if true.</param>
	static void CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, std::string _sButtonText, bool _bEnabled);

	/// <summary>
	/// Creates a UI text element.
	/// </summary>
	/// <param name="_uiFontSize:">The font size of the text.</param>
	/// <param name="_v2fPosition:">The position of the text (center-aligned).</param>
	/// <param name="_sTextString:">The string of the text element.</param>
	/// <param name="_oColour:">The colour of the text element.</param>
	/// <param name="_bEnabled:">Allows for updating and rendering if true.</param>
	static void CreateText(unsigned int _uiFontSize, sf::Vector2f _v2fPosition, std::string _sTextString, sf::Color _oColour, bool _bEnabled);

	CUIManager() = delete;
	~CUIManager() = delete;
};