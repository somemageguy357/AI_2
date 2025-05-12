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
#include "Utilities.h"

std::vector<CUIElement*> CUIManager::m_oVecManagerUIElementPtrs;
std::vector<CUIButton*> CUIManager::m_oVecButtonPtrs;
std::vector<CUIPanel*> CUIManager::m_oVecPanelPtrs;

sf::Font* CUIManager::m_poUIFont = nullptr;

CUIText* CUIManager::m_poAgentSpeedText = nullptr;

CUIArrivalPanel* CUIManager::m_poArrivalPanel = nullptr;
CUISeekPanel* CUIManager::m_poSeekPanel = nullptr;
CUIWanderPanel* CUIManager::m_poWanderPanel = nullptr;
CUISeparationPanel* CUIManager::m_poSeparationPanel = nullptr;
CUICohesionPanel* CUIManager::m_poCohesionPanel = nullptr;
CUIAlignmentPanel* CUIManager::m_poAlignmentPanel = nullptr;

void CUIManager::Update(bool _bIsClicking)
{
	for (size_t i = 0; i < m_oVecManagerUIElementPtrs.size(); i++)
	{
		m_oVecManagerUIElementPtrs[i]->Update();
	}

	for (size_t i = 0; i < m_oVecButtonPtrs.size(); i++)
	{
		m_oVecButtonPtrs[i]->CheckMouseOverlap(_bIsClicking);
	}

}

void CUIManager::Render()
{
	for (size_t i = 0; i < m_oVecManagerUIElementPtrs.size(); i++)
	{
		m_oVecManagerUIElementPtrs[i]->Render();
	}
}

void CUIManager::InitUI()
{
	//Load font.
	m_poUIFont = new sf::Font();
	m_poUIFont->loadFromFile("Fonts/Roboto-Light.ttf");

	//Create main UI.
	CreateText(20, { 60, 20 }, "Behaviours", sf::Color::White, CUIElement::EAlignment::CenterMiddle, true);
	CreateButton({ 100, 30 }, { 10, 50 }, CUIButton::EButtonType::AIArrival, CUIElement::EAlignment::TopLeft, 20, "Arrival", true);
	CreateButton({ 100, 30 }, { 10, 90 }, CUIButton::EButtonType::AISeek, CUIElement::EAlignment::TopLeft, 20, "Seek", true);
	CreateButton({ 100, 30 }, { 10, 130 }, CUIButton::EButtonType::AIWander, CUIElement::EAlignment::TopLeft, 20, "Wander", true);
	CreateButton({ 100, 30 }, { 10, 170 }, CUIButton::EButtonType::AIFlock, CUIElement::EAlignment::TopLeft, 20, "Flock", true);

	CreateText(20, { 60, 320 }, "Gizmos", sf::Color::White, CUIElement::EAlignment::CenterMiddle, true);
	CreateButton({ 100, 30 }, { 10, 350 }, CUIButton::EButtonType::ToggleGizmos, CUIElement::EAlignment::TopLeft, 20, "Enable", true);

	CreateText(20, { 60, 420 }, "Agent Speed:", sf::Color::White, CUIElement::EAlignment::CenterMiddle, true);
	m_poAgentSpeedText = CreateText(20, { 60, 440 }, "", sf::Color::White, CUIElement::EAlignment::CenterMiddle, true);

	//Create panels for the behaviours.
	m_poArrivalPanel = new CUIArrivalPanel({ 0.0f, 510.0f });
	m_poSeekPanel = new CUISeekPanel({ 0.0f, 510.0f });
	m_poWanderPanel = new CUIWanderPanel({ 0.0f, 510.0f });
	m_poSeparationPanel = new CUISeparationPanel({ 0.0f, 510.0f });
	m_poCohesionPanel = new CUICohesionPanel({ 0.0f, 510.0f });
	m_poAlignmentPanel = new CUIAlignmentPanel({ 0.0f, 510.0f });

	m_oVecManagerUIElementPtrs.push_back(m_poArrivalPanel);
	m_oVecManagerUIElementPtrs.push_back(m_poSeekPanel);
	m_oVecManagerUIElementPtrs.push_back(m_poWanderPanel);
	m_oVecManagerUIElementPtrs.push_back(m_poSeparationPanel);
	m_oVecManagerUIElementPtrs.push_back(m_poCohesionPanel);
	m_oVecManagerUIElementPtrs.push_back(m_poAlignmentPanel);

	//Add panels to their own vector to make it easier to access them when closing them all.
	m_oVecPanelPtrs.push_back(m_poArrivalPanel);
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
	for (size_t i = 0; i < m_oVecPanelPtrs.size(); i++)
	{
		m_oVecPanelPtrs[i]->SetEnabled(false);
	}
}

void CUIManager::SetAgentSpeedText(float _fValue)
{
	m_poAgentSpeedText->SetString(CUtilities::FloatToString(_fValue, 0));
}

CUIArrivalPanel* CUIManager::GetArrivalPanel()
{
	return m_poArrivalPanel;
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

	//Repositions all enabled panels horizontally.
	for (size_t i = 0; i < m_oVecPanelPtrs.size(); i++)
	{
		if (m_oVecPanelPtrs[i]->GetEnabled() == true)
		{
			m_oVecPanelPtrs[i]->ResetPosition();
			m_oVecPanelPtrs[i]->RepositionPanel((float)iPanelsOpen * 300.0f);
			iPanelsOpen += 1;
		}
	}
}

void CUIManager::Destroy()
{
	for (size_t i = 0; i < m_oVecManagerUIElementPtrs.size(); i++)
	{
		delete m_oVecManagerUIElementPtrs[i]; //Contains all panels as well as text and buttons created by the UI Manager.
	}

	delete m_poUIFont;
}

void CUIManager::CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, CUIElement::EAlignment _eAlignment, bool _bEnabled)
{
	CUIButton* poButton = new CUIButton(_v2fSize, _v2fPosition, _eButtonType, _eAlignment, _bEnabled);
	m_oVecManagerUIElementPtrs.push_back(poButton);
}

void CUIManager::CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, CUIElement::EAlignment _eAlignment, unsigned int _uiFontSize, std::string _sButtonText, bool _bEnabled)
{
	CUIButton* poButton = new CUIButton(_v2fSize, _v2fPosition, _eButtonType, _eAlignment, _uiFontSize, _sButtonText, _bEnabled);
	m_oVecManagerUIElementPtrs.push_back(poButton);
}

CUIText* CUIManager::CreateText(unsigned int _uiFontSize, sf::Vector2f _v2fPosition, std::string _sTextString, sf::Color _oColour, CUIElement::EAlignment _eAlignment, bool _bEnabled)
{
	CUIText* poText = new CUIText(_uiFontSize, _v2fPosition, _sTextString, _oColour, _eAlignment, _bEnabled);
	m_oVecManagerUIElementPtrs.push_back(poText);

	return poText;
}