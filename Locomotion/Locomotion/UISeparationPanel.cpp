#include "UISeparationPanel.h"
#include "Utilities.h"

CUISeparationPanel::CUISeparationPanel(sf::Vector2f _v2fTopLeftPosition)
{
	float fX = _v2fTopLeftPosition.x;
	float fY = _v2fTopLeftPosition.y;

	m_bEnabled = false;

	m_poSeparationText = CreateText(20, { fX + 10, fY + 10 }, "Separation", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poWeightingText = CreateText(14, { fX + 90, fY + 40 }, "Weighting: 100%", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poStrengthText = CreateText(14, { fX + 90, fY + 75 }, "Strength: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poMaxSteerForceText = CreateText(14, { fX + 90, fY + 110 }, "Max Steer Force: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poNeighbourhoodRadiusText = CreateText(14, { fX + 90, fY + 145 }, "Neighbourhood Radius: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);

	m_poDecrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 40 }, CUIButton::EButtonType::DecSeparationWeighting, EAlignment::TopLeft, 14, "-5%", m_bEnabled);
	m_poIncrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 40 }, CUIButton::EButtonType::IncSeparationWeighting, EAlignment::TopLeft, 14, "+5%", m_bEnabled);
	m_poDecrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 75 }, CUIButton::EButtonType::DecSeparationStrength, EAlignment::TopLeft, 14, "-1", m_bEnabled);
	m_poIncrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 75 }, CUIButton::EButtonType::IncSeparationStrength, EAlignment::TopLeft, 14, "+1", m_bEnabled);
	m_poDecrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 110 }, CUIButton::EButtonType::DecSeparationMSF, EAlignment::TopLeft, 14, "-1", m_bEnabled);
	m_poIncrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 110 }, CUIButton::EButtonType::IncSeparationMSF, EAlignment::TopLeft, 14, "+1", m_bEnabled);
	m_poDecNeighbourhoodRadiusBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 145 }, CUIButton::EButtonType::DecSeparationNHR, EAlignment::TopLeft, 14, "-5", m_bEnabled);
	m_poIncNeighbourhoodRadiusBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 145 }, CUIButton::EButtonType::IncSeparationNHR, EAlignment::TopLeft, 14, "+5", m_bEnabled);
}

CUISeparationPanel::~CUISeparationPanel() {}

void CUISeparationPanel::SetWeightText(float _fValue)
{
	m_poWeightingText->SetString("Weighting: " + CUtilities::FloatToString(roundf(_fValue * 100), 0) + "%");
}

void CUISeparationPanel::SetStrengthText(float _fValue)
{
	m_poStrengthText->SetString("Strength: " + CUtilities::FloatToString(_fValue, 0));
}

void CUISeparationPanel::SetMaxSteerForceText(float _fValue)
{
	m_poMaxSteerForceText->SetString("Max Steer Force: " + CUtilities::FloatToString(_fValue, 0));
}

void CUISeparationPanel::SetNeighbourhoodRadiusText(float _fValue)
{
	m_poNeighbourhoodRadiusText->SetString("Neighbourhood Radius: " + CUtilities::FloatToString(_fValue, 0));
}