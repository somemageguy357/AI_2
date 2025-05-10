#pragma once
#include "UIPanel.h"

class CUIArrivalPanel : public CUIPanel
{
public:
	CUIArrivalPanel(sf::Vector2f _v2fTopLeftPosition);
	~CUIArrivalPanel();

	void SetWeightText(float _fValue);

	void SetStoppingRadiusText(float _fValue);

	void SetStrengthText(float _fValue);

	void SetMaxSteerForceText(float _fValue);

private:
	CUIButton* m_poDecrementWeightingBtn = nullptr;
	CUIButton* m_poIncrementWeightingBtn = nullptr;
	CUIButton* m_poDecrementStrengthBtn = nullptr;
	CUIButton* m_poIncrementStrengthBtn = nullptr;
	CUIButton* m_poDecrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poIncrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poDecrementStoppingRadiusBtn = nullptr;
	CUIButton* m_poIncrementStoppingRadiusBtn = nullptr;

	CUIText* m_poArrivalText = nullptr;
	CUIText* m_poStrengthText = nullptr;
	CUIText* m_poWeightingText = nullptr;
	CUIText* m_poMaxSteerForceText = nullptr;
	CUIText* m_poStoppingRadiusText = nullptr;
};