
#include "Launcher.hpp"
#include "Timer.hpp"

int main(int argc, char** argv) {
	
	Launcher *launcher = nullptr ;
	launcher = new Launcher() ;
	
	Timer *timer = nullptr ;
	timer = new Timer() ;
	
	launcher->initScreen(" Conway's Game Of Life ", SCR_W, SCR_H, 0 ) ;
	
	while(launcher->isRunning())
	{
		Uint32 beforeTicks = SDL_GetTicks() ;
		
		launcher->handleEvents() ;
		launcher->updateScreen() ;	
		launcher->renderScreen() ;
		
		double deltaTime = timer->setFraps(60, beforeTicks, CAP_LIMIT_ENABLE) ;
		//std::cout << " FPS : " << 1000/deltaTime << std::endl ;
	}
	
	launcher->quit() ;
	
	return 0;
}
