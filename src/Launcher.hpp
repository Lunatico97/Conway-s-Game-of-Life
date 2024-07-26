
/* SDL_Wrapper_Class
   Author : Diwas Adhikari
   Email : lunaticoda123@gmail.com
*/

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
#include <algorithm>

#define SCR_W 1200
#define SCR_H 700

class Launcher
{
	public:
		
		void initScreen(const char *title, int width, int height, int flag) ;
		
		void handleEvents() ;
		
		void updateScreen() ;
		
		void renderScreen() ;
		
		void quit() ;
		
		bool isRunning() ;

		static SDL_Renderer *renderer ;
		
		static bool switchedOn ;
		
		static SDL_Event event ;
		
		void getDt(double t) ;
		
		static double deltaTime ;
		
	private:
		
		SDL_Window *window ;
		
} ;
