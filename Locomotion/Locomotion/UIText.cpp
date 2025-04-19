/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIText.cpp
Description : Contains function definitions for UIText.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "UIText.h"
#include "WindowManager.h"
#include "UIManager.h"

CUIText::CUIText(unsigned int _uiFontSize, sf::Vector2f _v2fPosition, std::string _sTextString, sf::Color _oColour, EAlignment _eAlignment, bool _bEnabled)
{
	m_oText.setFont(*CUIManager::GetUIFont());
	m_oText.setFillColor(_oColour);
	m_oText.setCharacterSize(_uiFontSize);
	m_oText.setString(_sTextString);

	SetElementAlignment(&m_oText, _eAlignment, _v2fPosition);

	m_bEnabled = _bEnabled;
}

CUIText::~CUIText() {}

void CUIText::Update() {}

void CUIText::Render()
{
	if (m_bEnabled == true)
	{
		CWindowManager::GetWindow()->draw(m_oText);
	}
}

void CUIText::SetString(std::string _sTextString)
{
	m_oText.setString(_sTextString);
	SetElementAlignment(&m_oText, m_eAlignment, m_oText.getPosition());
}

void CUIText::SetAlignment(EAlignment _eAlignment)
{
	SetElementAlignment(&m_oText, _eAlignment, m_oText.getPosition());
}

sf::Text* CUIText::GetShape()
{
	return &m_oText;
}