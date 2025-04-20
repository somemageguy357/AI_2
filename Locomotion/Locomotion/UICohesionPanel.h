#pragma once
#include "UIPanel.h"

class CUICohesionPanel : public CUIPanel
{
public:
	CUICohesionPanel(sf::Vector2f _v2fTopLeftPosition);
	~CUICohesionPanel();

	void SetWeightText(float _fValue);

	void SetStrengthText(float _fValue);

	void SetMaxSteerForceText(float _fValue);

	void SetNeighbourhoodRadiusText(float _fValue);

	void SetIncludeSelfText(bool _bValue);

private:
	CUIButton* m_poDecrementWeightingBtn = nullptr;
	CUIButton* m_poIncrementWeightingBtn = nullptr;
	CUIButton* m_poDecrementStrengthBtn = nullptr;
	CUIButton* m_poIncrementStrengthBtn = nullptr;
	CUIButton* m_poDecrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poIncrementMaxSteerForceBtn = nullptr;
	CUIButton* m_poDecNeighbourhoodRadiusBtn = nullptr;
	CUIButton* m_poIncNeighbourhoodRadiusBtn = nullptr;
	CUIButton* m_poToggleIncludeSelfBtn = nullptr;

	CUIText* m_poCohesionText = nullptr;
	CUIText* m_poWeightingText = nullptr;
	CUIText* m_poStrengthText = nullptr;
	CUIText* m_poMaxSteerForceText = nullptr;
	CUIText* m_poNeighbourhoodRadiusText = nullptr;
	CUIText* m_poIncludeSelfText = nullptr;
};