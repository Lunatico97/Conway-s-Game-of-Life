
/* Conway's Game Of Life
   Author : Diwas Adhikari
   SDL_Wrapper Class - Oriented
   
   Required for : GameOfLife.hpp/.cpp
*/

#pragma once

#include "Launcher.hpp"

#define CELL_SIZE 10
#define ROWS SCR_W/CELL_SIZE
#define COLUMNS SCR_H/CELL_SIZE

#define DEAD 0
#define ALIVE 1

class Cells
{
	public :
		
		void init() ;
		
		void makeCellAliveOrNot(int x, int y, int flag) ;
		
		void makeNewGeneration() ;
		
		void drawGrid(SDL_Color c) ;
		
		void drawCells(SDL_Color c) ;
		
		int countNeighbours(int x, int y) ;
		
		void update(int x, int y, int neighbourCount) ;
		
	private :
		
		int grid[ROWS][COLUMNS] ;
} ;
