#pragma once
#include <windows.h>
#include <winnetwk.h>
#include <iostream>

// Implementation of some operations with file system, using Windows API.
class CFileSystem 
{
public:
	// Searches files and directories, using yuor target (address)
	// RETURNS: Completition status 
	static int GetFileSystemEntries(std::wstring catalog);
	
	// Searches all Network entries
	// RETURNS: Completition status
	static int GetNetworkEntries(std::wstring netcat);
	
	// Searches and writes all alternative data streams, using your target
	// RETURNS: Completition status
	static int GetAlternateDataStreams(std::wstring catalog);
	
	// Searches names and labels of all drives
	// RETURNS: Completition status
	static int GetDrivesInformation();

private:
	
	// i dont know: need it or not.
	static BOOL CALLBACK EnumerateNextEntry
	(
		HANDLE hNet,
		LPVOID next,
		LPWSTR name,
		LONG type,
		LPWSTR comment,
		LPARAM context
	);
};

