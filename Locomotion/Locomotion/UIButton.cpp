/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIButton.cpp
Description : Contains function definitions for UIButton.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "UIButton.h"
#include "WindowManager.h"

CUIButton::CUIButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, bool _bEnabled)
{
	SetupButton(_v2fSize, _v2fPosition, _eButtonType, _bEnabled);
}

CUIButton::CUIButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, std::string _sButtonText, bool _bEnabled)
{
	SetupButton(_v2fSize, _v2fPosition, _eButtonType, _bEnabled);

	m_poButtonText = new CUIText(20, _v2fPosition, _sButtonText, _bEnabled);
}

CUIButton::~CUIButton() 
{
	if (m_poButtonText != nullptr)
	{
		delete m_poButtonText;
	}
}

void CUIButton::Update(bool _bIsClicking)
{
	if (m_bEnabled == true)
	{
		CheckMouseOverlap(_bIsClicking);
	}
}

void CUIButton::Render()
{
	if (m_bEnabled == true)
	{
		CWindowManager::GetWindow()->draw(m_oButtonShape);

		if (m_poButtonText != nullptr)
		{
			m_poButtonText->Render();
		}
	}
}

void CUIButton::SetEnabled(bool _bEnabled)
{
	m_bEnabled = _bEnabled;
}

void CUIButton::CheckMouseOverlap(bool _bIsClicking)
{
	sf::Vector2i v2iMousePosition = sf::Mouse::getPosition(*CWindowManager::GetWindow());

	//Check for mouse overlap.
	if (v2iMousePosition.x >= m_oButtonShape.getGlobalBounds().left &&
		v2iMousePosition.x <= m_oButtonShape.getGlobalBounds().left + m_oButtonShape.getGlobalBounds().width &&
		v2iMousePosition.y >= m_oButtonShape.getGlobalBounds().top &&
		v2iMousePosition.y <= m_oButtonShape.getGlobalBounds().top + m_oButtonShape.getGlobalBounds().height)
	{
		m_oButtonShape.setFillColor(sf::Color::Yellow);

		//Perform click event.
		if (_bIsClicking == true)
		{
			OnClick();
		}
	}

	//Reset to unhovered colour.
	else if (m_oButtonShape.getFillColor() != sf::Color::White)
	{
		m_oButtonShape.setFillColor(sf::Color::White);
	}
}

void CUIButton::OnClick()
{
	if (m_eButtonType == EButtonType::AIArrival)
	{

	}

	else if (m_eButtonType == EButtonType::AIFlock)
	{

	}

	else if (m_eButtonType == EButtonType::AISeek)
	{

	}

	else if (m_eButtonType == EButtonType::AIWander)
	{

	}
}

void CUIButton::SetupButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, bool _bEnabled)
{
	m_oButtonShape.setSize(_v2fSize);

	m_oButtonShape.setOrigin
	(
		m_oButtonShape.getGlobalBounds().left + (m_oButtonShape.getGlobalBounds().width / 2),
		m_oButtonShape.getGlobalBounds().top + (m_oButtonShape.getGlobalBounds().height / 2)
	);

	m_oButtonShape.setPosition(_v2fPosition);
	m_oButtonShape.setFillColor(sf::Color::White);
	m_eButtonType = _eButtonType;
	m_bEnabled = _bEnabled;
}