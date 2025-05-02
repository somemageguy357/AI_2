#pragma once
#include "UIButton.h"

class CUIPanel : public CUIElement
{
public:
	~CUIPanel() {};

	void Update() override;

	void Render() override;

	void SetEnabled(bool _bEnabled) override;

	void RepositionPanel(float _fXOffset);

	void ResetPosition();

protected:
	CUIPanel() {};

	CUIButton* CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, CUIElement::EAlignment _eAlignment, bool _bEnabled);

	CUIButton* CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, CUIElement::EAlignment _eAlignment, unsigned int _uiFontSize, std::string _sButtonText, bool _bEnabled);

	CUIText* CreateText(unsigned int _uiFontSize, sf::Vector2f _v2fPosition, std::string _sTextString, sf::Color _oColour, CUIElement::EAlignment _eAlignment, bool _bEnabled);

private:
	std::vector<CUIButton*> m_oVecButtonPtrs;
	std::vector<CUIText*> m_oVecTextPtrs;

	float m_fXOffset = 0.0f;

	void SetAlignment(EAlignment _eAlignment) override {};
};