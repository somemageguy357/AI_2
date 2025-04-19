#include "UIElement.h"

void CUIElement::SetEnabled(bool _bEnabled)
{
	m_bEnabled = _bEnabled;
}

bool CUIElement::GetEnabled()
{
	return m_bEnabled;
}