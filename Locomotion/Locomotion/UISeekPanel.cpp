#include "UISeekPanel.h"
#include "Utilities.h"

CUISeekPanel::CUISeekPanel(sf::Vector2f _v2fTopLeftPosition)
{
	//Offset position of the panel.
	float fX = _v2fTopLeftPosition.x;
	float fY = _v2fTopLeftPosition.y;

	m_poSeekText = CreateText(20, { fX + 10, fY + 10 }, "Seek", sf::Color::White, EAlignment::TopLeft, true);
	m_poWeightingText = CreateText(14, { fX + 90, fY + 40 }, "Weighting: 100%", sf::Color::White, EAlignment::TopLeft, true);
	m_poStrengthText = CreateText(14, { fX + 90, fY + 75 }, "Strength: 100", sf::Color::White, EAlignment::TopLeft, true);
	m_poMaxSteerForceText = CreateText(14, { fX + 90, fY + 110 }, "Max Steer Force: 100", sf::Color::White, EAlignment::TopLeft, true);

	m_poDecrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 40 }, CUIButton::EButtonType::DecSeekWeighting, EAlignment::TopLeft, 14, "-5%", true);
	m_poIncrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 40 }, CUIButton::EButtonType::IncSeekWeighting, EAlignment::TopLeft, 14, "+5%", true);
	m_poDecrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 75 }, CUIButton::EButtonType::DecSeekStrength, EAlignment::TopLeft, 14, "-1", true);
	m_poIncrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 75 }, CUIButton::EButtonType::IncSeekStrength, EAlignment::TopLeft, 14, "+1", true);
	m_poDecrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 110 }, CUIButton::EButtonType::DecSeekMSF, EAlignment::TopLeft, 14, "-1", true);
	m_poIncrementMaxSteerForceBtn = CreateButton({ 30, 20 }, {fX + 50, fY + 110}, CUIButton::EButtonType::IncSeekMSF, EAlignment::TopLeft, 14, "+1", true);

	m_bEnabled = false;
}

CUISeekPanel::~CUISeekPanel() {}

void CUISeekPanel::SetWeightText(float _fValue)
{
	m_poWeightingText->SetString("Weighting: " + CUtilities::FloatToString(roundf(_fValue * 100), 0) + "%");
}

void CUISeekPanel::SetStrengthText(float _fValue)
{
	m_poStrengthText->SetString("Strength: " + CUtilities::FloatToString(_fValue, 0));
}

void CUISeekPanel::SetMaxSteerForceText(float _fValue)
{
	m_poMaxSteerForceText->SetString("Max Steer Force: " + CUtilities::FloatToString(_fValue, 0));
}