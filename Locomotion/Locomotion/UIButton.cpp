/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : UIButton.cpp
Description : Contains function definitions for UIButton.h.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#include "UIButton.h"
#include "WindowManager.h"
#include "UIManager.h"
#include "AgentManager.h"
#include "Gizmos.h"
#include "AgentBehaviourValues.h"

CUIButton::CUIButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, EAlignment _eAlignment, bool _bEnabled)
{
	SetupButton(_v2fSize, _v2fPosition, _eButtonType, _eAlignment, _bEnabled);
}

CUIButton::CUIButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, EAlignment _eAlignment, unsigned int _uiFontSize, std::string _sButtonText, bool _bEnabled)
{
	SetupButton(_v2fSize, _v2fPosition, _eButtonType, _eAlignment, _bEnabled);

	sf::Vector2f v2fTextPosition = 
	{
		m_oButtonShape.getGlobalBounds().left + m_oButtonShape.getGlobalBounds().width / 2, 
		(m_oButtonShape.getGlobalBounds().top + m_oButtonShape.getGlobalBounds().height / 2) - 4
	};

	m_poButtonText = new CUIText(_uiFontSize, v2fTextPosition, _sButtonText, sf::Color::Black, EAlignment::CenterMiddle, _bEnabled);
}

CUIButton::~CUIButton() 
{
	if (m_poButtonText != nullptr)
	{
		delete m_poButtonText;
	}

	CUIManager::RemoveFromButtonVector(this);
}

void CUIButton::Update() {}

void CUIButton::Render()
{
	if (m_bEnabled == true)
	{
		CWindowManager::GetWindow()->draw(m_oButtonShape);

		if (m_poButtonText != nullptr)
		{
			m_poButtonText->Render();
		}
	}
}

void CUIButton::SetEnabled(bool _bEnabled)
{
	m_bEnabled = _bEnabled;

	if (m_poButtonText != nullptr)
	{
		m_poButtonText->SetEnabled(_bEnabled);
	}
}

void CUIButton::SetAlignment(EAlignment _eAlignment)
{
	SetElementAlignment(&m_oButtonShape, _eAlignment, m_oButtonShape.getPosition());
}

sf::RectangleShape* CUIButton::GetShape()
{
	return &m_oButtonShape;
}

void CUIButton::SetPosition(sf::Vector2f _v2fPosition)
{
	m_oButtonShape.setPosition(_v2fPosition);

	//Update the button's text position, if it exists.
	if (m_poButtonText != nullptr)
	{
		sf::Vector2f v2fTextPosition =
		{
			m_oButtonShape.getGlobalBounds().left + m_oButtonShape.getGlobalBounds().width / 2,
			(m_oButtonShape.getGlobalBounds().top + m_oButtonShape.getGlobalBounds().height / 2) - 4
		};

		m_poButtonText->GetShape()->setPosition(v2fTextPosition);
	}
}

void CUIButton::CheckMouseOverlap(bool _bIsClicking)
{
	if (m_bEnabled == true)
	{
		sf::Vector2i v2iMousePosition = sf::Mouse::getPosition(*CWindowManager::GetWindow());

		//Check for mouse overlap.
		if (v2iMousePosition.x >= m_oButtonShape.getGlobalBounds().left &&
			v2iMousePosition.x <= m_oButtonShape.getGlobalBounds().left + m_oButtonShape.getGlobalBounds().width &&
			v2iMousePosition.y >= m_oButtonShape.getGlobalBounds().top &&
			v2iMousePosition.y <= m_oButtonShape.getGlobalBounds().top + m_oButtonShape.getGlobalBounds().height)
		{
			m_oButtonShape.setFillColor(sf::Color::Yellow);

			//Perform click event.
			if (_bIsClicking == true)
			{
				OnClick();
			}
		}

		//Reset to unhovered colour.
		else if (m_oButtonShape.getFillColor() != sf::Color::White)
		{
			m_oButtonShape.setFillColor(sf::Color::White);
		}
	}
}

void CUIButton::OnClick()
{
	#pragma region SetAgentBehaviour
	//------------------------------------------------------------------------------------------------------------SET BEHAVIOUR
	if (m_eButtonType == EButtonType::AIArrival)
	{
		CAgentBehaviourValues::InitBehaviour(CAgentBehaviourValues::EBehaviour::Arrival);
	}

	else if (m_eButtonType == EButtonType::AIFlock)
	{
		CAgentBehaviourValues::InitBehaviour(CAgentBehaviourValues::EBehaviour::Flock);
	}

	else if (m_eButtonType == EButtonType::AISeek)
	{
		CAgentBehaviourValues::InitBehaviour(CAgentBehaviourValues::EBehaviour::Seek);
	}

	else if (m_eButtonType == EButtonType::AIWander)
	{
		CAgentBehaviourValues::InitBehaviour(CAgentBehaviourValues::EBehaviour::Wander);
	}
	#pragma endregion

	#pragma region ChangeBehaviourValues
	//------------------------------------------------------------------------------------------------------------ARRIVAL
	else if (m_eButtonType == EButtonType::DecArrivalWeighting)
	{
		CAgentBehaviourValues::SetArrivalWeighting(CAgentBehaviourValues::GetArrivalWeighting() - 0.05f);
	}

	else if (m_eButtonType == EButtonType::IncArrivalWeighting)
	{
		CAgentBehaviourValues::SetArrivalWeighting(CAgentBehaviourValues::GetArrivalWeighting() + 0.05f);
	}

	else if (m_eButtonType == EButtonType::DecArrivalStrength)
	{
		CAgentBehaviourValues::SetArrivalStrength(CAgentBehaviourValues::GetArrivalStrength() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncArrivalStrength)
	{
		CAgentBehaviourValues::SetArrivalStrength(CAgentBehaviourValues::GetArrivalStrength() + 1.0f);
	}

	else if (m_eButtonType == EButtonType::DecArrivalMSF)
	{
		CAgentBehaviourValues::SetArrivalMaxSteerForce(CAgentBehaviourValues::GetArrivalMaxSteerForce() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncArrivalMSF)
	{
		CAgentBehaviourValues::SetArrivalMaxSteerForce(CAgentBehaviourValues::GetArrivalMaxSteerForce() + 1.0f);
	}

	else if (m_eButtonType == EButtonType::DecArrivalStoppingRadius)
	{
		CAgentBehaviourValues::SetArrivalStoppingRadius(CAgentBehaviourValues::GetArrivalStoppingRadius() - 5.0f);
	}

	else if (m_eButtonType == EButtonType::IncArrivalStoppingRadius)
	{
		CAgentBehaviourValues::SetArrivalStoppingRadius(CAgentBehaviourValues::GetArrivalStoppingRadius() + 5.0f);
	}

	//------------------------------------------------------------------------------------------------------------SEEK
	else if (m_eButtonType == EButtonType::DecSeekWeighting)
	{
		CAgentBehaviourValues::SetSeekWeighting(CAgentBehaviourValues::GetSeekWeighting() - 0.05f);
	}

	else if (m_eButtonType == EButtonType::IncSeekWeighting)
	{
		CAgentBehaviourValues::SetSeekWeighting(CAgentBehaviourValues::GetSeekWeighting() + 0.05f);
	}

	else if (m_eButtonType == EButtonType::DecSeekStrength)
	{
		CAgentBehaviourValues::SetSeekStrength(CAgentBehaviourValues::GetSeekStrength() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncSeekStrength)
	{
		CAgentBehaviourValues::SetSeekStrength(CAgentBehaviourValues::GetSeekStrength() + 1.0f);
	}

	else if (m_eButtonType == EButtonType::DecSeekMSF)
	{
		CAgentBehaviourValues::SetSeekMaxSteerForce(CAgentBehaviourValues::GetSeekMaxSteerForce() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncSeekMSF)
	{
		CAgentBehaviourValues::SetSeekMaxSteerForce(CAgentBehaviourValues::GetSeekMaxSteerForce() + 1.0f);
	}

	//------------------------------------------------------------------------------------------------------------WANDER
	else if (m_eButtonType == EButtonType::DecWanderWeighting)
	{
		CAgentBehaviourValues::SetWanderWeighting(CAgentBehaviourValues::GetWanderWeighting() - 0.05f);
	}

	else if (m_eButtonType == EButtonType::IncWanderWeighting)
	{
		CAgentBehaviourValues::SetWanderWeighting(CAgentBehaviourValues::GetWanderWeighting() + 0.05f);
	}

	else if (m_eButtonType == EButtonType::DecWanderStrength)
	{
		CAgentBehaviourValues::SetWanderStrength(CAgentBehaviourValues::GetWanderStrength() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncWanderStrength)
	{
		CAgentBehaviourValues::SetWanderStrength(CAgentBehaviourValues::GetWanderStrength() + 1.0f);
	}

	else if (m_eButtonType == EButtonType::DecWanderMSF)
	{
		CAgentBehaviourValues::SetWanderMaxSteerForce(CAgentBehaviourValues::GetWanderMaxSteerForce() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncWanderMSF)
	{
		CAgentBehaviourValues::SetWanderMaxSteerForce(CAgentBehaviourValues::GetWanderMaxSteerForce() + 1.0f);
	}

	else if (m_eButtonType == EButtonType::DecWanderRadius)
	{
		CAgentBehaviourValues::SetWanderRadius(CAgentBehaviourValues::GetWanderRadius() - 5.0f);
	}

	else if (m_eButtonType == EButtonType::IncWanderRadius)
	{
		CAgentBehaviourValues::SetWanderRadius(CAgentBehaviourValues::GetWanderRadius() + 5.0f);
	}

	else if (m_eButtonType == EButtonType::DecWanderDistance)
	{
		CAgentBehaviourValues::SetWanderDistance(CAgentBehaviourValues::GetWanderDistance() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncWanderDistance)
	{
		CAgentBehaviourValues::SetWanderDistance(CAgentBehaviourValues::GetWanderDistance() + 1.0f);
	}

	//------------------------------------------------------------------------------------------------------------SEPARATION
	else if (m_eButtonType == EButtonType::DecSeparationWeighting)
	{
		CAgentBehaviourValues::SetSeparationWeighting(CAgentBehaviourValues::GetSeparationWeighting() - 0.05f);
	}

	else if (m_eButtonType == EButtonType::IncSeparationWeighting)
	{
		CAgentBehaviourValues::SetSeparationWeighting(CAgentBehaviourValues::GetSeparationWeighting() + 0.05f);
	}

	else if (m_eButtonType == EButtonType::DecSeparationStrength)
	{
		CAgentBehaviourValues::SetSeparationStrength(CAgentBehaviourValues::GetSeparationStrength() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncSeparationStrength)
	{
		CAgentBehaviourValues::SetSeparationStrength(CAgentBehaviourValues::GetSeparationStrength() + 1.0f);
	}

	else if (m_eButtonType == EButtonType::DecSeparationMSF)
	{
		CAgentBehaviourValues::SetSeparationMaxSteerForce(CAgentBehaviourValues::GetSeparationMaxSteerForce() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncSeparationMSF)
	{
		CAgentBehaviourValues::SetSeparationMaxSteerForce(CAgentBehaviourValues::GetSeparationMaxSteerForce() + 1.0f);
	}

	else if (m_eButtonType == EButtonType::DecSeparationNHR)
	{
		CAgentBehaviourValues::SetSeparationNeighbourhoodRadius(CAgentBehaviourValues::GetSeparationNeighbourhoodRadius() - 5.0f);
	}

	else if (m_eButtonType == EButtonType::IncSeparationNHR)
	{
		CAgentBehaviourValues::SetSeparationNeighbourhoodRadius(CAgentBehaviourValues::GetSeparationNeighbourhoodRadius() + 5.0f);
	}

	//------------------------------------------------------------------------------------------------------------COHESION
	else if (m_eButtonType == EButtonType::DecCohesionWeighting)
	{
		CAgentBehaviourValues::SetCohesionWeighting(CAgentBehaviourValues::GetCohesionWeighting() - 0.05f);
	}

	else if (m_eButtonType == EButtonType::IncCohesionWeighting)
	{
		CAgentBehaviourValues::SetCohesionWeighting(CAgentBehaviourValues::GetCohesionWeighting() + 0.05f);
	}

	else if (m_eButtonType == EButtonType::DecCohesionStrength)
	{
		CAgentBehaviourValues::SetCohesionStrength(CAgentBehaviourValues::GetCohesionStrength() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncCohesionStrength)
	{
		CAgentBehaviourValues::SetCohesionStrength(CAgentBehaviourValues::GetCohesionStrength() + 1.0f);
	}

	else if (m_eButtonType == EButtonType::DecCohesionMSF)
	{
		CAgentBehaviourValues::SetCohesionMaxSteerForce(CAgentBehaviourValues::GetCohesionMaxSteerForce() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncCohesionMSF)
	{
		CAgentBehaviourValues::SetCohesionMaxSteerForce(CAgentBehaviourValues::GetCohesionMaxSteerForce() + 1.0f);
	}

	else if (m_eButtonType == EButtonType::DecCohesionNHR)
	{
		CAgentBehaviourValues::SetCohesionNeighbourhoodRadius(CAgentBehaviourValues::GetCohesionNeighbourhoodRadius() - 5.0f);
	}

	else if (m_eButtonType == EButtonType::IncCohesionNHR)
	{
		CAgentBehaviourValues::SetCohesionNeighbourhoodRadius(CAgentBehaviourValues::GetCohesionNeighbourhoodRadius() + 5.0f);
	}

	else if (m_eButtonType == EButtonType::ToggleCohesionIncludeSelf)
	{
		CAgentBehaviourValues::SetCohesionIncludeSelf(!CAgentBehaviourValues::GetCohesionIncludeSelf());
	}

	//------------------------------------------------------------------------------------------------------------ALIGNMENT
	else if (m_eButtonType == EButtonType::DecAlignmentWeighting)
	{
		CAgentBehaviourValues::SetAlignmentWeighting(CAgentBehaviourValues::GetAlignmentWeighting() - 0.05f);
	}

	else if (m_eButtonType == EButtonType::IncAlignmentWeighting)
	{
		CAgentBehaviourValues::SetAlignmentWeighting(CAgentBehaviourValues::GetAlignmentWeighting() + 0.05f);
	}

	else if (m_eButtonType == EButtonType::DecAlignmentStrength)
	{
		CAgentBehaviourValues::SetAlignmentStrength(CAgentBehaviourValues::GetAlignmentStrength() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncAlignmentStrength)
	{
		CAgentBehaviourValues::SetAlignmentStrength(CAgentBehaviourValues::GetAlignmentStrength() + 1.0f);
	}

	else if (m_eButtonType == EButtonType::DecAlignmentMSF)
	{
		CAgentBehaviourValues::SetAlignmentMaxSteerForce(CAgentBehaviourValues::GetAlignmentMaxSteerForce() - 1.0f);
	}

	else if (m_eButtonType == EButtonType::IncAlignmentMSF)
	{
		CAgentBehaviourValues::SetAlignmentMaxSteerForce(CAgentBehaviourValues::GetAlignmentMaxSteerForce() + 1.0f);
	}

	else if (m_eButtonType == EButtonType::DecAlignmentNHR)
	{
		CAgentBehaviourValues::SetAlignmentNeighbourhoodRadius(CAgentBehaviourValues::GetAlignmentNeighbourhoodRadius() - 5.0f);
	}

	else if (m_eButtonType == EButtonType::IncAlignmentNHR)
	{
		CAgentBehaviourValues::SetAlignmentNeighbourhoodRadius(CAgentBehaviourValues::GetAlignmentNeighbourhoodRadius() + 5.0f);
	}
	#pragma endregion

	else if (m_eButtonType == EButtonType::ToggleGizmos)
	{
		CGizmos::ToggleGizmos();

		if (CGizmos::GetGizmosEnabled() == true)
		{
			m_poButtonText->SetString("Disable");
		}

		else
		{
			m_poButtonText->SetString("Enable");
		}
	}
}

void CUIButton::SetupButton(sf::Vector2f _v2fSize, sf::Vector2f _v2fPosition, EButtonType _eButtonType, EAlignment _eAlignment, bool _bEnabled)
{
	m_oButtonShape.setSize(_v2fSize);
	SetElementAlignment(&m_oButtonShape, _eAlignment, _v2fPosition);
	m_oButtonShape.setFillColor(sf::Color::White);
	m_eButtonType = _eButtonType;
	m_bEnabled = _bEnabled;

	CUIManager::AddToButtonVector(this);
}