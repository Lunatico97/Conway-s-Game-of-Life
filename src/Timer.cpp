
#include "Timer.hpp"

double Timer::setFraps(int fraps, Uint32 beforeCountFraps, int delayFlag )
{
	periodTicks = 1000/fraps ;
	deltaTicks = SDL_GetTicks() - beforeCountFraps ; 
	
	switch(delayFlag)
		{
			case CAP_LIMIT_DISABLE :
				if(deltaTicks < periodTicks)
				{
					deltaTime = periodTicks - deltaTicks ;
				}
				break ;
				
			case CAP_LIMIT_ENABLE :
				if(deltaTicks < periodTicks)
				{
					deltaTime = periodTicks - deltaTicks ;
				}
				SDL_Delay(deltaTime) ;
				break ;
				
			default :
				break ;		
		}
	
	return deltaTime ;
} 
