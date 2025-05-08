/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIButton.h
Description : A UI element that is displayed to the window and performs events when clicked.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include <SFML/Graphics.hpp>
#include "UIText.h"

//A UI element that is displayed to the window and performs events when clicked.
class CUIButton : public CUIElement
{
public:
	//The type of event to perform when the button is clicked.
	enum class EButtonType
	{
		n,

		//--------------------------SET BEHAVIOURS
		AIArrival,
		AISeek,
		AIPursuit,
		AIWander,
		AIFlock,

		//--------------------------GIZMOS
		ToggleGizmos,

		//--------------------------ARRIVAL
		IncArrivalWeighting,
		DecArrivalWeighting,
		IncArrivalMSF,
		DecArrivalMSF,
		IncArrivalStoppingRadius,
		DecArrivalStoppingRadius,

		//--------------------------SEEK
		IncSeekWeighting,
		DecSeekWeighting,
		IncSeekStrength,
		DecSeekStrength,
		IncSeekMSF,
		DecSeekMSF,

		//--------------------------WANDER
		IncWanderWeighting,
		DecWanderWeighting,
		IncWanderStrength,
		DecWanderStrength,
		IncWanderMSF,
		DecWanderMSF,
		IncWanderRadius,
		DecWanderRadius,
		IncWanderDistance,
		DecWanderDistance,

		//--------------------------SEPARATION
		IncSeparationWeighting,
		DecSeparationWeighting,
		IncSeparationStrength,
		DecSeparationStrength,
		IncSeparationMSF,
		DecSeparationMSF,
		IncSeparationNHR,
		DecSeparationNHR,

		//--------------------------COHESION
		IncCohesionWeighting,
		DecCohesionWeighting,
		IncCohesionStrength,
		DecCohesionStrength,
		IncCohesionMSF,
		DecCohesionMSF,
		IncCohesionNHR,
		DecCohesionNHR,
		ToggleCohesionIncludeSelf,

		//--------------------------ALIGNMENT
		IncAlignmentWeighting,
		DecAlignmentWeighting,
		IncAlignmentStrength,
		DecAlignmentStrength,
		IncAlignmentMSF,
		DecAlignmentMSF,
		IncAlignmentNHR,
		DecAlignmentNHR,
	};

	CUIButton() = delete;

	/// <summary>
	/// Creates a UI button element.
	/// </summary>
	/// <param name="_v2fSize:">The size of the button.</param>
	/// <param name="_v2fPosition:">The position of the button (center-aligned).</param>
	/// <param name="_eButtonType:">Determines what event to perform when clicked.</param>
	/// <param name="_bEnabled:">Allows for updating and rendering if true.</param>
	CUIButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, EAlignment _eAlignment, bool _bEnabled);

	/// <summary>
	/// Creates a UI button element with text in the middle.
	/// </summary>
	/// <param name="_v2fSize:">The size of the button.</param>
	/// <param name="_v2fPosition:">The position of the button (center-aligned).</param>
	/// <param name="_eButtonType:">Determines what event to perform when clicked.</param>
	/// <param name="_sButtonText:">The text that is displayed on the button.</param>
	/// <param name="_bEnabled:">Allows for updating and rendering if true.</param>
	CUIButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, EAlignment _eAlignment, unsigned int _uiFontSize, std::string _sButtonText, bool _bEnabled);

	~CUIButton();

	/// <summary>
	/// If enabled: checks for mouse overlap and performs the button's OnClick() event if the mouse is overlapping
	/// the button and its left button is being clicked.
	/// </summary>
	/// <param name="_bIsClicking:">True if the left mouse button is down. Allows for the button's OnClick() event to be performed.</param>
	void CheckMouseOverlap(bool _bIsClicking);

	/// <summary>
	/// If enabled: checks for mouse overlap and performs the button's OnClick() event if the mouse is overlapping
	/// the button and its left button is being clicked.
	/// </summary>
	void Update() override;

	/// <summary>
	/// If enabled: renders the button and its text element (if it has one) to the render window.
	/// </summary>
	void Render() override;

	void SetEnabled(bool _bEnabled) override;

	void SetAlignment(EAlignment _eAlignment) override;

	sf::RectangleShape* GetShape();

	void SetPosition(sf::Vector2f _v2fPosition);

private:
	sf::RectangleShape m_oButtonShape;

	CUIText* m_poButtonText = nullptr;

	EButtonType m_eButtonType;

	//Performs the click event of the button, determined by its EButtonType.
	void OnClick();

	//Sets up the buttons initial values. Called from the constructors.
	void SetupButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, EAlignment _eAlignment, bool _bEnabled);
};