/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UICohesionPanel.h
Description : Inheriting from UIPanel, contains UI buttons and text elements associated with the cohesion agent behaviour.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "UIPanel.h"

class CUICohesionPanel : public CUIPanel
{
public:
	/// <summary>
	/// Creates a panel and setups up all text and button UI elements.
	/// </summary>
	/// <param name="_v2fTopLeftPosition:">The top-left anchor position of the panel in window space.</param>
	CUICohesionPanel(sf::Vector2f _v2fTopLeftPosition);

	~CUICohesionPanel();

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

	/// <summary>
	/// Sets the string for the Include Self text to display the given value.
	/// </summary>
	/// <param name="_fValue:">The value to display.</param>
	void SetIncludeSelfText(bool _bValue);

private:
	CUIButton* m_poDecrementWeightingBtn = nullptr;
	CUIButton* m_poIncrementWeightingBtn = nullptr;
	CUIButton* m_poDecrementStrengthBtn = nullptr;
	CUIButton* m_poIncrementStrengthBtn = nullptr;
	CUIButton* m_poDecrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poIncrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poDecNeighbourhoodRadiusBtn = nullptr;
	CUIButton* m_poIncNeighbourhoodRadiusBtn = nullptr;
	CUIButton* m_poToggleIncludeSelfBtn = nullptr;

	CUIText* m_poCohesionText = nullptr;
	CUIText* m_poWeightingText = nullptr;
	CUIText* m_poStrengthText = nullptr;
	CUIText* m_poMaxSteerForceText = nullptr;
	CUIText* m_poNeighbourhoodRadiusText = nullptr;
	CUIText* m_poIncludeSelfText = nullptr;
};