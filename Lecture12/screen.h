#pragma once

char ScreenBuffer[65536];

void setScreenSize(int width, int height);
void setCursorPos(int x, int y);
void setCursorVisibility(int isVisible);
void SetColor(unsigned short backgroundColor, unsigned short textColor);

void ClearBuffer();
int WriteToBuffer(int x, int y, const char* str);


