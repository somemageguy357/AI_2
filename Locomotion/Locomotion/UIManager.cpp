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
std::vector<CUIPanel*> CUIManager::m_oVecPanelPtrs;

sf::Font* CUIManager::m_poUIFont = nullptr;

CUISeekPanel* CUIManager::m_poSeekPanel = nullptr;
CUIWanderPanel* CUIManager::m_poWanderPanel = nullptr;
CUISeparationPanel* CUIManager::m_poSeparationPanel = nullptr;
CUICohesionPanel* CUIManager::m_poCohesionPanel = nullptr;
CUIAlignmentPanel* CUIManager::m_poAlignmentPanel = nullptr;

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
	m_poWanderPanel = new CUIWanderPanel({ 0.0f, 510.0f });
	m_poSeparationPanel = new CUISeparationPanel({ 0.0f, 510.0f });
	m_poCohesionPanel = new CUICohesionPanel({ 0.0f, 510.0f });
	m_poAlignmentPanel = new CUIAlignmentPanel({ 0.0f, 510.0f });

	m_oVecUIElementPtrs.push_back(m_poSeekPanel);
	m_oVecUIElementPtrs.push_back(m_poWanderPanel);
	m_oVecUIElementPtrs.push_back(m_poSeparationPanel);
	m_oVecUIElementPtrs.push_back(m_poCohesionPanel);
	m_oVecUIElementPtrs.push_back(m_poAlignmentPanel);

	m_oVecPanelPtrs.push_back(m_poSeekPanel);
	m_oVecPanelPtrs.push_back(m_poWanderPanel);
	m_oVecPanelPtrs.push_back(m_poSeparationPanel);
	m_oVecPanelPtrs.push_back(m_poCohesionPanel);
	m_oVecPanelPtrs.push_back(m_poAlignmentPanel);
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

void CUIManager::CloseAllPanels()
{
	m_poSeekPanel->SetEnabled(false);
	m_poWanderPanel->SetEnabled(false);
	m_poSeparationPanel->SetEnabled(false);
	m_poCohesionPanel->SetEnabled(false);
	m_poAlignmentPanel->SetEnabled(false);
}

CUISeekPanel* CUIManager::GetSeekPanel()
{
	return m_poSeekPanel;
}

CUIWanderPanel* CUIManager::GetWanderPanel()
{
	return m_poWanderPanel;
}

CUISeparationPanel* CUIManager::GetSeparationPanel()
{
	return m_poSeparationPanel;
}

CUICohesionPanel* CUIManager::GetCohesionPanel()
{
	return m_poCohesionPanel;
}

CUIAlignmentPanel* CUIManager::GetAlignmentPanel()
{
	return m_poAlignmentPanel;
}

void CUIManager::PositionPanels()
{
	int iPanelsOpen = 0;

	for (size_t i = 0; i < m_oVecPanelPtrs.size(); i++)
	{
		if (m_oVecPanelPtrs[i]->GetEnabled() == true)
		{
			m_oVecPanelPtrs[i]->ResetPosition();
			m_oVecPanelPtrs[i]->RepositionPanel(iPanelsOpen * 300);
			iPanelsOpen += 1;
		}
	}
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