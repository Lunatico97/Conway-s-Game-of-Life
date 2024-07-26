
/* Conway's Game Of Life
   Author : Diwas Adhikari
   SDL_Wrapper Class - Oriented
   
   Required for : GameOfLife.hpp/.cpp
*/

#include "Cell.hpp"

void Cells::init()
{
	for(int i=0; i<ROWS; i++)
	{
		for(int j=0; j<COLUMNS; j++)
		{
			grid[i][j] = DEAD ;
		}
	}
}

void Cells::makeCellAliveOrNot(int x, int y, int flag)
{
	
	if(x >=0 && x<ROWS && y>=0 && y<COLUMNS)
	{
		grid[x][y] = flag ;
	}
}

int Cells::countNeighbours(int x, int y)
{
	int count ;
	count = 0 ;
	
	for(int i=x-1; i<=x+1; i++)
	{
		for(int j=y-1; j<=y+1; j++)
		{
			if(i>=0 && j>=0 && i<ROWS && j<COLUMNS)
			{
				if(grid[i][j] == ALIVE)
				{
					count += 1 ;
				}
			}
		}
	}
	
	if(grid[x][y] != DEAD)
	{
		count -= 1 ;
	}
	
	return count ;
}

void Cells::update(int x, int y, int neighbourCount)
{
	if(neighbourCount == 3)
	{
		grid[x][y] = ALIVE ;
	}
	if(neighbourCount > 3 || neighbourCount < 2)
	{
		grid[x][y] = DEAD ;
	}
}

void Cells::makeNewGeneration()
{
	int count[ROWS][COLUMNS] ;  
	
	for(int i=0; i<ROWS; i++)
	{
		for(int j=0; j<COLUMNS; j++) 
		{
			count[i][j] = this->countNeighbours(i, j) ;
		}
	}
	
	for(int i=0; i<ROWS; i++)
	{
		for(int j=0; j<COLUMNS; j++)
		{
			this->update(i, j, count[i][j]) ;
		}
	}
}

void Cells::drawGrid(SDL_Color c)
{
	SDL_SetRenderDrawColor(Launcher::renderer, c.r,c.g,c.b,c.a) ;
	
	for(int i=0; i<COLUMNS; i++)
	{
 		SDL_RenderDrawLine(Launcher::renderer, 0 ,CELL_SIZE*i, SCR_W, CELL_SIZE*i) ;
	}
	for(int j=0; j<ROWS; j++)
	{
		SDL_RenderDrawLine(Launcher::renderer, CELL_SIZE*j, 0, CELL_SIZE*j, SCR_H) ;
	}	

}

void Cells::drawCells(SDL_Color c)
{
	SDL_SetRenderDrawColor(Launcher::renderer, c.r,c.g,c.b,c.a) ;
		
	for(int i=0; i<ROWS; i++)
	{
		for(int j=0; j<COLUMNS; j++)
		{	
			if(grid[i][j] == ALIVE)
			{
				
				SDL_Rect rect = {CELL_SIZE*i, CELL_SIZE*j, CELL_SIZE, CELL_SIZE} ;
				SDL_RenderFillRect(Launcher::renderer, &rect) ;
				
			}
		}
	}
}


