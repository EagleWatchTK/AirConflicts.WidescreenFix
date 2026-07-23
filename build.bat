@echo off

call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\Common7\Tools\VsDevCmd.bat"

cl /EHsc /LD ^
source\dllmain.cpp ^
source\Logger.cpp ^
source\Ini.cpp ^
source\Memory.cpp ^
source\Hook.cpp ^
source\ResolutionHook.cpp ^
source\Trampoline.cpp ^
source\globals.cpp ^
source\patches.cpp ^
/link ^
/OUT:AirConflicts.WidescreenFix.asi ^
user32.lib

pause