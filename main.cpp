#include <iostream>
#include <GL/glut.h>
#include <unistd.h>

typedef unsigned long int u64;

using namespace std;

void Display();

#include "universe.h"
#include "render.h"
#include "io.h"
#include "mouse.h"
#include "glutinit.h"

int main(int argc, char **argv){
	glutInit(&argc, argv);
	InitializeGlut();
	universe.clear();
	glutMainLoop();
}

void Display(){
	glClearColor(0.7,0.7,0.7,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	DrawUniverse();
	DrawGrid();
	if (parameters.genpopout) universe.infoout();
	glutSwapBuffers();
}






