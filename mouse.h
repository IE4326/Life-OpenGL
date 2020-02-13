void Mouse(int button, int state, int x, int y);

void Mouse(int button, int state, int x, int y){
	if (button == 0 && state == 1) { 
	SwitchAlive(x/cellWidth, y/cellWidth);
	parameters.keyboardxcell = x/cellWidth;
	parameters.keyboardycell = y/cellWidth;
	}
	if (button == 2 && state == 1) parameters.Running ^= 1;
	if (button == 1) universe.clear();
	if (button == 4) universe.save();
	if (button == 3) universe.load();
	Display();
}
