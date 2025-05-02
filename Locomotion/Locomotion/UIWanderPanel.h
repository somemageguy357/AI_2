#pragma once
#include "UIPanel.h"

class CUIWanderPanel : public CUIPanel
{
public:
	CUIWanderPanel(sf::Vector2f _v2fTopLeftPosition);
	~CUIWanderPanel();

	void SetWeightText(float _fValue);

	void SetStrengthText(float _fValue);

	void SetMaxSteerForceText(float _fValue);

	void SetRadiusText(float _fValue);

	void SetDistanceText(float _fValue);

private:
	CUIButton* m_poDecrementWeightingBtn = nullptr;
	CUIButton* m_poIncrementWeightingBtn = nullptr;
	CUIButton* m_poDecrementStrengthBtn = nullptr;
	CUIButton* m_poIncrementStrengthBtn = nullptr;
	CUIButton* m_poDecrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poIncrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poDecrementRadiusBtn = nullptr;
	CUIButton* m_poIncrementRadiusBtn = nullptr;
	CUIButton* m_poDecrementDistanceBtn = nullptr;
	CUIButton* m_poIncrementDistanceBtn = nullptr;

	CUIText* m_poSeekText = nullptr;
	CUIText* m_poWeightingText = nullptr;
	CUIText* m_poStrengthText = nullptr;
	CUIText* m_poMaxSteerForceText = nullptr;
	CUIText* m_poRadiusText = nullptr;
	CUIText* m_poDistanceText = nullptr;
};