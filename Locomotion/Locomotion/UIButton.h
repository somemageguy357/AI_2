/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIButton.h
Description : A UI element that is displayed to the window and performs events when clicked.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include "UIText.h"

//A UI element that is displayed to the window and performs events when clicked.
class CUIButton
{
public:
	//The type of event to perform when the button is clicked.
	enum class EButtonType
	{
		AISeek,
		AIWander,
		AIArrival,
		AIFlock,
	};

	/// <summary>
	/// Creates a UI button element.
	/// </summary>
	/// <param name="_v2fSize:">The size of the button.</param>
	/// <param name="_v2fPosition:">The position of the button (center-aligned).</param>
	/// <param name="_eButtonType:">Determines what event to perform when clicked.</param>
	/// <param name="_bEnabled:">Allows for updating and rendering if true.</param>
	CUIButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, bool _bEnabled);

	/// <summary>
	/// Creates a UI button element with text in the middle.
	/// </summary>
	/// <param name="_v2fSize:">The size of the button.</param>
	/// <param name="_v2fPosition:">The position of the button (center-aligned).</param>
	/// <param name="_eButtonType:">Determines what event to perform when clicked.</param>
	/// <param name="_sButtonText:">The text that is displayed on the button.</param>
	/// <param name="_bEnabled:">Allows for updating and rendering if true.</param>
	CUIButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, std::string _sButtonText, bool _bEnabled);

	~CUIButton();

	/// <summary>
	/// If enabled: checks for mouse overlap and performs the button's OnClick() event if the mouse is overlapping
	/// the button and its left button is being clicked.
	/// </summary>
	/// <param name="_bIsClicking:">True if the left mouse button is down. Allows for the button's OnClick() event to be performed.</param>
	void Update(bool _bIsClicking);

	/// <summary>
	/// If enabled: renders the button and its text element (if it has one) to the render window.
	/// </summary>
	void Render();

	/// <summary>
	/// Enables/disables the button which determines if its Update() and Render() functions should perform.
	/// </summary>
	/// <param name="_bEnabled:">The new enabled state of the button.</param>
	void SetEnabled(bool _bEnabled);

private:
	bool m_bEnabled;

	sf::RectangleShape m_oButtonShape;

	CUIText* m_poButtonText = nullptr;

	EButtonType m_eButtonType;

	//Determines if the mouse is overlapping the button's bounds and calls OnClick() if the left mouse button is down.
	void CheckMouseOverlap(bool _bIsClicking);

	//Performs the click event of the button, determined by its EButtonType.
	void OnClick();

	//Sets up the buttons initial values. Called from the constructors.
	void SetupButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, bool _bEnabled);
};