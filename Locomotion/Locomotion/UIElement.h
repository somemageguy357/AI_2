/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIElement.h
Description : Base class for all UI elements.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "SFML/Graphics.hpp"

class CUIElement
{
public:
	enum class EAlignment
	{
		TopLeft,
		TopMiddle,
		TopRight,
		CenterLeft,
		CenterMiddle,
		CenterRight,
		BottomLeft,
		BottomMiddle,
		BottomRight
	};

	~CUIElement() {};

	virtual void Update() = 0;

	virtual void Render() = 0;

	virtual void SetAlignment(EAlignment _eAlignment) = 0;

	/// <summary>
	/// Returns the anchor alignment value of the element.
	/// </summary>
	/// <returns>The anchor alignment value of the element.</returns>
	EAlignment GetAlignment();

	/// <summary>
	/// Enables/disables the button which determines if its Update() and Render() functions should perform.
	/// </summary>
	/// <param name="_bEnabled:">The new enabled state of the button.</param>
	virtual void SetEnabled(bool _bEnabled);

	/// <summary>
	/// Returns the enabled state of the element.
	/// </summary>
	/// <returns>The enabled state of the element.</returns>
	bool GetEnabled();

protected:
	bool m_bEnabled = true;

	EAlignment m_eAlignment = EAlignment::CenterMiddle;

	CUIElement() {};

	void SetElementAlignment(sf::RectangleShape* _poShape, EAlignment _eAlignment, sf::Vector2f _v2fPosition);

	void SetElementAlignment(sf::Text* _poText, EAlignment _eAlignment, sf::Vector2f _v2fPosition);
};