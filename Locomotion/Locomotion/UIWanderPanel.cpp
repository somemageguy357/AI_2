/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIWanderPanel.cpp
Description : Contains function definitions for UIWanderPanel.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "UIWanderPanel.h"
#include "Utilities.h"

CUIWanderPanel::CUIWanderPanel(sf::Vector2f _v2fTopLeftPosition)
{
	//Offset position of the panel.
	float fX = _v2fTopLeftPosition.x;
	float fY = _v2fTopLeftPosition.y;

	m_bEnabled = false;

	m_poSeekText = CreateText(20, { fX + 10, fY + 10 }, "Wander", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poWeightingText = CreateText(14, { fX + 90, fY + 40 }, "Weighting: 100%", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poStrengthText = CreateText(14, { fX + 90, fY + 75 }, "Strength: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poMaxSteerForceText = CreateText(14, { fX + 90, fY + 110 }, "Max Steer Force: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poRadiusText = CreateText(14, { fX + 90, fY + 145 }, "Wander Radius: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poDistanceText = CreateText(14, { fX + 90, fY + 180 }, "Wander Distance: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);

	m_poDecrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 40 }, CUIButton::EButtonType::DecWanderWeighting, EAlignment::TopLeft, 14, "-5%", m_bEnabled);
	m_poIncrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 40 }, CUIButton::EButtonType::IncWanderWeighting, EAlignment::TopLeft, 14, "+5%", m_bEnabled);
	m_poDecrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 75 }, CUIButton::EButtonType::DecWanderStrength, EAlignment::TopLeft, 14, "-1", m_bEnabled);
	m_poIncrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 75 }, CUIButton::EButtonType::IncWanderStrength, EAlignment::TopLeft, 14, "+1", m_bEnabled);
	m_poDecrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 110 }, CUIButton::EButtonType::DecWanderMSF, EAlignment::TopLeft, 14, "-1", m_bEnabled);
	m_poIncrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 110 }, CUIButton::EButtonType::IncWanderMSF, EAlignment::TopLeft, 14, "+1", m_bEnabled);
	m_poDecrementRadiusBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 145 }, CUIButton::EButtonType::DecWanderRadius, EAlignment::TopLeft, 14, "-5", m_bEnabled);
	m_poIncrementRadiusBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 145 }, CUIButton::EButtonType::IncWanderRadius, EAlignment::TopLeft, 14, "+5", m_bEnabled);
	m_poDecrementDistanceBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 180 }, CUIButton::EButtonType::DecWanderDistance, EAlignment::TopLeft, 14, "-1", m_bEnabled);
	m_poIncrementDistanceBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 180 }, CUIButton::EButtonType::IncWanderDistance, EAlignment::TopLeft, 14, "+1", m_bEnabled);
}

CUIWanderPanel::~CUIWanderPanel() {}

void CUIWanderPanel::SetWeightText(float _fValue)
{
	m_poWeightingText->SetString("Weighting: " + CUtilities::FloatToString(roundf(_fValue * 100), 0) + "%");
}

void CUIWanderPanel::SetStrengthText(float _fValue)
{
	m_poStrengthText->SetString("Strength: " + CUtilities::FloatToString(_fValue, 0));
}

void CUIWanderPanel::SetMaxSteerForceText(float _fValue)
{
	m_poMaxSteerForceText->SetString("Max Steer Force: " + CUtilities::FloatToString(_fValue, 0));
}

void CUIWanderPanel::SetRadiusText(float _fValue)
{
	m_poRadiusText->SetString("Wander Radius: " + CUtilities::FloatToString(_fValue, 0));
}

void CUIWanderPanel::SetDistanceText(float _fValue)
{
	m_poDistanceText->SetString("Wander Distance: " + CUtilities::FloatToString(_fValue, 0));
}