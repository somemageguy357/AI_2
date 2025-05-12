/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIManager.h
Description : Static class that handles all UI elements and runs their Update and Render functions.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include <vector>
#include "UIButton.h"
#include "UISeekPanel.h"
#include "UIWanderPanel.h"
#include "UISeparationPanel.h"
#include "UICohesionPanel.h"
#include "UIAlignmentPanel.h"
#include "UIArrivalPanel.h"

//Static class that handles all UI elements and runs their Update and Render functions.
class CUIManager
{
public:
	/// <summary>
	/// Calls Update() for all UI elements.
	/// </summary>
	/// <param name="_bIsClicking:">If the left mouse button is down. Used for button clicks.</param>
	static void Update(bool _bIsClicking);

	/// <summary>
	/// Calls Render() for all UI elements.
	/// </summary>
	static void Render();

	/// <summary>
	/// Creates all UI elements and stores them.
	/// </summary>
	static void InitUI();

	/// <summary>
	/// Gets the font used for UI text elements.
	/// </summary>
	/// <returns></returns>
	static sf::Font* GetUIFont();

	/// <summary>
	/// All UI buttons add themselves to the manager's button vector this way.
	/// </summary>
	/// <param name="_poButton:">Pointer to the button that is to be added.</param>
	static void AddToButtonVector(CUIButton* _poButton);

	/// <summary>
	/// Removes the given button from the manager's button vector.
	/// </summary>
	/// <param name="_poButton":>The button to remove.</param>
	static void RemoveFromButtonVector(CUIButton* _poButton);

	/// <summary>
	/// Closes all UI Panels.
	/// </summary>
	static void CloseAllPanels();

	/// <summary>
	/// Sets the text string representing the speed value of AI agents.
	/// </summary>
	/// <param name="_fValue:">The value to set to.</param>
	static void SetAgentSpeedText(float _fValue);

	/// <summary>
	/// Returns a pointer to the Arrival panel.
	/// </summary>
	/// <returns>A pointer to the Arrival panel.</returns>
	static CUIArrivalPanel* GetArrivalPanel();

	/// <summary>
	/// Returns a pointer to the Seek panel.
	/// </summary>
	/// <returns>A pointer to the Seek panel.</returns>
	static CUISeekPanel* GetSeekPanel();

	/// <summary>
	/// Returns a pointer to the Wander panel.
	/// </summary>
	/// <returns>A pointer to the Wander panel.</returns>
	static CUIWanderPanel* GetWanderPanel();

	/// <summary>
	/// Returns a pointer to the Separation panel.
	/// </summary>
	/// <returns>A pointer to the Separation panel.</returns>
	static CUISeparationPanel* GetSeparationPanel();

	/// <summary>
	/// Returns a pointer to the Cohesion panel.
	/// </summary>
	/// <returns>A pointer to the Cohesion panel.</returns>
	static CUICohesionPanel* GetCohesionPanel();

	/// <summary>
	/// Returns a pointer to the Alignment panel.
	/// </summary>
	/// <returns>A pointer to the Alignment panel.</returns>
	static CUIAlignmentPanel* GetAlignmentPanel();

	/// <summary>
	/// Repositions all enabled panels horizontally.
	/// </summary>
	static void PositionPanels();

	/// <summary>
	/// Deletes all UI elements and calls their destructors.
	/// </summary>
	static void Destroy();

private:
	static std::vector<CUIElement*> m_oVecManagerUIElementPtrs; //UI elements created only in the manager itself.
	static std::vector<CUIButton*> m_oVecButtonPtrs; //All UI buttons. All buttons add themselves to this vector.
	static std::vector<CUIPanel*> m_oVecPanelPtrs;

	static sf::Font* m_poUIFont;

	static CUIText* m_poAgentSpeedText;

	static CUIArrivalPanel* m_poArrivalPanel;
	static CUISeekPanel* m_poSeekPanel;
	static CUIWanderPanel* m_poWanderPanel;
	static CUISeparationPanel* m_poSeparationPanel;
	static CUICohesionPanel* m_poCohesionPanel;
	static CUIAlignmentPanel* m_poAlignmentPanel;

	/// <summary>
	/// Creates a UI button element.
	/// </summary>
	/// <param name="_v2fSize:">The size of the button.</param>
	/// <param name="_v2fPosition:">The position of the button (center-aligned).</param>
	/// <param name="_eButtonType:">Determines what event to perform when clicked.</param>
	/// <param name="_bEnabled:">Allows for updating and rendering if true.</param>
	static void CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, CUIElement::EAlignment _eAlignment, bool _bEnabled);

	/// <summary>
	/// Creates a UI button element with text in the middle.
	/// </summary>
	/// <param name="_v2fSize:">The size of the button.</param>
	/// <param name="_v2fPosition:">The position of the button (center-aligned).</param>
	/// <param name="_eButtonType:">Determines what event to perform when clicked.</param>
	/// <param name="_sButtonText:">The text that is displayed on the button.</param>
	/// <param name="_bEnabled:">Allows for updating and rendering if true.</param>
	static void CreateButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, CUIButton::EButtonType _eButtonType, CUIElement::EAlignment _eAlignment, unsigned int _uiFontSize, std::string _sButtonText, bool _bEnabled);

	/// <summary>
	/// Creates a UI text element.
	/// </summary>
	/// <param name="_uiFontSize:">The font size of the text.</param>
	/// <param name="_v2fPosition:">The position of the text (center-aligned).</param>
	/// <param name="_sTextString:">The string of the text element.</param>
	/// <param name="_oColour:">The colour of the text element.</param>
	/// <param name="_bEnabled:">Allows for updating and rendering if true.</param>
	static CUIText* CreateText(unsigned int _uiFontSize, sf::Vector2f _v2fPosition, std::string _sTextString, sf::Color _oColour, CUIElement::EAlignment _eAlignment, bool _bEnabled);

	CUIManager() = delete;
	~CUIManager() = delete;
};