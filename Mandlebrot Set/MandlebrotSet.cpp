#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

/*
	Author : Diwas Adhikari
	
	For Mandlebrot Set :
		itr_x represents the real part of c ranging from -2.5 to 1.1
		itr_y represents the imaginary part of c ranging from -1 to 1.1
		
		Hence, if we assume that window sizes are taken with 0.005 divisions per every pixel to be drawn such that 
		the window's width is (-2.5-1.1) / 0.005 = 720 and window's height is (-1-1.1) / 0.005 = 420 configuring 
		a 720 * 420 window screen for the visualization.
*/

#define DIVISION 0.005f 
#define SCR_W (int)((-2.5f-1.1f) / - DIVISION)
#define SCR_H (int)((-1-1.1f) / - DIVISION) 
#define PIX SCR_W*SCR_H

typedef struct{
	float r, g, b ;
} rgb ;

rgb pixels[PIX], pattern[999] ;

void drawMandlebrotSet(){
	float itr_x, itr_y, x, y, temp ;
	int iterations, maxIterations ;
	int locator = 0 ;
	
	for(itr_y = -1; itr_y < 1.1f; itr_y += DIVISION){
		for(itr_x = -2.5f; itr_x < 1.1f; itr_x += DIVISION){
			x = 0 ; 
			y = 0 ;
			iterations = 0 ;
			maxIterations = 1000 ;
			
			while( ((x*x) + (y*y) < (2*2)) && (iterations < maxIterations) ){
				temp = (x*x) - (y*y) + itr_x ;
				y = (2*x*y) + itr_y;
				x = temp ;
				iterations += 1 ;
			}
			
			if(iterations >= 999){
				pixels[locator] = {0,0,0} ;
			}else{
				pixels[locator] = {pattern[iterations].r, pattern[iterations].g, pattern[iterations].b} ;
			}
			
			locator += 1 ;
		}
	}
}

void initialize(){
	std::cout << "Mandlebrot Set " << std::endl ;
	std::cout << "----------------------------------------" << std::endl ;
	std::cout << "Number of pixels : " << PIX << std::endl ;
	std::cout << "Window Size : " << SCR_W << " * " << SCR_H << std::endl ;
	
	glViewport(0,0,SCR_W, SCR_H) ;
	glMatrixMode(GL_MODELVIEW) ;
	glLoadIdentity() ;
	glMatrixMode(GL_PROJECTION) ;
	glLoadIdentity() ;
	gluOrtho2D(0, SCR_W, 0, SCR_H) ;
	
	int i; 
	float r, g, b ;
	
	for(int i=0; i<SCR_H*SCR_W; i++){
		pixels[i] = {1,1,1} ;
	}
	
	i = 0 ;
	
	for(r=0.1f; r<=0.9f; r+=0.1f){
		for(g=0.1f; g<=0.9f; g+=0.1f){
			for(b=0.1f; b<=0.9f; b+=0.1f){
				pattern[i] = {g, b, r} ;
				i++ ;
			}
		}
	}
	
	for(; i<=999; i++){
		pattern[i] = {1, 1, 1} ;
	}
	
	drawMandlebrotSet() ;
	
}

void display(){
	glClearColor(1,1,1,0) ;
	glClear(GL_COLOR_BUFFER_BIT) ;
	
	glDrawPixels(SCR_W, SCR_H, GL_RGB, GL_FLOAT, pixels) ;
	glutSwapBuffers() ;
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv) ;
	glutInitWindowSize(SCR_W, SCR_H) ;
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH) ;
	glutInitWindowPosition(0,200) ;
	glutCreateWindow("Mandlebrot Set") ;
	initialize() ;
	glutDisplayFunc(display) ;
	glutMainLoop() ;
	return 0 ;
}
