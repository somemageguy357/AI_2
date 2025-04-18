/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIText.h
Description : A UI element that displays text to the window.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>

//A UI element that displays text to the window.
class CUIText
{
public:
	CUIText() = delete;

	/// <summary>
	/// Creates a UI text element.
	/// </summary>
	/// <param name="_uiFontSize:">The font size of the text.</param>
	/// <param name="_v2fPosition:">The position of the text (center-aligned).</param>
	/// <param name="_sTextString:">The string of the text element.</param>
	/// <param name="_oColour:">The colour of the text element.</param>
	/// <param name="_bEnabled:">Allows for updating and rendering if true.</param>
	CUIText(unsigned int _uiFontSize, sf::Vector2f _v2fPosition, std::string _sTextString, sf::Color _oColour, bool _bEnabled);

	~CUIText();

	/// <summary>
	/// -----CURRENTLY UNUSED-----
	/// </summary>
	void Update();

	/// <summary>
	/// If enabled: renders the text element to the render window.
	/// </summary>
	void Render();

	/// <summary>
	/// Enables/disables the button which determines if its Update() and Render() functions should perform.
	/// </summary>
	/// <param name="_bEnabled:">The new enabled state of the text.</param>
	void SetEnabled(bool _bEnabled);

	/// <summary>
	/// Sets the string of the text to the given value.
	/// </summary>
	/// <param name="_sTextString:">The new value for the text element.</param>
	void SetString(std::string _sTextString);

private:
	sf::Text m_oText;

	bool m_bEnabled = true;
};