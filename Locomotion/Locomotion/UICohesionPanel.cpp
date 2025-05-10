#include "UICohesionPanel.h"
#include "Utilities.h"

CUICohesionPanel::CUICohesionPanel(sf::Vector2f _v2fTopLeftPosition)
{
	float fX = _v2fTopLeftPosition.x;
	float fY = _v2fTopLeftPosition.y;

	m_bEnabled = false;

	m_poCohesionText = CreateText(20, { fX + 10, fY + 10 }, "Cohesion", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poWeightingText = CreateText(14, { fX + 90, fY + 40 }, "Weighting: 100%", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poStrengthText = CreateText(14, { fX + 90, fY + 75 }, "Strength: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poMaxSteerForceText = CreateText(14, { fX + 90, fY + 110 }, "Max Steer Force: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poNeighbourhoodRadiusText = CreateText(14, { fX + 90, fY + 145 }, "Neighbourhood Radius: 100", sf::Color::White, EAlignment::TopLeft, m_bEnabled);
	m_poIncludeSelfText = CreateText(14, { fX + 90, fY + 180 }, "Include Self: m_bEnabled", sf::Color::White, EAlignment::TopLeft, m_bEnabled);

	m_poDecrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 40 }, CUIButton::EButtonType::DecCohesionWeighting, EAlignment::TopLeft, 14, "-5%", m_bEnabled);
	m_poIncrementWeightingBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 40 }, CUIButton::EButtonType::IncCohesionWeighting, EAlignment::TopLeft, 14, "+5%", m_bEnabled);
	m_poDecrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 75 }, CUIButton::EButtonType::DecCohesionStrength, EAlignment::TopLeft, 14, "-1", m_bEnabled);
	m_poIncrementStrengthBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 75 }, CUIButton::EButtonType::IncCohesionStrength, EAlignment::TopLeft, 14, "+1", m_bEnabled);
	m_poDecrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 110 }, CUIButton::EButtonType::DecCohesionMSF, EAlignment::TopLeft, 14, "-1", m_bEnabled);
	m_poIncrementMaxSteerForceBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 110 }, CUIButton::EButtonType::IncCohesionMSF, EAlignment::TopLeft, 14, "+1", m_bEnabled);
	m_poDecNeighbourhoodRadiusBtn = CreateButton({ 30, 20 }, { fX + 10, fY + 145 }, CUIButton::EButtonType::DecCohesionNHR, EAlignment::TopLeft, 14, "-5", m_bEnabled);
	m_poIncNeighbourhoodRadiusBtn = CreateButton({ 30, 20 }, { fX + 50, fY + 145 }, CUIButton::EButtonType::IncCohesionNHR, EAlignment::TopLeft, 14, "+5", m_bEnabled);
	m_poToggleIncludeSelfBtn = CreateButton({ 70, 20 }, { fX + 10, fY + 180 }, CUIButton::EButtonType::ToggleCohesionIncludeSelf, EAlignment::TopLeft, 14, "Toggle", m_bEnabled);
}

CUICohesionPanel::~CUICohesionPanel() {}

void CUICohesionPanel::SetWeightText(float _fValue)
{
	m_poWeightingText->SetString("Weighting: " + CUtilities::FloatToString(roundf(_fValue * 100), 0) + "%");
}

void CUICohesionPanel::SetStrengthText(float _fValue)
{
	m_poStrengthText->SetString("Strength: " + CUtilities::FloatToString(_fValue, 0));
}

void CUICohesionPanel::SetMaxSteerForceText(float _fValue)
{
	m_poMaxSteerForceText->SetString("Max Steer Force: " + CUtilities::FloatToString(_fValue, 0));
}

void CUICohesionPanel::SetNeighbourhoodRadiusText(float _fValue)
{
	m_poNeighbourhoodRadiusText->SetString("Neighbourhood Radius: " + CUtilities::FloatToString(_fValue, 0));
}

void CUICohesionPanel::SetIncludeSelfText(bool _bValue)
{
	std::string sValue = "True";

	if (_bValue == false)
	{
		sValue = "False";
	}

	m_poIncludeSelfText->SetString("Include Self: " + sValue);
}