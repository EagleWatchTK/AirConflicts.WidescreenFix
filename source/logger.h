#pragma once

void Log(const char* text);

void LogHex(const char* title, const unsigned char* data, int size);

void LogAddress(const char* title, void* address);