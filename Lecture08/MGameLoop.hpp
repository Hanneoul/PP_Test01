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
			std::cout << "�ʱ�ȭ �Ϸ�" << std::endl;
		}

		void Release()
		{
			std::cout << "�ý��� ���� �Ϸ�" << std::endl;
		}

		void Update()
		{
			std::cout << "������Ʈ�� �Ϸ�" << std::endl;

			if (_kbhit())
			{
				keyEvent(_getch());
				
					
			}
		}
		void Render()
		{
			std::cout << "������ �Ϸ�" << std::endl;
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