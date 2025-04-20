#include "UIPanel.h"

void CUIPanel::Update()
{
	if (m_bEnabled == true)
	{
		for (size_t i = 0; i < m_oVecButtonPtrs.size(); i++)
		{
			m_oVecButtonPtrs[i]->Update();
		}

		for (size_t i = 0; i < m_oVecTextPtrs.size(); i++)
		{
			m_oVecTextPtrs[i]->Update();
		}
	}
}

void CUIPanel::Render()
{
	if (m_bEnabled == true)
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
}

void CUIPanel::RepositionPanel(float _fXOffset)
{
	m_fXOffset = _fXOffset;

	for (size_t i = 0; i < m_oVecButtonPtrs.size(); i++)
	{
		sf::Vector2f v2fShapePos = m_oVecButtonPtrs[i]->GetShape()->getPosition();
		
		m_oVecButtonPtrs[i]->SetPosition({ v2fShapePos.x + m_fXOffset, v2fShapePos.y });
	}

	for (size_t i = 0; i < m_oVecTextPtrs.size(); i++)
	{
		sf::Vector2f v2fShapePos = m_oVecTextPtrs[i]->GetShape()->getPosition();

		m_oVecTextPtrs[i]->GetShape()->setPosition({ v2fShapePos.x + m_fXOffset, v2fShapePos.y });
	}
}

void CUIPanel::ResetPosition()
{
	for (size_t i = 0; i < m_oVecButtonPtrs.size(); i++)
	{
		sf::Vector2f v2fShapePos = m_oVecButtonPtrs[i]->GetShape()->getPosition();

		m_oVecButtonPtrs[i]->SetPosition({ v2fShapePos.x - m_fXOffset, v2fShapePos.y });
	}

	for (size_t i = 0; i < m_oVecTextPtrs.size(); i++)
	{
		sf::Vector2f v2fShapePos = m_oVecTextPtrs[i]->GetShape()->getPosition();

		m_oVecTextPtrs[i]->GetShape()->setPosition({ v2fShapePos.x - m_fXOffset, v2fShapePos.y });
	}
}

CUIButton* CUIPanel::CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, CUIElement::EAlignment _eAlignment, bool _bEnabled)
{
	CUIButton* poButton = new CUIButton(_v2fSize, _v2fPosition, _eButtonType, _eAlignment, _bEnabled);
	m_oVecButtonPtrs.push_back(poButton);
	return poButton;
}

CUIButton* CUIPanel::CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, CUIElement::EAlignment _eAlignment, unsigned int _uiFontSize, std::string _sButtonText, bool _bEnabled)
{
	CUIButton* poButton = new CUIButton(_v2fSize, _v2fPosition, _eButtonType, _eAlignment, _uiFontSize, _sButtonText, _bEnabled);
	m_oVecButtonPtrs.push_back(poButton);
	return poButton;
}

CUIText* CUIPanel::CreateText(unsigned int _uiFontSize, sf::Vector2f _v2fPosition, std::string _sTextString, sf::Color _oColour, CUIElement::EAlignment _eAlignment, bool _bEnabled)
{
	CUIText* poText = new CUIText(_uiFontSize, _v2fPosition, _sTextString, _oColour, _eAlignment, _bEnabled);
	m_oVecTextPtrs.push_back(poText);
	return poText;
}