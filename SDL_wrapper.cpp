#include "stdafx.h"
#include "SDL_wrapper.h"


SDL_Renderer* SDL_wrapper::gRenderer = nullptr;

SDL_DisplayMode SDL_wrapper::displayMode;

b2World* SDL_wrapper::world = new b2World( b2Vec2( 0.0f, 10.0f ) );


SDL_wrapper::SDL_wrapper()
{

}


bool SDL_wrapper::quit = false;
//std::unique_ptr<SDL_wrapper> SDL_wrapper::Game = std::make_unique<SDL_wrapper>();
std::shared_ptr< SDL_wrapper > SDL_wrapper::hInstance(nullptr);
std::vector< std::shared_ptr< Body > > SDL_wrapper::GameBodys;
//std::shared_ptr< EventHandle > SDL_wrapper::eventHandler = std::make_shared< EventHandle >();



void SDL_wrapper::onMouseButtonEvent(int x, int y, bool isReleased, int button)
{


}


std::shared_ptr<SDL_wrapper> SDL_wrapper::Instance()
{
	if (!hInstance)
	{
		hInstance = std::make_unique< SDL_wrapper >();
	}
	return hInstance;
}

void SDL_wrapper::GameDraw()
{
	SDL_SetRenderDrawColor(SDL_wrapper::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(SDL_wrapper::gRenderer);


	box->Draw();
	dybox->Draw();
	dybox2->Draw();


	SDL_RenderPresent(SDL_wrapper::gRenderer);
}

bool SDL_wrapper::GameInit()
{

	SDL_wrapper::Instance();


	if (!Instance()->Init())
	{

		printf("Failed to initialize!\n");

		return 0;

	}

	if (!Instance()->loadMedia())
	{

		printf("Failed to load media!\n");

		return 0;

	}

	//b2Vec2 gravity( 0.0f, -10.0f );
	//
	//world = new b2World( gravity );


	TriggersManager::Instance();

	SoundManager::Instance();
	SoundManager::Instance()->loadSounds();

	box = std::make_shared< Body >();
	dybox = std::make_shared< dynBody >( 3.0f, 1.0f, TextureManager::getTexture("box.jpg"), 0.65f, 0.3f );
	dybox2 = std::make_shared< dynBody >( 2.0f, 2.0f, TextureManager::getTexture("box.jpg"), 0.65f, 0.3f );
	//phObj = std::make_shared< phBody >( 10, 20, std::make_shared< b2Vec2 >( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 ), TextureManager::getTexture("Puck.png") );
	//phObj1 = std::make_shared< phBody >( 10, 20, std::make_shared< b2Vec2 >( SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 ), TextureManager::getTexture("Puck.png"));

	return 1;

}

void SDL_wrapper::GameTick()
{

	world->Step( timeStep, velocityIterations, positionIterations );

}

void SDL_wrapper::GameReset()
{

}




SDL_wrapper::~SDL_wrapper()
{
	delete world;
}


bool SDL_wrapper::Init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;

	}
	else
	{
		if ( SDL_GetDesktopDisplayMode( 0, &displayMode ) != 0)
		{
			success = false;
		}

		//Create window
		gWindow = SDL_CreateWindow("Air Hockey", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		

		if (gWindow == NULL)
		{

			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;

		}
		else
		{

			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}


			int imgFlags = IMG_INIT_PNG;

			if ( !( IMG_Init(imgFlags) & imgFlags ) )
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}

			if (TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf error: %s\n", TTF_GetError());
				success = false;

			}
			
			if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
			{
				printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
				success = false;
			}

			TimerIns::Instance();
			TextureManager::Initialize();

		}


	}

	return success;
}


bool SDL_wrapper::loadMedia()
{
	bool success = true;

	return success;
}

void SDL_wrapper::drawRect(std::shared_ptr<b2AABB> rect, const SDL_Color & color)
{

		//SDL_Rect r = rect->convertToSDLRect();
		SDL_SetRenderDrawBlendMode( SDL_wrapper::gRenderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor( SDL_wrapper::gRenderer, color.r, color.g, color.b, color.a);
		//SDL_RenderDrawRect(SDL_wrapper::gRenderer, &r);
		SDL_SetRenderDrawBlendMode(SDL_wrapper::gRenderer, SDL_BLENDMODE_NONE);
		SDL_SetRenderDrawColor(SDL_wrapper::gRenderer, 255, 255, 255, 255);

}

void SDL_wrapper::close()
{

	delete TextureManager::Initialize();
	delete TriggersManager::Instance();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}



