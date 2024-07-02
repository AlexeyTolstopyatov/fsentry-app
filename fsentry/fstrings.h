#include <string>
#include <iostream>
#include <windows.h>

class CFileString 
{
public:

	// Transforms the C-like String to Unicode string.
	// RETURNS: wstring-object
	static std::wstring GetWideString(char cstr[]);
};