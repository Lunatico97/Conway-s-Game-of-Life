
/* Conway's Game Of Life
   Author : Diwas Adhikari
   Algorithm : John H. Conway
   SDL_Wrapper Class - Oriented (Author : Diwas Adhikari)
   
   ~ Zero-player cellular automata/simulation
   
   ->Files included : Cell.hpp/.cpp
   
   ->Controls : Keyboard =
   						{BACKSPACE - Clear The Screen & Pause The Automata}
   						{SPACE - Pause/Resume The Automata}
   						
   		   	    Mouse = 	
				 		{LEFT_CLICK - Revive a cell }
						{RIGHT_CLICK - Kill a cell }
						
   ->Beginner Patterns : {LABEL : '#' : Alive Cell || '.' : Dead Cell}
   	 (also, includes some interesting patterns)
							
   						Block =         (Creates stable square block)
										. . . .
										. # # .
										. # # .
										. . . . 
   						
   					    Glider =        (Glides infinitely if, no barriers) 
										. . . . .       . . . . .
							     		. . # . .       . . # . .
								    	. . . # .  or,  . # . . .
									    . # # # .       . # # # . 
									    . . . . .       . . . . .
						
						Eater =         (Eats a glider without disrupting itself)
										. . . . . .
										. # # . . .
										. # . . . .
										. . # # # .
										. . . . # .
										. . . . . . 
						
						Blinker =       (Blinks continously and never becomes stable)
										. . .     . . . . . 
										. # .     . # # # .
										. # . or, . . . . .
										. # . 
										. . .
									
					    Glider Gun =    (Creates glider infinitely)
			         (Bill Cosper)		. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .  
										. . . . . . . . . . . . . . . . . . . . . . . . . # . . . . . . . . .
										. . . . . . . . . . . . . . . . . . . . . . . # . # . . . . . . . . .
										. . . . . . . . . . . . . # # . . . . . . # # . . . . . . . . . # # .
										. . . . . . . . . . . . # . . . # . . . . # # . . . . . . . . . # # .
										. # # . . . . . . . . # . . . . . # . . . # # . . . . . . . . . . . .
										. # # . . . . . . . . # . . . # . # # . . . . # . # . . . . . . . . .
										. . . . . . . . . . . # . . . . . # . . . . . . . # . . . . . . . . .
										. . . . . . . . . . . . # . . . # . . . . . . . . . . . . . . . . . .
										. . . . . . . . . . . . . # # . . . . . . . . . . . . . . . . . . . .
										. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
						          
				   4-8-12 Diamond =	    (Creates 4 gliders moving on axis away by 90 degrees)
				                        . . . . . . . . . . . . . .
				                        . . . . . # # # # . . . . .
				                        . . . . . . . . . . . . . .
				                        . . . # # # # # # # # . . .
				                        . . . . . . . . . . . . . .
				                        . # # # # # # # # # # # # .
				                        . . . . . . . . . . . . . .
				                        . . . # # # # # # # # . . .
				                        . . . . . . . . . . . . . .
				                        . . . . . # # # # . . . . .
				                        . . . . . . . . . . . . . .
					
					    Acorn =         (Creates methuselah i.e pattern that stabilizes after a long time with 13 gliders
			(Charles Corderman)			 and some small patterns like blinkers, blocks as well as, a mango and a eater)
									    . . . . . . . . .
										. . # . . . . . .
										. . . . # . . . .
										. # # . . # # # .
										. . . . . . . . .
										
					Demonoid =          (Creates some patterns and change phase to create 12 blinkers at the end)
		   (Achim Flammenkamp)          . . . . . . . . . . . . . . . . . . .   
										. . . . # # . . . . . . # # . . . . . 
										. . . # . # . . . . . . # . # . . . . 
										. . . # . . . . . . . . . . # . . . . 
										# # . # . . . . . . . . . . # . # # . 
										# # . # . # . . # # . . # . # . # # . 
										. . . # . # . # . . # . # . # . . . . 
										. . . # . # . # . . # . # . # . . . . 
										# # . # . # . . # # . . # . # . # # . 
										# # . # . . . . . . . . . . # . # # . 
										. . . # . . . . . . . . . . # . . . . 
										. . . # . # . . . . . . # . # . . . .          
										. . . . # # . . . . . . # # . . . . . 
										. . . . . . . . . . . . . . . . . . . 
									
		  1-2-3 Oscillator =            (Creates an oscillator with three cells only in the rotor) 	
		   (Dave Buckingham)            . . . . . . . . . . . . 
		                                . . . # # . . . . . . . 
										. # . . # . . . . . . . 
										. # # . # . # # . . . . 
										. . # . # . . # . . . . 
										. . # . . . . # . # # . 
										. . . # # # . # . # # . 
										. . . . . . # . . . . . 
										. . . . . # . . . . . . 
										. . . . . # # . . . . . 
										. . . . . . . . . . . .
										
		1-2-3-4 Oscillator =            (Creates an oscillator with three cells with one vacant space in the rotor) 	
		   (Dave Buckingham)            . . . . . . . . . . . . .
		   								. . . . . . # . . . . . .
		                                . . . . . # . # . . . . .
										. . . . # . # . # . . . .
										. . . . # . . . # . . . .
										. # # . # . # . # . # # .
										. # . # . . . . . # . . .
										. . . . # # # # # . . . .
										. . . . . . . . . . . . .
										. . . . . . # . . . . . .
										. . . . . # . # . . . . .
										. . . . . . # . . . . . .
										. . . . . . . . . . . . .
										
		  Two-Glider Mess =             (Collides two gliders in this way to get 4 gliders, 4 blocks , 8 blinkers,
		                                 beehive and a ship)
		                                . . . . . . . . . . . . 
		                                . . . # . . . . . . . .
		                                . # . # . . . . . . . .
		                                . . # # . . . . . . . .
		                                . . . . . . . . . . # .
		                                . . . . . . . . # # . .
		                                . . . . . . . . . # # .
		                                . . . . . . . . . . . .
		                                
              'A' For All =             (Creates a 4-way rotor)
		   (Dean Hickerson)             . . . . . . . . . . . . 
		                                . . . . . # # . . . . .
		                                . . . . # . . # . . . .
		                                . . . . # # # # . . . .
		                                . . # . # . . # . # . .
		                                . # . . . . . . . . # .
		                                . # . . . . . . . . # .
		                                . . # . # . . # . # . .
		                                . . . . # # # # . . . .
		                                . . . . # . . # . . . .
		                                . . . . . # # . . . . .
		                                . . . . . . . . . . . .
		                                 
		   								  
*/

#include "GameOfLife.hpp"
#include "Cell.hpp"

#define RETARD 0.5

Cells *cells = nullptr ;

Game::Game()
{}
Game::~Game()
{}

void Game::initGame()
{
	cells = new Cells() ;
	cells->init() ;
	pause = true; 
}

void Game::handleKeys()
{
	if(Launcher::event.type == SDL_KEYDOWN)
	{
		switch(Launcher::event.key.keysym.sym)
		{
			case SDLK_SPACE :
				pause = !pause ;
				break ;
				
			case SDLK_BACKSPACE :
				pause = true ;
				cells->init() ;
				break ;
			
			default :
				break ;
				
		}
	}
	
	//Click to make a cell alive or dead 
	else if(Launcher::event.type == SDL_MOUSEBUTTONDOWN)
	{
	 	cells->makeCellAliveOrNot(Launcher::event.button.x/CELL_SIZE, Launcher::event.button.y/CELL_SIZE,
								  (Launcher::event.button.button == SDL_BUTTON_LEFT)?ALIVE:DEAD 
								 ) ;
								 
		
	}
	
	else if(Launcher::event.type == SDL_MOUSEMOTION)
	{
		if(Launcher::event.motion.state & (SDL_BUTTON_LMASK | SDL_BUTTON_RMASK))
		{
			cells->makeCellAliveOrNot(Launcher::event.motion.x/CELL_SIZE, Launcher::event.motion.y/CELL_SIZE,
								  (Launcher::event.motion.state & SDL_BUTTON_LMASK)?ALIVE:DEAD 
								 ) ;
			
		}
	}
}

void Game::renderGame()
{
	SDL_Color gray = {128,128,128,255} ;
	cells->drawGrid(gray) ;
	srand(time(0)) ;
	Uint8 r_ = rand()%255 ;
	Uint8 g_ = rand()%255 ;
	Uint8 b_ = rand()%255 ;
	SDL_Color color = {r_ ,g_ ,b_ ,255} ;
	cells->drawCells(color) ;
}

void Game::updateGame()
{
	if(!pause)
	{
	  cells->makeNewGeneration() ;
	}
}

void Game::delayGame()
{
	SDL_Delay(100*RETARD) ;
}
