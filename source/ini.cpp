#include "Ini.h"
#include "Logger.h"

#include <windows.h>
#include <cstdio>

Resolution gResolution =
{
    1920,
    1080
};

void LoadIni()
{
    gResolution.Width = GetPrivateProfileIntA(
        "MAIN",
        "Width",
        1920,
        ".\\WidescreenFix.ini");

    gResolution.Height = GetPrivateProfileIntA(
        "MAIN",
        "Height",
        1080,
        ".\\WidescreenFix.ini");

    char buffer[128];

    sprintf_s(buffer, "Width = %d", gResolution.Width);
    Log(buffer);

    sprintf_s(buffer, "Height = %d", gResolution.Height);
    Log(buffer);
}