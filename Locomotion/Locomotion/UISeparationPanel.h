#pragma once
#include "UIPanel.h"

class CUISeparationPanel : public CUIPanel
{
public:
	CUISeparationPanel(sf::Vector2f _v2fTopLeftPosition);
	~CUISeparationPanel();

	void SetWeightText(float _fValue);

	void SetStrengthText(float _fValue);

	void SetMaxSteerForceText(float _fValue);

	void SetNeighbourhoodRadiusText(float _fValue);

private:
	CUIButton* m_poDecrementWeightingBtn = nullptr;
	CUIButton* m_poIncrementWeightingBtn = nullptr;
	CUIButton* m_poDecrementStrengthBtn = nullptr;
	CUIButton* m_poIncrementStrengthBtn = nullptr;
	CUIButton* m_poDecrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poIncrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poDecNeighbourhoodRadiusBtn = nullptr;
	CUIButton* m_poIncNeighbourhoodRadiusBtn = nullptr;

	CUIText* m_poSeparationText = nullptr;
	CUIText* m_poWeightingText = nullptr;
	CUIText* m_poStrengthText = nullptr;
	CUIText* m_poMaxSteerForceText = nullptr;
	CUIText* m_poNeighbourhoodRadiusText = nullptr;
};