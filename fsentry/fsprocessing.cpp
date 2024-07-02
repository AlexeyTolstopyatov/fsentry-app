#include "fsprocessing.h"

int CFileSystem::GetFileSystemEntries(std::wstring catalog)
{
    WIN32_FIND_DATAW wfd;
    HANDLE hFind = FindFirstFileW
    (
        (catalog + L"\\*").c_str(),
        &wfd
    );

    if (hFind == INVALID_HANDLE_VALUE)
        return 1;

    while (FindNextFileW(hFind, &wfd) != NULL)
    {
        std::wcout << &wfd.cFileName[0] << std::endl;
    }

    FindClose(hFind);

    return 0;
}

int CFileSystem::GetDrivesInformation()
{
    DWORD result; 
    HANDLE hDrives;

    return 0;
}

int CFileSystem::GetNetworkEntries(std::wstring netcat)
{
    HANDLE hFind;
    DWORD result = 0;
    DWORD type   = RESOURCETYPE_ANY;
    DWORD scope  = RESOURCE_GLOBALNET;
    DWORD usage  = 0;

    result = WNetOpenEnumW(scope, type, usage, NULL, &hFind);

    if (result != NO_ERROR)
        return (int)result;

    while (1)
    {
        result = WNetEnumResourceW(hFind, &type, NULL, NULL);

        if (result == ERROR_NO_MORE_ITEMS)
            break;

        if (result != NO_ERROR)
            break;

        std::wcout
            << result
            << std::endl;
    }

    return 0;
}

int CFileSystem::GetAlternateDataStreams(std::wstring catalog)
{
    int result = 0;

    HANDLE hStream;
    WIN32_FIND_STREAM_DATA data;

    hStream = FindFirstStreamW();

    if (hStream == INVALID_HANDLE_VALUE)
    {
        result -= 1;
        return result;
    }

    while (FindNextStreamW(hStream, &data) != 0)
    {
        std::wcout
            << data.cStreamName
            << std::endl; 
    }

    return result;
}

// Based on Handle, searches next network item.
// Returns ???
BOOL CALLBACK CFileSystem::EnumerateNextEntry
(
    HANDLE hNet,
    LPVOID next,
    LPWSTR name,
    LONG   type,
    LPWSTR comment,
    LPARAM context
)
{
    std::wcout
        << name
        << std::endl;

    return 0;
}