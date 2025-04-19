#pragma once
#include "UIPanel.h"

class CUISeekPanel : public CUIPanel
{
public:
	CUISeekPanel(sf::Vector2f _v2fTopLeftPosition);
	~CUISeekPanel();

	void SetWeightText(float _fValue);

	void SetStrengthText(float _fValue);

	void SetMaxSteerForceText(float _fValue);

private:
	CUIButton* m_poDecrementWeightingBtn = nullptr;
	CUIButton* m_poIncrementWeightingBtn = nullptr;
	CUIButton* m_poDecrementStrengthBtn = nullptr;
	CUIButton* m_poIncrementStrengthBtn = nullptr;
	CUIButton* m_poDecrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poIncrementMaxSteerForceBtn = nullptr;

	CUIText* m_poSeekText = nullptr;
	CUIText* m_poWeightingText = nullptr;
	CUIText* m_poStrengthText = nullptr;
	CUIText* m_poMaxSteerForceText = nullptr;
};