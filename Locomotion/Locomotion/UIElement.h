#pragma once
#include "SFML/Graphics.hpp"

class CUIElement
{
public:
	enum class EAlignment
	{
		TopLeft,
		TopMiddle,
		TopRight,
		CenterLeft,
		CenterMiddle,
		CenterRight,
		BottomLeft,
		BottomMiddle,
		BottomRight
	};

	~CUIElement() {};

	virtual void Update() = 0;

	virtual void Render() = 0;

	virtual void SetAlignment(EAlignment _eAlignment) = 0;

	EAlignment GetAlignment();

	/// <summary>
	/// Enables/disables the button which determines if its Update() and Render() functions should perform.
	/// </summary>
	/// <param name="_bEnabled:">The new enabled state of the button.</param>
	virtual void SetEnabled(bool _bEnabled);

	bool GetEnabled();

protected:
	bool m_bEnabled = true;

	EAlignment m_eAlignment = EAlignment::CenterMiddle;

	CUIElement() {};

	void SetElementAlignment(sf::RectangleShape* _poShape, EAlignment _eAlignment, sf::Vector2f _v2fPosition);

	void SetElementAlignment(sf::Text* _poText, EAlignment _eAlignment, sf::Vector2f _v2fPosition);
};