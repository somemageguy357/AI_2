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

CUIText::CUIText(unsigned int _uiFontSize, sf::Vector2f _v2fPosition, std::string _sTextString, sf::Color _oColour, bool _bEnabled)
{
	m_oText.setFont(*CUIManager::GetUIFont());
	m_oText.setFillColor(_oColour);
	m_oText.setCharacterSize(_uiFontSize);
	m_oText.setString(_sTextString);

	m_oText.setOrigin
	(
		m_oText.getGlobalBounds().left + (m_oText.getGlobalBounds().width / 2), 
		m_oText.getGlobalBounds().top + (m_oText.getGlobalBounds().height / 2) 
	);

	m_oText.setPosition(_v2fPosition);

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

void CUIText::SetEnabled(bool _bEnabled)
{
	m_bEnabled = _bEnabled;
}

void CUIText::SetString(std::string _sTextString)
{
	sf::Vector2f v2fPosition = m_oText.getPosition();

	m_oText.setString(_sTextString);

	m_oText.setOrigin
	(
		m_oText.getGlobalBounds().left + (m_oText.getGlobalBounds().width / 2),
		m_oText.getGlobalBounds().top + (m_oText.getGlobalBounds().height / 2)
	);

	m_oText.setPosition(v2fPosition);
}