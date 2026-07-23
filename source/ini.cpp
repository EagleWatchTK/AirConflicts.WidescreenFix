#include "Ini.h"
#include "Logger.h"

#include <windows.h>
#include <cstring>

Resolution gResolution =
{
    111,
    222
};

void LoadIni()
{
    char path[MAX_PATH];

    GetModuleFileNameA(
        NULL,
        path,
        MAX_PATH);

    char* slash = strrchr(path, '\\');

    if (slash)
        *(slash + 1) = '\0';

    strcat_s(path, "WidescreenFix.ini");

    gResolution.Width = GetPrivateProfileIntA(
        "MAIN",
        "Width",
        1920,
        path);

    gResolution.Height = GetPrivateProfileIntA(
        "MAIN",
        "Height",
        1080,
        path);

    char buffer[128];

    wsprintfA(buffer,
        "INI = %s",
        path);

    Log(buffer);

    wsprintfA(buffer,
        "Width = %d",
        gResolution.Width);

    Log(buffer);

    wsprintfA(buffer,
        "Height = %d",
        gResolution.Height);

    Log(buffer);
}