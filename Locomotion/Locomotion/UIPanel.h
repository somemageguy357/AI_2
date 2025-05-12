/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIPanel.h
Description : Base class for all UI panels. Contains any buttons and text elements that a panel may create.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include "UIButton.h"

class CUIPanel : public CUIElement
{
public:
	~CUIPanel();

	/// <summary>
	/// Calls Update for all existing button and text elements in the panel.
	/// </summary>
	void Update() override;

	/// <summary>
	/// Calls Render for all existing button and text elements in the panel.
	/// </summary>
	void Render() override;

	/// <summary>
	/// Sets the enabled state of the panel. Also sets the enabled state of all button and text elements that exist in the panel.
	/// </summary>
	/// <param name="_bEnabled:">The new enabled state.</param>
	void SetEnabled(bool _bEnabled) override;

	/// <summary>
	/// 'Repositions' the panel by repositioning all button and text elements that exist in the panel.
	/// </summary>
	/// <param name="_fXOffset:">The x-coordinate offset for the panel.</param>
	void RepositionPanel(float _fXOffset);

	/// <summary>
	/// Resers the positions of all button and text elements that exist in the panel to their creation-time values.
	/// </summary>
	void ResetPosition();

protected:
	CUIPanel() {};

	CUIButton* CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, CUIElement::EAlignment _eAlignment, bool _bEnabled);

	CUIButton* CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, CUIElement::EAlignment _eAlignment, unsigned int _uiFontSize, std::string _sButtonText, bool _bEnabled);

	CUIText* CreateText(unsigned int _uiFontSize, sf::Vector2f _v2fPosition, std::string _sTextString, sf::Color _oColour, CUIElement::EAlignment _eAlignment, bool _bEnabled);

private:
	std::vector<CUIButton*> m_oVecButtonPtrs;
	std::vector<CUIText*> m_oVecTextPtrs;

	float m_fXOffset = 0.0f;

	void SetAlignment(EAlignment _eAlignment) override {};
};