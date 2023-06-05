#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "screen.h"
#include "util.h"

int Initialize();
int Release();
int DrawBuffer(int DeltaTime);

//게임스테이트가 0일때 무조건 게임 종료
int GameState;
int GameStartSnakeLength;
int ActiveSnakeNum;

#define MAX_SNAKE_LENGTH 1400
struct GameObject
{
	int posX;
	int posY;
	int isActive;
};

//0번이 머리
struct GameObject snakeSkin[MAX_SNAKE_LENGTH];
struct GameObject apple;

int main()
{
	CHECKERROR(Initialize());
	
	unsigned long time_end = GetTickCount();
	unsigned long deltaTime = GetTickCount();

	while(GameState)
	{
		deltaTime = GetTickCount() - time_end;
		time_end = GetTickCount();
		
		DrawBuffer(deltaTime);

		if(deltaTime < 33)
			Sleep(33- deltaTime);
	}

	CHECKERROR(Release());

	exit(1);
	return 0;
}

void InitApple()
{
	//apple 초기화
	srand(time(NULL));
	apple.posX = rand() % 70;
	apple.posY = rand() % 20;
	apple.isActive = 1;
}

int Initialize()
{
	GameState = 1;
	GameStartSnakeLength = 3;
	ActiveSnakeNum = GameStartSnakeLength;
	setScreenSize(70, 20);	
	setCursorVisibility(0);
	SetColor(0b1000, 0b1111);
	ClearBuffer();	

	//GameObject 초기화

	//사과 초기화
	InitApple();
	int i = 0;
	while (i < GameStartSnakeLength)
	{
		if (snakeSkin[i].posX == apple.posX
			&& snakeSkin[i].posY == apple.posY)
		{
			InitApple();
			i = 0;
		}
		else
		{
			i = i + 1;
		}
	}
	
	//뱀 몸뚱아리 초기화
	i = 0;
	while (i < MAX_SNAKE_LENGTH)
	{
		snakeSkin[i].posX = 35;
		snakeSkin[i].posY = 10;
		snakeSkin[i].isActive = 0;
		i=i+1;
	}

	i = 0;
	while (i < GameStartSnakeLength)
	{
		snakeSkin[i].posX = 35-i;
		snakeSkin[i].posY = 10;
		snakeSkin[i].isActive = 1;
		i = i + 1;
	}

	return 0;
}

int Release()
{
	return 0;
}

//dir : 좌우
void MoveSnake(int dir)
{
	//몸통이동 부분
	int i = GameStartSnakeLength - 1;
	while (i > 0)
	{
		snakeSkin[i].posX = snakeSkin[i - 1].posX;
		snakeSkin[i].posY = snakeSkin[i - 1].posY;
		i = i - 1;
	}
	//머리 이동부분
	snakeSkin[0].posX = snakeSkin[0].posX+1;
	snakeSkin[0].posY = snakeSkin[0].posY;
}

int DeltaTimeSum = 0;


int DrawBuffer(int DeltaTime)
{
	setCursorPos(0, 0);
	SetColor(0b1111, 0b0000);
	printf("%s", ScreenBuffer);

	DeltaTimeSum = DeltaTimeSum + DeltaTime;
	if (DeltaTimeSum >= 500)
	{
		MoveSnake(0);
		DeltaTimeSum = 0;
	}


	//apple
	setCursorPos(apple.posX, apple.posY);
	SetColor(0b1111, 0b0100);
	printf("*");

	//snake
	int i = 0;
	while (i < GameStartSnakeLength)
	{
		setCursorPos(snakeSkin[i].posX, snakeSkin[i].posY);
		SetColor(0b1111, 0b0010);
		printf("O");
		i = i + 1;
	}
	
	SetColor(0b0000, 0b1111);
	setCursorPos(0, 22);
	if (DeltaTime != 0)
		printf("time : %d                 \nfps :%d                  \n", DeltaTime, 1000 / DeltaTime);

	return 0;
}