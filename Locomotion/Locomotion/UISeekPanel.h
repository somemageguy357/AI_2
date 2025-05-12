/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UISeekPanel.h
Description : Inheriting from UIPanel, contains UI buttons and text elements associated with the seek agent behaviour.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "UIPanel.h"

class CUISeekPanel : public CUIPanel
{
public:
	/// <summary>
	/// Creates a panel and setups up all text and button UI elements.
	/// </summary>
	/// <param name="_v2fTopLeftPosition:">The top-left anchor position of the panel in window space.</param>
	CUISeekPanel(sf::Vector2f _v2fTopLeftPosition);

	~CUISeekPanel();

	/// <summary>
	/// Sets the string for the Weight text to display the given value.
	/// </summary>
	/// <param name="_fValue:">The value to display.</param>
	void SetWeightText(float _fValue);

	/// <summary>
	/// Sets the string for the Strength text to display the given value.
	/// </summary>
	/// <param name="_fValue:">The value to display.</param>
	void SetStrengthText(float _fValue);

	/// <summary>
	/// Sets the string for the Max Steer Force text to display the given value.
	/// </summary>
	/// <param name="_fValue:">The value to display.</param>
	void SetMaxSteerForceText(float _fValue);

private:
	CUIButton* m_poDecrementWeightingBtn = nullptr;
	CUIButton* m_poIncrementWeightingBtn = nullptr;
	CUIButton* m_poDecrementStrengthBtn = nullptr;
	CUIButton* m_poIncrementStrengthBtn = nullptr;
	CUIButton* m_poDecrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poIncrementMaxSteerForceBtn = nullptr;

	CUIText* m_poSeekText = nullptr;
	CUIText* m_poWeightingText = nullptr;
	CUIText* m_poStrengthText = nullptr;
	CUIText* m_poMaxSteerForceText = nullptr;
};