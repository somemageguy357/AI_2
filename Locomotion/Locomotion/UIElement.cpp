#include "UIElement.h"

CUIElement::EAlignment CUIElement::GetAlignment()
{
	return m_eAlignment;
}

void CUIElement::SetEnabled(bool _bEnabled)
{
	m_bEnabled = _bEnabled;
}

bool CUIElement::GetEnabled()
{
	return m_bEnabled;
}

void CUIElement::SetElementAlignment(sf::RectangleShape* _poShape, EAlignment _eAlignment, sf::Vector2f _v2fPosition)
{
	m_eAlignment = _eAlignment;
	sf::FloatRect oShapeRect = _poShape->getGlobalBounds();

	if (_eAlignment == EAlignment::TopLeft)
	{
		_poShape->setOrigin(0, 0);
	}

	else if (_eAlignment == EAlignment::TopMiddle)
	{
		_poShape->setOrigin(oShapeRect.width / 2, 0);
	}

	else if (_eAlignment == EAlignment::TopRight)
	{
		_poShape->setOrigin(oShapeRect.width, 0);
	}

	else if (_eAlignment == EAlignment::CenterLeft)
	{
		_poShape->setOrigin(0, oShapeRect.height / 2);
	}

	else if (_eAlignment == EAlignment::CenterMiddle)
	{
		_poShape->setOrigin(oShapeRect.width / 2, oShapeRect.height / 2);
	}

	else if (_eAlignment == EAlignment::CenterRight)
	{
		_poShape->setOrigin(oShapeRect.width, oShapeRect.height / 2);
	}

	else if (_eAlignment == EAlignment::BottomLeft)
	{
		_poShape->setOrigin(0, oShapeRect.height);
	}

	else if (_eAlignment == EAlignment::BottomMiddle)
	{
		_poShape->setOrigin(oShapeRect.width / 2, oShapeRect.height);
	}

	else if (_eAlignment == EAlignment::BottomRight)
	{
		_poShape->setOrigin(oShapeRect.width, oShapeRect.height);
	}

	_poShape->setPosition(_v2fPosition);
}

void CUIElement::SetElementAlignment(sf::Text* _poText, EAlignment _eAlignment, sf::Vector2f _v2fPosition)
{
	m_eAlignment = _eAlignment;
	sf::FloatRect oTextRect = _poText->getGlobalBounds();

	if (_eAlignment == EAlignment::TopLeft)
	{
		_poText->setOrigin(0, 0);
	}

	else if (_eAlignment == EAlignment::TopMiddle)
	{
		_poText->setOrigin(oTextRect.width / 2, 0);
	}

	else if (_eAlignment == EAlignment::TopRight)
	{
		_poText->setOrigin(oTextRect.width, 0);
	}

	else if (_eAlignment == EAlignment::CenterLeft)
	{
		_poText->setOrigin(0, oTextRect.height / 2);
	}

	else if (_eAlignment == EAlignment::CenterMiddle)
	{
		_poText->setOrigin(oTextRect.width / 2, oTextRect.height / 2);
	}

	else if (_eAlignment == EAlignment::CenterRight)
	{
		_poText->setOrigin(oTextRect.width, oTextRect.height / 2);
	}

	else if (_eAlignment == EAlignment::BottomLeft)
	{
		_poText->setOrigin(0, oTextRect.height);
	}

	else if (_eAlignment == EAlignment::BottomMiddle)
	{
		_poText->setOrigin(oTextRect.width / 2, oTextRect.height);
	}

	else if (_eAlignment == EAlignment::BottomRight)
	{
		_poText->setOrigin(oTextRect.width, oTextRect.height);
	}

	_poText->setPosition(_v2fPosition);
}