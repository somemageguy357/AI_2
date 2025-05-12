/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UISeparationPanel.h
Description : Inheriting from UIPanel, contains UI buttons and text elements associated with the separation agent behaviour.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "UIPanel.h"

class CUISeparationPanel : public CUIPanel
{
public:
	/// <summary>
	/// Creates a panel and setups up all text and button UI elements.
	/// </summary>
	/// <param name="_v2fTopLeftPosition:">The top-left anchor position of the panel in window space.</param>
	CUISeparationPanel(sf::Vector2f _v2fTopLeftPosition);

	~CUISeparationPanel();

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

	/// <summary>
	/// Sets the string for the Neighbourhood Radius text to display the given value.
	/// </summary>
	/// <param name="_fValue:">The value to display.</param>
	void SetNeighbourhoodRadiusText(float _fValue);

private:
	CUIButton* m_poDecrementWeightingBtn = nullptr;
	CUIButton* m_poIncrementWeightingBtn = nullptr;
	CUIButton* m_poDecrementStrengthBtn = nullptr;
	CUIButton* m_poIncrementStrengthBtn = nullptr;
	CUIButton* m_poDecrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poIncrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poDecNeighbourhoodRadiusBtn = nullptr;
	CUIButton* m_poIncNeighbourhoodRadiusBtn = nullptr;

	CUIText* m_poSeparationText = nullptr;
	CUIText* m_poWeightingText = nullptr;
	CUIText* m_poStrengthText = nullptr;
	CUIText* m_poMaxSteerForceText = nullptr;
	CUIText* m_poNeighbourhoodRadiusText = nullptr;
};