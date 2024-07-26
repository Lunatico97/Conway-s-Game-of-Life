
/* Conway's Game Of Life
   Author : Diwas Adhikari
   SDL_Wrapper Class - Oriented
   
   Files included : Cell.hpp/.cpp
*/

#pragma once

#include "Launcher.hpp"

class Game
{
	public :
	
		Game() ;
		~Game() ;
		
		void initGame() ;
		
		void handleKeys() ;
		
		void updateGame() ;
		
		void delayGame() ;
		
		void renderGame() ;
	
	private :
		
		bool pause ;
} ;
