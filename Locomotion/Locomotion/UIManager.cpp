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

	CreateText(20, { 60, 20 }, "Behaviours", sf::Color::White, true);
	CreateButton({ 100, 30 }, { 60, 60 }, CUIButton::EButtonType::AIArrival, "Arrival", true);
	CreateButton({ 100, 30 }, { 60, 100 }, CUIButton::EButtonType::AIFlock, "Flock", true);
	CreateButton({ 100, 30 }, { 60, 140 }, CUIButton::EButtonType::AISeek, "Seek", true);
	CreateButton({ 100, 30 }, { 60, 180 }, CUIButton::EButtonType::AIWander, "Wander", true);
	CreateButton({ 100, 30 }, { 60, 220 }, CUIButton::EButtonType::n, "NULL", true);
	CreateButton({ 100, 30 }, { 60, 260 }, CUIButton::EButtonType::n, "NULL", true);

	CreateText(20, { 60, 320 }, "Gizmos", sf::Color::White, true);
	CreateButton({ 100, 30 }, { 60, 360 }, CUIButton::EButtonType::ToggleGizmos, "Enable", true);
}

sf::Font* CUIManager::GetUIFont()
{
	return m_poUIFont;
}

void CUIManager::Destroy()
{
	for (size_t i = 0; i < m_oVecUIElementPtrs.size(); i++)
	{
		delete m_oVecUIElementPtrs[i];
	}

	delete m_poUIFont;
}

void CUIManager::CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, bool _bEnabled)
{
	CUIButton* poButton = new CUIButton(_v2fSize, _v2fPosition, _eButtonType, _bEnabled);
	m_oVecButtonPtrs.push_back(poButton);
	m_oVecUIElementPtrs.push_back(poButton);
}

void CUIManager::CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, std::string _sButtonText, bool _bEnabled)
{
	CUIButton* poButton = new CUIButton(_v2fSize, _v2fPosition, _eButtonType, _sButtonText, _bEnabled);
	m_oVecButtonPtrs.push_back(poButton);
	m_oVecUIElementPtrs.push_back(poButton);
}

void CUIManager::CreateText(unsigned int _uiFontSize, sf::Vector2f _v2fPosition, std::string _sTextString, sf::Color _oColour, bool _bEnabled)
{
	CUIText* poText = new CUIText(_uiFontSize, _v2fPosition, _sTextString, _oColour, _bEnabled);
	m_oVecUIElementPtrs.push_back(poText);
}