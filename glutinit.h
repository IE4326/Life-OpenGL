void InitializeGlut();
void Reshape(int width, int height);

void InitializeGlut(){
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(400,0);
	glutCreateWindow("CELL AUTOMATA");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMouseFunc(Mouse);
	glutKeyboardFunc(Keyboard);
	glutIdleFunc(RunTime);
}

void Reshape(int width, int height){
	cellWidth=height/64;
	windowWidth = width;
	windowHeight = height;
	glViewport(0, 0, cellWidth*64, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, cellWidth*64, height,0.0, 0.0, 1.0);
	Display();
}
