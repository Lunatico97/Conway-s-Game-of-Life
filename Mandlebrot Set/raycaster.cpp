
#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

#define MAPW 24
#define MAPH 24
#define SCRW 640
#define SCRH 480

int map[MAPW][MAPH] = 
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1},
	{1,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,4,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,2,2,2,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,2,2,2,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}	
} ;

typedef struct{
	float posX, posY, dirX, dirY, planeX, planeY, speed, rotate ;
	SDL_FRect rect ;
} Player ;

Player player ;

void initialize(){
	player.posX = 18 ;
	player.posY = 12 ;
	player.dirX = -1 ;
	player.dirY = 0 ;
	player.planeX = 0 ;
	player.planeY = 0.66 ;
	player.speed = 0 ;
	player.rotate = 0 ; 
}

int main(int argc, char *argv[]){
	
	SDL_Init(SDL_INIT_EVERYTHING) ;
	SDL_Window *window = SDL_CreateWindow("Ray", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCRW, SCRH, 0) ; 
	SDL_Window *mapWindow = SDL_CreateWindow("Map", 20 , 20, MAPW*10, MAPH*10, 0) ;
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0) ;
	SDL_Renderer *mapRender = SDL_CreateRenderer(mapWindow, -1, 0) ;
	SDL_Event event ;
	bool status = true ;
	
	initialize() ;
	double time = 0 ;
	double oldTime = 0 ;
	
	SDL_Rect mRect ;
	double cameraX, rayX, rayY, sideDistX, sideDistY, delX, delY, perpDist, frametime, olddir, oldplane ;
	int mapX, mapY, stepX, stepY ;
	bool hit, side ;
	
	while(status){
		
		SDL_PollEvent(&event) ;
		if(event.type == SDL_QUIT){
			status = false ;
		}
		
		SDL_RenderClear(renderer) ;
		SDL_RenderClear(mapRender) ;
		
		//Only for map window 
		for(int i=0; i<24; i++){
		for(int j=0; j<24; j++){
			mRect = {i*10, j*10, 10, 10} ;
			switch(map[i][j]){
				case 0 : SDL_SetRenderDrawColor(mapRender, 255/4, 255/4, 255/4, 0) ; break ;
				case 1 : SDL_SetRenderDrawColor(mapRender, 255, 255, 255, 0) ; break ;
				case 2 : SDL_SetRenderDrawColor(mapRender, 255, 0, 0, 0) ; break ;
				case 3 : SDL_SetRenderDrawColor(mapRender, 0, 0, 255, 0) ; break ;
				case 4 : SDL_SetRenderDrawColor(mapRender, 255, 255, 0, 0) ; break ;
				default :  break ;
			}
			SDL_RenderDrawRect(mapRender, &mRect) ;
		}}
		player.rect = {player.posX*10, player.posY*10, 5, 5} ;
		SDL_SetRenderDrawColor(mapRender, 0, 255/2, 0, 0) ;
		SDL_RenderFillRectF(mapRender, &player.rect) ;
		
		//Digital Differtial Analyzer (DDA)
		for(int i=0; i<SCRW; i++){
			cameraX = 2*i / double(SCRW) - 1 ;
			rayX = player.dirX + player.planeX * cameraX ;
			rayY = player.dirY + player.planeY * cameraX ;
			mapX = int(player.posX) ;
			mapY = int(player.posY) ;
			delX = (rayX == 0) ? 1e30 : std::abs(1/rayX) ;
			delY = (rayY == 0) ? 1e30 : std::abs(1/rayY) ;
			hit = false ;
			if(rayX < 0){
				stepX = -1 ;
				sideDistX = (player.posX - mapX) * delX ;
			}
			else{
				stepX = 1 ;
				sideDistX = (mapX + 1.0 - player.posX) * delX ;
			}
			if(rayY < 0){
				stepY = -1 ;
				sideDistY = (player.posY - mapY) * delY ;
			}
			else{
				stepY = 1 ;
				sideDistY = (mapY + 1.0 - player.posY) * delY ;
			}
			
			while(!hit){
				if(sideDistX < sideDistY){
					sideDistX += delX ;
					mapX += stepX ;
					side = false ;
				}	
				else{
					sideDistY += delY ;
					mapY += stepY ;
					side = true ;
				}
				
				if(map[mapX][mapY] > 0) hit = true ;
			}
			
			if(!side) perpDist = (sideDistX - delX) ;
			else perpDist = (sideDistY - delY) ;
			
			int lineHeight = (int)(SCRH / perpDist) ;
			
			int drawStart = -lineHeight/2 + SCRH/2 ;
			if(drawStart < 0) drawStart = 0 ;
			int drawEnd = lineHeight/2 + SCRH/2 ;
			if(drawEnd > SCRH) drawEnd = SCRH - 1 ; 
			
			switch(map[mapX][mapY]){
				case 1 : if(side) SDL_SetRenderDrawColor(renderer, 255/4,255/4,255/4,255) ;
						 else SDL_SetRenderDrawColor(renderer, 255/2,255/2,225/2,255) ;
						 break ;
				case 2 : if(side) SDL_SetRenderDrawColor(renderer, 255/4,0,0,255) ;
						 else SDL_SetRenderDrawColor(renderer, 255/2,0,0,255) ;
						 break ;
			    case 3 : if(side) SDL_SetRenderDrawColor(renderer, 0,0,255/4,255) ;
						 else SDL_SetRenderDrawColor(renderer, 0,0,255/2,255) ;
						 break ;
				case 4 : if(side) SDL_SetRenderDrawColor(renderer, 255/4,255/4,0,255) ;
						 else SDL_SetRenderDrawColor(renderer, 255/2,255/2,0,255) ;
						 break ;
				default : break ;
			}
			SDL_RenderDrawLine(renderer, i, drawStart, i, drawEnd) ;
		}
		
		//Timing
		oldTime = time ;
		time = SDL_GetTicks() ;
		frametime = (time - oldTime) / 1000.0 ;
		
		player.speed = frametime * 8.0 ;
		player.rotate = frametime * 3.0 ;
		
		//Controls
		if(event.type == SDL_KEYDOWN){
			switch(event.key.keysym.sym){
				case SDLK_w: if(map[int(player.posX + player.dirX * player.speed)][int(player.posY)] == 0)
							 	player.posX += player.dirX * player.speed ;
							 if(map[int(player.posX)][int(player.posY + player.dirY * player.speed)] == 0)
							 	player.posY += player.dirY * player.speed ;	  
							 break ;
				case SDLK_s: if(map[int(player.posX - player.dirX * player.speed)][int(player.posY)] == 0)
							 	player.posX -= player.dirX * player.speed ;
							 if(map[int(player.posX)][int(player.posY - player.dirY * player.speed)] == 0)
							 	player.posY -= player.dirY * player.speed ;	  
							 break ;
				case SDLK_d: olddir = player.dirX ;
							 player.dirX = player.dirX * cos(-player.rotate) - player.dirY * sin(-player.rotate) ;
							 player.dirY = olddir * sin(-player.rotate) + player.dirY * cos(-player.rotate) ;
						     oldplane = player.planeX ;		
							 player.planeX = player.planeX * cos(-player.rotate) - player.planeY * sin(-player.rotate) ;
							 player.planeY = oldplane * sin(-player.rotate) + player.planeY * cos(-player.rotate) ;	
							 break ;
				case SDLK_a: olddir = player.dirX ;
							 player.dirX = player.dirX * cos(player.rotate) - player.dirY * sin(player.rotate) ;
							 player.dirY = olddir * sin(player.rotate) + player.dirY * cos(player.rotate) ;
						     oldplane = player.planeX ;		
							 player.planeX = player.planeX * cos(player.rotate) - player.planeY * sin(player.rotate) ;
							 player.planeY = oldplane * sin(player.rotate) + player.planeY * cos(player.rotate) ;	
							 break ;
				default : break ;
			}
		}
		
		SDL_SetRenderDrawColor(renderer, 0,0,0,255) ;
		SDL_RenderPresent(renderer) ;
		SDL_SetRenderDrawColor(mapRender, 0, 0, 0, 0) ;
		SDL_RenderPresent(mapRender) ;
	}
	
	SDL_DestroyWindow(mapWindow) ;
	SDL_DestroyRenderer(mapRender) ;
	SDL_DestroyWindow(window) ;
	SDL_DestroyRenderer(renderer) ;
	SDL_Quit() ;
	return 0 ;
}
