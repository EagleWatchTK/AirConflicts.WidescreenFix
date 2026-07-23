#include <windows.h>
#include "Logger.h"

#include <fstream>
#include <iomanip>

void Log(const char* text)
{
    std::ofstream file("WidescreenFix.log", std::ios::app);

    if (file.is_open())
    {
        file << text << std::endl;
        file.close();
    }
}

void LogHex(const char* title, const unsigned char* data, int size)
{
    std::ofstream file("WidescreenFix.log", std::ios::app);

    if (!file.is_open())
        return;

    file << title << std::endl;

    for (int i = 0; i < size; i++)
    {
        file << std::hex
             << std::uppercase
             << std::setw(2)
             << std::setfill('0')
             << (int)data[i]
             << ' ';
    }

    file << std::endl;

    file.close();
}

void LogAddress(const char* title, void* address)
{
    char buffer[128];

    wsprintfA(buffer, "%s 0x%p", title, address);

    Log(buffer);
}