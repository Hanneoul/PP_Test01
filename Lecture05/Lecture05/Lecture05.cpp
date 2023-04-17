//#define DEBUG
#include <iostream>
#include <conio.h>
#include <Windows.h>

char** map = NULL;
int stage_width = 15;
int stage_height = 15;

// game_state == 0 일때
int print_title_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*              지렁이 게임               *" << std::endl;
    std::cout << "*             (Snake  Bite)              *" << std::endl;

#ifdef DEBUG
    std::cout << "*            - 디버그 모드 -             *" << std::endl;
#else
    std::cout << "*                                        *" << std::endl;
#endif  
    std::cout << "*   1. 게임 시작                         *" << std::endl;
    std::cout << "*   2. 게임 설명                         *" << std::endl;
    std::cout << "*   3. 게임 랭킹 보기                    *" << std::endl;
    std::cout << "*   4. 게임 종료 (esc)                   *" << std::endl;
    std::cout << "******************************************" << std::endl;

    return 0;
}

void gotoxy(int x, int y) {
    //x, y 좌표 설정
    COORD pos = { x,y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



int InitMap()
{
    if (map == nullptr)
    {
        map = (char**)malloc(sizeof(char*) * stage)

        for (int i = 0; i < stage_height; i++)
        {
            map[i] = new char[stage_width];
        }
    }
    return 0;
}

int ReleaseMap()
{
    for (int i = 0; i < stage_height; i++)
    {
        delete[] map[i];
    }

    delete[] * map;
    return 0;
}

int print_game_screen()
{
    if (map == NULL)
    {
        InitMap();
    }

    gotoxy(0, 0);

    for (int j = 0; j < stage_height + 2; j++)
    {
        for (int i = 0; i < stage_width + 2; i++)
        {
            if(i>1 || i< stage_width +1)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }


    

    
    


    return 0;
}

// game_state == 2 일때
int print_introduction_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "타이틀화면으로 돌아갈까요? (Y/N)" << std::endl;
    return 0;
}

int main()
{
    /*
     * GameState
     * 0 : 게임 종료
     * 1 : 시작 화면
     * 2 : 게임 설명
     * 3 : 게임 랭킹
     */

    int game_state = 1;

    InitMap();

    while (game_state)
    {
        switch (game_state)
        {
        case 0:
            
            break;
        case 1:
            print_title_screen();
            int sub_title_state = 1;
            while (sub_title_state)
            {
                char key_input = _getch();
                switch(key_input)
                {
                case 0:
                    game_state = 0;
                    break;
                case 1:
                    game_state = 1;
                    break;
                case 2:
                    game_state = 2;
                    break;
                case 3:
                    game_state = 3;
                   break;
                default:
                    break;
                }
            }
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }
    }

    return 0;
}
/*
    

    while (is_game_running)
    {   
        char key_input = '0';
        switch (game_state)
        {
        case 0:
            print_title_screen();
            key_input = _getch();
            switch(key_input)
            {
            case '1':
                game_state = 1;
                break;
            case '2':
                game_state = 2;
                break;
            case '3':
                break;
            case '4':
                is_game_running = 0;
                break;
            case 27:
                is_game_running = 0;
                break;
            default:
                break;
            }
            break;
        case 1:
            print_game_screen();
            key_input = _getch();
            break;
        case 2:
            print_introduction_screen();
            key_input = _getch();
            switch (key_input)
            {
            case 'y':
                game_state = 0;
                break;
            case 'n':
                break;
            default:
                break;
            }
            break;
        
        default:
            break;
        }     
        
        
    }

    if (map != NULL)
    {
        ReleaseMap();
    }

    return 0;
}
*/