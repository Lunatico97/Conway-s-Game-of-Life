
/* SDL_Wrapper_Class
   Author : Diwas Adhikari
   Email : lunaticoda123@gmail.com
*/

#include "Launcher.hpp"
#include "Texture.hpp"
#include "Music.hpp"
#include "Font.hpp"

#include "GameOfLife.hpp"

SDL_Renderer* Launcher::renderer = nullptr ;
bool Launcher::switchedOn ;
SDL_Event Launcher::event ;
double Launcher::deltaTime ;

Game *game = nullptr ;

bool Launcher::isRunning()
{
	return switchedOn ;
}

void Launcher::getDt(double t)
{
	deltaTime = t ;
}

void Launcher::initScreen(const char *title, int width, int height, int flag)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL 2.0 FAILED TO INITIALIZE ! " << std::endl ;
	}
	
	std::cout << "SDL 2.0 INITIALIZED SUCCESSFULLY ! " << std::endl ;
	window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,flag) ;
	renderer = SDL_CreateRenderer(window, -1, 0) ;
	switchedOn = true ;
	
	game = new Game() ;
	game->initGame() ;
}

void Launcher::handleEvents()
{
	SDL_PollEvent(&event) ;
	if(event.type == SDL_QUIT)
	{
		switchedOn = false ;
	}
	if(event.type == SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_ESCAPE :
				switchedOn = false ;
				break ;

			default :
				break ;
				
		}
	}
	
	game->handleKeys() ;
	
}

void Launcher::quit()
{	
	delete game ;

	std::cout << "SDL 2.0 TERMINATED ! " << std::endl ;
	SDL_DestroyRenderer(renderer) ;
	SDL_DestroyWindow(window) ;
	SDL_Quit() ;
}

void Launcher::updateScreen()
{
	game->updateGame() ;
}

void Launcher::renderScreen()
{
	SDL_RenderClear(renderer) ;
	
	game->renderGame() ;
	
	SDL_SetRenderDrawColor(renderer, 255,255,255,255) ; 	
	SDL_RenderPresent(renderer) ;

	game->delayGame() ;
}
