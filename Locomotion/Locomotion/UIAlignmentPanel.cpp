#include "UIAlignmentPanel.h"
#include "Utilities.h"

CUIAlignmentPanel::CUIAlignmentPanel(sf::Vector2f _v2fTopLeftPosition)
{
	float fX = _v2fTopLeftPosition.x;
	float fY = _v2fTopLeftPosition.y;

	m_bEnabled = false;

	m_poAlignmentText = CreateText(20, { fX + 10, fY + 10 }, "Alignment", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poWeightingText = CreateText(14, { fX + 90, fY + 40 }, "Weighting: 100%", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poStrengthText = CreateText(14, { fX + 90, fY + 75 }, "Strength: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poMaxSteerForceText = CreateText(14, { fX + 90, fY + 110 }, "Max Steer Force: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poNeighbourhoodRadiusText = CreateText(14, { fX + 90, fY + 145 }, "Neighbourhood Radius: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);

	m_poDecrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 40 }, CUIButton::EButtonType::DecAlignmentWeighting, EAlignment::TopLeft, 14, "-5%", m_bEnabled);
	m_poIncrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 40 }, CUIButton::EButtonType::IncAlignmentWeighting, EAlignment::TopLeft, 14, "+5%", m_bEnabled);
	m_poDecrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 75 }, CUIButton::EButtonType::DecAlignmentStrength, EAlignment::TopLeft, 14, "-1", m_bEnabled);
	m_poIncrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 75 }, CUIButton::EButtonType::IncAlignmentStrength, EAlignment::TopLeft, 14, "+1", m_bEnabled);
	m_poDecrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 110 }, CUIButton::EButtonType::DecAlignmentMSF, EAlignment::TopLeft, 14, "-1", m_bEnabled);
	m_poIncrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 110 }, CUIButton::EButtonType::IncAlignmentMSF, EAlignment::TopLeft, 14, "+1", m_bEnabled);
	m_poDecNeighbourhoodRadiusBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 145 }, CUIButton::EButtonType::DecAlignmentNHR, EAlignment::TopLeft, 14, "-5", m_bEnabled);
	m_poIncNeighbourhoodRadiusBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 145 }, CUIButton::EButtonType::IncAlignmentNHR, EAlignment::TopLeft, 14, "+5", m_bEnabled);
}

CUIAlignmentPanel::~CUIAlignmentPanel() {}

void CUIAlignmentPanel::SetWeightText(float _fValue)
{
	m_poWeightingText->SetString("Weighting: " + CUtilities::FloatToString(roundf(_fValue * 100), 0) + "%");
}

void CUIAlignmentPanel::SetStrengthText(float _fValue)
{
	m_poStrengthText->SetString("Strength: " + CUtilities::FloatToString(_fValue, 0));
}

void CUIAlignmentPanel::SetMaxSteerForceText(float _fValue)
{
	m_poMaxSteerForceText->SetString("Max Steer Force: " + CUtilities::FloatToString(_fValue, 0));
}

void CUIAlignmentPanel::SetNeighbourhoodRadiusText(float _fValue)
{
	m_poNeighbourhoodRadiusText->SetString("Neighbourhood Radius: " + CUtilities::FloatToString(_fValue, 0));
}