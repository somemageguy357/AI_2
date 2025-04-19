#pragma once
#include <string>

class CUtilities
{
public:
	static std::string FloatToString(float _fValue, int _iDecimals);

private:
	CUtilities() = delete;
	~CUtilities() = delete;
};