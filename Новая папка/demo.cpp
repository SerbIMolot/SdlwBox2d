#include "stdafx.h"

int main(int argc, char *argv[])
{

	//SDL_wrapper::Instance()->Init();

	if (SDL_wrapper::Instance()->GameInit())
	{

		TimerIns::Instance()->Reset();


		while (!SDL_wrapper::Instance()->quit)
		{


			TimerIns::Instance()->Update();



			SDL_wrapper::Instance()->GameDraw();

			SDL_wrapper::Instance()->GameTick();


		}

	}



	SDL_wrapper::Instance()->close();

	return 0;
}



