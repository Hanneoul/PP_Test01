#pragma once // #define _IS_THIS_HEADER_INCLUDED


namespace MuSoeun
{
	class MGameLoop
	{
	public :

		bool isGameRunning = false;

		MGameLoop(){}
		~MGameLoop(){}

		void Initialize()
		{
			isGameRunning = true;
			std::cout << "초기화 완료" << std::endl;
		}

		void Release()
		{
			std::cout << "시스템 해제 완료" << std::endl;
		}

		void Update()
		{
			std::cout << "업데이트중 완료" << std::endl;

			if (_kbhit())
			{
				keyEvent(_getch());
				
					
			}
		}
		void Render()
		{
			std::cout << "렌더링 완료" << std::endl;
		}

		void Run()
		{
			Initialize();

			while (isGameRunning)
			{
				Update();	
				Render();
			}

			Release();
			
		}

		void keyEvent(char KeyInput)
		{

		}
	};
}