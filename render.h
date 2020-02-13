struct parameters{
bool Grid = true;
bool genpopout = false;
bool KeyboardInput = true;
bool Running = false;

char keyboardxcell = 32, keyboardycell = 32;
} parameters;

int cellWidth = 14;
int windowWidth = cellWidth*64, windowHeight=windowWidth;

void RunTime();
void DrawUniverse();
void DrawCell(int x, int y);
void DrawGrid();

void RunTime(){
	if(parameters.Running){
	usleep(100000);
	ComputeCells();
	Display();}
}

void DrawUniverse(){
	for (int y = 0; y<64;y++){
		for (int x = 0; x < 64; x++) {
			DrawCell(x, y);
		}
	}
}

void DrawCell(int x, int y){
	bool alive;
	if ( universe.u[y] & ( (u64)1<<x) ) alive = true; else alive = false;
	if (alive) glColor3f(0.2,1.0,1.0); else {if (parameters.Running)glColor3f(0.22,0.22,0.2); else glColor3f(0.2,0.2,0.2);}
	int lcorner = x*cellWidth, ucorner = y * cellWidth;
	glBegin(GL_QUADS);
	glVertex2i(lcorner, ucorner);
	glVertex2i(lcorner+cellWidth, ucorner);
	glVertex2i(lcorner+cellWidth, ucorner+cellWidth);
	glVertex2i(lcorner, ucorner+cellWidth);
	glEnd();
}

void DrawGrid(){
	glColor3f(0.3,0.3,0.3);
	glLineWidth(1);
	if (parameters.Grid) for (int i = 0; i < 64; i++){

	glBegin(GL_LINES);
	glVertex2i(0,cellWidth*i);
	glVertex2i(windowWidth, cellWidth*i);
	glVertex2i(cellWidth*i, 0);
	glVertex2i(cellWidth*i, windowHeight);
	glEnd();
	}

	if (parameters.KeyboardInput) {
		glColor3f(0.6,0.6,0.6);
		int lcorner = parameters.keyboardxcell*cellWidth;
		int ucorner = parameters.keyboardycell*cellWidth;
		glBegin(GL_LINE_LOOP);
		glVertex2i(lcorner, ucorner);
		glVertex2i(lcorner+cellWidth, ucorner);
		glVertex2i(lcorner+cellWidth, ucorner+cellWidth);
		glVertex2i(lcorner, ucorner+cellWidth);
		glEnd();
	}
}
