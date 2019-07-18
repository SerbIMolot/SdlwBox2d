#pragma once
#define PtMratio 0.02f
#define MtPratio 50.0f
#define RtDratio 180.0f / 3.141592653589793238463f 
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;
const float timeStep = 1.0f / 60.0f;
const int velocityIterations = 6;
const int positionIterations = 2;

class SDL_wrapper
{
public:
	SDL_Window* gWindow = NULL;

	std::shared_ptr< Body > box;
	std::shared_ptr< dynBody > dybox;
	std::shared_ptr< dynBody > dybox2;
	static std::vector< std::shared_ptr< Body > > GameBodys;
//	static std::shared_ptr< EventHandle > eventHandler;
	//static std::unique_ptr<SDL_wrapper> Game;
	static std::shared_ptr<SDL_wrapper> hInstance;

	static bool quit;

	static b2World* world;

	static SDL_Renderer* gRenderer;

	static SDL_DisplayMode displayMode;

	static void drawRect(std::shared_ptr<b2AABB> rect, const SDL_Color & color);


	
	//starts SDL and creates window
	bool Init();
	//load media
	bool loadMedia();
	

	static std::shared_ptr<SDL_wrapper> Instance();

	void GameDraw();

	bool GameInit();

	void GameTick();

	void GameReset();

	void onMouseButtonEvent(int x, int y, bool isReleased, int button);



	//Frees media and shots down sdl
	void close();

	SDL_wrapper();
	~SDL_wrapper();
};

