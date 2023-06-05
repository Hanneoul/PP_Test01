#include <stdio.h>
#include <Windows.h>
#include "screen.h"
#include "util.h"



struct SnakeBody
{
	int posX;
	int posY;
	int active;
};

#define BODY_LENGTH 1400

int Initialize();
int Release();
int DrawBuffer();

int GameState = 0;

struct SnakeBody skin[BODY_LENGTH];

int snakeBodyLength = 2;



int main()
{
	int isGameRunning = 1;
	
	CHECKERROR(Initialize());
	
	unsigned long time_end = GetTickCount();
	unsigned long deltaTime = GetTickCount();

	while(isGameRunning)
	{
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
	snakeBodyLength = 2;
	int i = 0;
	while(i< BODY_LENGTH)
	{
		skin[i].active = 0;
		skin[i].posX = 35;
		skin[i].posY = 10;

		i = i+1;
	}

	snakeBodyLength = 2;
	i = 0;
	while (i < snakeBodyLength)
	{
		skin[i].active = 1;
		skin[i].posX = 35;
		skin[i].posY = 10 - i;

		i = i + 1;
	}
	setScreenSize(70, 20);	
	setCursorIcon(0);
	ClearBuffer();	

	return 0;
}

int Release()
{
	return 0;
}

int DrawBuffer()
{
	SetColor(0b0011, 0b0111);
	setCursorPos(0, 0);
	printf("%s", ScreenBuffer);
	
	SetColor(0b0011, 0b1101);	
	int i = 0;
	while (i < snakeBodyLength)
	{
		setCursorPos(skin[i].posX, skin[i].posY);
		printf("*");
		i = i + 1;
	}

	SetColor(0b0000, 0b0111);
	setCursorPos(0, 22);


	return 0;
}