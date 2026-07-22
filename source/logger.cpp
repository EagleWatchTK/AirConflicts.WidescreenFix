#include "Logger.h"

#include <fstream>

void Log(const char* text)
{
    std::ofstream file("WidescreenFix.log", std::ios::app);

    if (file.is_open())
    {
        file << text << std::endl;
        file.close();
    }
}