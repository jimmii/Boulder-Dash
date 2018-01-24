#include"Global_headers.h"
#include "Setup.h"



Setup::Setup(int przekazywany_screenwidth, int przekazywany_screeheight)
{
	SDL_Init(SDL_INIT_VIDEO);
	
	_window = SDL_CreateWindow("BOULDER DASH", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, przekazywany_screenwidth, przekazywany_screeheight, SDL_WINDOW_SHOWN);
	if (_window == NULL)
	{
		std::cerr << "Failed to initialize window\n" << SDL_GetError();
		exit(0);
	}
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == NULL)
	{
		std::cerr<<"Renderer could not be created! SDL Error: "<< SDL_GetError();
		exit(0);
	}
}

Setup::~Setup()
{
	SDL_DestroyWindow(_window);
	_window = NULL;
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	delete mEvent;
	mEvent = NULL;
	SDL_Quit();
}

SDL_Renderer* Setup::GetRenderer()
{
	return _renderer;
}

SDL_Event* Setup::GetEvent()
{
	return mEvent;
}

void Setup::begin()
{
	SDL_PollEvent(mEvent);
	SDL_RenderClear(_renderer);
}

void Setup::end()
{
	SDL_RenderPresent(_renderer);
}