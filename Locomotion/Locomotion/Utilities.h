/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : Utilities.h
Description : Static class containing various utility functions.
Author : Connor Galvin
Mail : Connor.Galvin@mds.ac.nz
**************************************************************************/

#pragma once
#include <string>

class CUtilities
{
public:
	/// <summary>
	/// Returns a copy of a string by converting a given float with a provided number of decimals.
	/// </summary>
	/// <param name="_fValue:">The float to convert.</param>
	/// <param name="_iDecimals:">The number of decimals to keep.</param>
	/// <returns>A copy of a string by converting a given float with a provided number of decimals.</returns>
	static std::string FloatToString(float _fValue, int _iDecimals);

private:
	CUtilities() = delete;
	~CUtilities() = delete;
};