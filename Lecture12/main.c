#include <stdio.h>
#include <Windows.h>
#include "screen.h"
#include "util.h"

int Initialize();
int Release();
int DrawBuffer();


int GameState = 0;

int main()
{
	int isGameRunning = 1;
	
	CHECKERROR(Initialize());
	
	unsigned long time_end = GetTickCount();
	unsigned long deltaTime = GetTickCount();

	while(isGameRunning)
	{
		
		SetColor(0b1000, 0b1111);

		WriteToBuffer(25, 10, "게임의 제목은 없다");
		WriteToBuffer(25, 12, "1. 게임시작");
		WriteToBuffer(25, 13, "2. 게임종료");

		DrawBuffer();
		deltaTime = GetTickCount() - time_end;
		time_end = GetTickCount();
		if(deltaTime < 33)
			Sleep(33- deltaTime);
		
		if(deltaTime !=0)
			printf("time : %d \nfps :%d\n", deltaTime, 1000 / deltaTime);
		
	}

	CHECKERROR(Release());

	exit(1);
	return 0;
}

int Initialize()
{
	GameState = 0;
	setScreenSize(70, 20);	
	
	ClearBuffer();	

	return 0;
}

int Release()
{
	return 0;
}

int DrawBuffer()
{
	setCursorPos(0, 0);
	printf("%s", ScreenBuffer);
	return 0;
}