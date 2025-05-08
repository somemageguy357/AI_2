#include "UIArrivalPanel.h"
#include "Utilities.h"

CUIArrivalPanel::CUIArrivalPanel(sf::Vector2f _v2fTopLeftPosition)
{
	//Offset position of the panel.
	float fX = _v2fTopLeftPosition.x;
	float fY = _v2fTopLeftPosition.y;

	m_bEnabled = false;

	m_poArrivalText = CreateText(20, { fX + 10, fY + 10 }, "Arrival", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poWeightingText = CreateText(14, { fX + 90, fY + 40 }, "Weighting: 100%", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poMaxSteerForceText = CreateText(14, { fX + 90, fY + 75 }, "Max Steer Force: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poStoppingRadiusText = CreateText(14, { fX + 90, fY + 110 }, "Stopping Radius: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	//m_poStrengthText = CreateText(14, { fX + 90, fY + 75 }, "Strength: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);

	m_poDecrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 40 }, CUIButton::EButtonType::DecArrivalWeighting, EAlignment::TopLeft, 14, "-5%", m_bEnabled);
	m_poIncrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 40 }, CUIButton::EButtonType::IncArrivalWeighting, EAlignment::TopLeft, 14, "+5%", m_bEnabled);
	m_poDecrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 75 }, CUIButton::EButtonType::DecArrivalMSF, EAlignment::TopLeft, 14, "-1", m_bEnabled);
	m_poIncrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 75 }, CUIButton::EButtonType::IncArrivalMSF, EAlignment::TopLeft, 14, "+1", m_bEnabled);
	m_poDecrementStoppingRadiusBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 110 }, CUIButton::EButtonType::DecArrivalStoppingRadius, EAlignment::TopLeft, 14, "-5", m_bEnabled);
	m_poIncrementStoppingRadiusBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 110 }, CUIButton::EButtonType::IncArrivalStoppingRadius, EAlignment::TopLeft, 14, "+5", m_bEnabled);
	//m_poDecrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 75 }, CUIButton::EButtonType::n, EAlignment::TopLeft, 14, "-1", m_bEnabled);
	//m_poIncrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 75 }, CUIButton::EButtonType::n, EAlignment::TopLeft, 14, "+1", m_bEnabled);
}

CUIArrivalPanel::~CUIArrivalPanel() {}

void CUIArrivalPanel::SetWeightText(float _fValue)
{
	m_poWeightingText->SetString("Weighting: " + CUtilities::FloatToString(roundf(_fValue * 100), 0) + "%");
}

void CUIArrivalPanel::SetStoppingRadiusText(float _fValue)
{
	m_poStoppingRadiusText->SetString("Stopping Radius: " + CUtilities::FloatToString(_fValue, 0));
}

//void CUIArrivalPanel::SetStrengthText(float _fValue)
//{
//	m_poStrengthText->SetString("Strength: " + CUtilities::FloatToString(_fValue, 0));
//}

void CUIArrivalPanel::SetMaxSteerForceText(float _fValue)
{
	m_poMaxSteerForceText->SetString("Max Steer Force: " + CUtilities::FloatToString(_fValue, 0));
}