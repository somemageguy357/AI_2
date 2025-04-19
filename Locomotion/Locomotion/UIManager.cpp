/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIManager.cpp
Description : Contains function definitions for UIManager.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "UIManager.h"

std::vector<CUIElement*> CUIManager::m_oVecUIElementPtrs;
std::vector<CUIButton*> CUIManager::m_oVecButtonPtrs;

sf::Font* CUIManager::m_poUIFont = nullptr;

CUISeekPanel* CUIManager::m_poSeekPanel = nullptr;

void CUIManager::Update(bool _bIsClicking)
{
	for (size_t i = 0; i < m_oVecUIElementPtrs.size(); i++)
	{
		m_oVecUIElementPtrs[i]->Update();
	}

	for (size_t i = 0; i < m_oVecButtonPtrs.size(); i++)
	{
		m_oVecButtonPtrs[i]->CheckMouseOverlap(_bIsClicking);
	}

}

void CUIManager::Render()
{
	for (size_t i = 0; i < m_oVecUIElementPtrs.size(); i++)
	{
		m_oVecUIElementPtrs[i]->Render();
	}
}

void CUIManager::InitUI()
{
	m_poUIFont = new sf::Font();
	m_poUIFont->loadFromFile("Fonts/Roboto-Light.ttf");

	CreateText(20, { 60, 20 }, "Behaviours", sf::Color::White, CUIElement::EAlignment::CenterMiddle, true);
	CreateButton({ 100, 30 }, { 10, 50 }, CUIButton::EButtonType::AIArrival, CUIElement::EAlignment::TopLeft, 20, "Arrival", true);
	CreateButton({ 100, 30 }, { 10, 90 }, CUIButton::EButtonType::AIFlock, CUIElement::EAlignment::TopLeft, 20, "Flock", true);
	CreateButton({ 100, 30 }, { 10, 130 }, CUIButton::EButtonType::AISeek, CUIElement::EAlignment::TopLeft, 20, "Seek", true);
	CreateButton({ 100, 30 }, { 10, 170 }, CUIButton::EButtonType::AIWander, CUIElement::EAlignment::TopLeft, 20, "Wander", true);
	CreateButton({ 100, 30 }, { 10, 210 }, CUIButton::EButtonType::n, CUIElement::EAlignment::TopLeft, 20, "NULL", true);
	CreateButton({ 100, 30 }, { 10, 250 }, CUIButton::EButtonType::n, CUIElement::EAlignment::TopLeft, 20, "NULL", true);

	CreateText(20, { 60, 320 }, "Gizmos", sf::Color::White, CUIElement::EAlignment::CenterMiddle, true);
	CreateButton({ 100, 30 }, { 10, 350 }, CUIButton::EButtonType::ToggleGizmos, CUIElement::EAlignment::TopLeft, 20, "Enable", true);

	m_poSeekPanel = new CUISeekPanel({ 0.0f, 510.0f });
	m_poSeekPanel->SetEnabled(true);
	m_oVecUIElementPtrs.push_back(m_poSeekPanel);

	//CreateText(20, { 10, 520 }, "Seek", sf::Color::White, CUIElement::EAlignment::TopLeft, true);
	//CreateText(14, { 90, 550 }, "Weighting: 100%", sf::Color::White, CUIElement::EAlignment::TopLeft, true);
	//CreateText(14, { 90, 585 }, "Strength: 100", sf::Color::White, CUIElement::EAlignment::TopLeft, true);
	//CreateText(14, { 90, 620 }, "Max Steer Force: 100", sf::Color::White, CUIElement::EAlignment::TopLeft, true);
	//CreateText(14, { 90, 655 }, "Neighbourhood Radius: 100", sf::Color::White, CUIElement::EAlignment::TopLeft, true);
	//CreateText(14, { 90, 690 }, "Neighbourhood Radius: 100", sf::Color::White, CUIElement::EAlignment::TopLeft, true);
	//CreateButton({ 30, 20 }, { 10, 550 }, CUIButton::EButtonType::n, CUIElement::EAlignment::TopLeft, 14, "-5%", true);
	//CreateButton({ 30, 20 }, { 50, 550 }, CUIButton::EButtonType::n, CUIElement::EAlignment::TopLeft, 14, "+5%", true);
	//CreateButton({ 30, 20 }, { 10, 585 }, CUIButton::EButtonType::n, CUIElement::EAlignment::TopLeft, 14, "-1", true);
	//CreateButton({ 30, 20 }, { 50, 585 }, CUIButton::EButtonType::n, CUIElement::EAlignment::TopLeft, 14, "+1", true);
	//CreateButton({ 30, 20 }, { 10, 620 }, CUIButton::EButtonType::n, CUIElement::EAlignment::TopLeft, 14, "-1", true);
	//CreateButton({ 30, 20 }, { 50, 620 }, CUIButton::EButtonType::n, CUIElement::EAlignment::TopLeft, 14, "+1", true);
	//CreateButton({ 30, 20 }, { 10, 655 }, CUIButton::EButtonType::n, CUIElement::EAlignment::TopLeft, 14, "-1", true);
	//CreateButton({ 30, 20 }, { 50, 655 }, CUIButton::EButtonType::n, CUIElement::EAlignment::TopLeft, 14, "+1", true);
	//CreateButton({ 30, 20 }, { 10, 690 }, CUIButton::EButtonType::n, CUIElement::EAlignment::TopLeft, 14, "-1", true);
	//CreateButton({ 30, 20 }, { 50, 690 }, CUIButton::EButtonType::n, CUIElement::EAlignment::TopLeft, 14, "+1", true);
}

sf::Font* CUIManager::GetUIFont()
{
	return m_poUIFont;
}

void CUIManager::AddToButtonVector(CUIButton* _poButton)
{
	m_oVecButtonPtrs.push_back(_poButton);
}

void CUIManager::RemoveFromButtonVector(CUIButton* _poButton)
{
	for (size_t i = 0; i < m_oVecButtonPtrs.size(); i++)
	{
		if (m_oVecButtonPtrs[i] == _poButton)
		{
			m_oVecButtonPtrs.erase(m_oVecButtonPtrs.begin() + i);
			break;
		}
	}
}

CUISeekPanel* CUIManager::GetSeekPanel()
{
	return m_poSeekPanel;
}

void CUIManager::Destroy()
{
	for (size_t i = 0; i < m_oVecUIElementPtrs.size(); i++)
	{
		delete m_oVecUIElementPtrs[i];
	}

	delete m_poUIFont;
}

void CUIManager::CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, CUIElement::EAlignment _eAlignment, bool _bEnabled)
{
	CUIButton* poButton = new CUIButton(_v2fSize, _v2fPosition, _eButtonType, _eAlignment, _bEnabled);
	m_oVecUIElementPtrs.push_back(poButton);
}

void CUIManager::CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, CUIElement::EAlignment _eAlignment, unsigned int _uiFontSize, std::string _sButtonText, bool _bEnabled)
{
	CUIButton* poButton = new CUIButton(_v2fSize, _v2fPosition, _eButtonType, _eAlignment, _uiFontSize, _sButtonText, _bEnabled);
	m_oVecUIElementPtrs.push_back(poButton);
}

void CUIManager::CreateText(unsigned int _uiFontSize, sf::Vector2f _v2fPosition, std::string _sTextString, sf::Color _oColour, CUIElement::EAlignment _eAlignment, bool _bEnabled)
{
	CUIText* poText = new CUIText(_uiFontSize, _v2fPosition, _sTextString, _oColour, _eAlignment, _bEnabled);
	m_oVecUIElementPtrs.push_back(poText);
}