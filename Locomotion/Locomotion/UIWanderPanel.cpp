#include "UIWanderPanel.h"
#include "Utilities.h"

CUIWanderPanel::CUIWanderPanel(sf::Vector2f _v2fTopLeftPosition)
{
	////Offset position of the panel.
	//float fX = _v2fTopLeftPosition.x;
	//float fY = _v2fTopLeftPosition.y;

	//m_poSeekText = CreateText(20, { fX + 10, fY + 10 }, "Separation", sf::Color::White, EAlignment::TopLeft, true);
	//m_poWeightingText = CreateText(14, { fX + 90, fY + 40 }, "Weighting: 100%", sf::Color::White, EAlignment::TopLeft, true);
	//m_poStrengthText = CreateText(14, { fX + 90, fY + 75 }, "Strength: 100", sf::Color::White, EAlignment::TopLeft, true);
	//m_poMaxSteerForceText = CreateText(14, { fX + 90, fY + 110 }, "Max Steer Force: 100", sf::Color::White, EAlignment::TopLeft, true);

	//m_poDecrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 40 }, CUIButton::EButtonType::DecSeparationWeighting, EAlignment::TopLeft, 14, "-5%", true);
	//m_poIncrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 40 }, CUIButton::EButtonType::IncSeparationWeighting, EAlignment::TopLeft, 14, "+5%", true);
	//m_poDecrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 75 }, CUIButton::EButtonType::DecSeparationStrength, EAlignment::TopLeft, 14, "-1", true);
	//m_poIncrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 75 }, CUIButton::EButtonType::IncSeparationStrength, EAlignment::TopLeft, 14, "+1", true);
	//m_poDecrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 110 }, CUIButton::EButtonType::DecSeparationMSF, EAlignment::TopLeft, 14, "-1", true);
	//m_poIncrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 110 }, CUIButton::EButtonType::IncSeparationMSF, EAlignment::TopLeft, 14, "+1", true);

	m_bEnabled = false;
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