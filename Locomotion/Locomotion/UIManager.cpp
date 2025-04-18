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

std::vector<CUIButton*> CUIManager::m_oVecButtonPtrs;
std::vector<CUIText*> CUIManager::m_oVecTextPtrs;
sf::Font* CUIManager::m_poUIFont = nullptr;

void CUIManager::Update(bool _bIsClicking)
{
	for (size_t i = 0; i < m_oVecButtonPtrs.size(); i++)
	{
		m_oVecButtonPtrs[i]->Update(_bIsClicking);
	}

	for (size_t i = 0; i < m_oVecTextPtrs.size(); i++)
	{
		m_oVecTextPtrs[i]->Update();
	}
}

void CUIManager::Render()
{
	for (size_t i = 0; i < m_oVecButtonPtrs.size(); i++)
	{
		m_oVecButtonPtrs[i]->Render();
	}

	for (size_t i = 0; i < m_oVecTextPtrs.size(); i++)
	{
		m_oVecTextPtrs[i]->Render();
	}
}

void CUIManager::InitUI()
{
	m_poUIFont = new sf::Font();
	m_poUIFont->loadFromFile("Fonts/Roboto-Light.ttf");

	CreateButton({ 100, 30 }, { 60, 25 }, CUIButton::EButtonType::AIArrival, "Arrival", true);
	CreateButton({ 100, 30 }, { 60, 65 }, CUIButton::EButtonType::AIFlock, "Flock", true);
	CreateButton({ 100, 30 }, { 60, 105 }, CUIButton::EButtonType::AISeek, "Seek", true);
	CreateButton({ 100, 30 }, { 60, 145 }, CUIButton::EButtonType::AIWander, "Wander", true);
}

sf::Font* CUIManager::GetUIFont()
{
	return m_poUIFont;
}

void CUIManager::Destroy()
{
	for (size_t i = 0; i < m_oVecButtonPtrs.size(); i++)
	{
		delete m_oVecButtonPtrs[i];
	}

	for (size_t i = 0; i < m_oVecTextPtrs.size(); i++)
	{
		delete m_oVecTextPtrs[i];
	}

	delete m_poUIFont;
}

void CUIManager::CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, bool _bEnabled)
{
	CUIButton* poButton = new CUIButton(_v2fSize, _v2fPosition, _eButtonType, _bEnabled);
	m_oVecButtonPtrs.push_back(poButton);
}

void CUIManager::CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, std::string _sButtonText, bool _bEnabled)
{
	CUIButton* poButton = new CUIButton(_v2fSize, _v2fPosition, _eButtonType, _sButtonText, _bEnabled);
	m_oVecButtonPtrs.push_back(poButton);
}

void CUIManager::CreateText(unsigned int _uiFontSize, sf::Vector2f _v2fPosition, std::string _sTextString, bool _bEnabled)
{
	CUIText* poText = new CUIText(_uiFontSize, _v2fPosition, _sTextString, _bEnabled);
	m_oVecTextPtrs.push_back(poText);
}