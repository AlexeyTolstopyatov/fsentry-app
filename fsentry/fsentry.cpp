#include <iostream>
#include <windows.h>

#include "fsprocessing.h"
#include "fstrings.h"
#include "fconsts.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    int result = 0;
    std::wstring cat = L"";


    switch (argc)
    {
        // same logic, but verbose mode shows extra information. //
    case 2:
        cat    = CFileString::GetWideString(argv[1]);

        // if argument equals root of schema -> get drives information
        (cat == WIDE_FSROOT || cat == WIDE_FSROOT_NORMALIZED) ?
            result = CFileSystem::GetDrivesInformation() :
            result = CFileSystem::GetFileSystemEntries(cat);


        result = CFileSystem::GetFileSystemEntries(cat);
        
        if (result > 0)
            std::cout 
                << "[X] Incorrect"
                << std::endl;
        break;

    case 3:
        cat = CFileString::GetWideString(argv[1]);

        // if argument equals root of schema -> get drives information
        (cat == WIDE_FSROOT || cat == WIDE_FSROOT_NORMALIZED) ?
            result = CFileSystem::GetDrivesInformation() :
            result = CFileSystem::GetFileSystemEntries(cat);

        if (argv[2][0] == '+')
        {
            std::cout
                << "[i] Pointer address "
                << &argv[1]
                << std::endl;

            if (result > 0)
            {
                std::cout
                    << "[X] Failed to initialize HANDLE." 
                    << std::endl
                    << "HANDLE ERROR " 
                    << result
                    << std::endl;
            }
        }
        break;

    default:
        std::cout
            << "\nArguments syntax:\n"
            << "fsentry [long path] (without '\\') -- Standard mode\n"
            << "fsentry [long path] + -- Verbose mode\n"
            << "\nexample:\n./fsentry \\\\?\\C:\\ \n"
            << "./fsentry \\\\?\\C:\\ +";
        break;
    }
    return result;
}
