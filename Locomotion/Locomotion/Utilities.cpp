#include "Utilities.h"

std::string CUtilities::FloatToString(float _fValue, int _iDecimals)
{
	std::string sValue = std::to_string(_fValue);

	bool bPointFound = false;

	for (size_t i = 0; i < sValue.size(); i++)
	{
		if (sValue[i] == '.')
		{
			bPointFound = true;
			int iStringLength = i + _iDecimals + 1;

			if (_iDecimals == 0)
			{
				iStringLength = i;
			}

			std::string sFinalString = sValue.substr(0, iStringLength);

			return sFinalString;
		}
	}

	return sValue;
}