void Keyboard(unsigned char ch, int x, int y);

void Keyboard(unsigned char ch, int x, int y){
	switch (ch){
		case 'g': parameters.Grid^=1; Display(); break; 
		case 'i': parameters.genpopout^=1; Display;break;
		case 'k': parameters.KeyboardInput^=1; Display(); break;
		case 'e': ComputeCells(); break;
	}

	if (parameters.KeyboardInput){
	int xc = parameters.keyboardxcell;
	int yc = parameters.keyboardycell;
		switch (ch) {
		case 'w': (yc-1) >= 0? yc--: yc=63; break;
		case 'a': (xc-1) >= 0? xc--: xc=63; break;
		case 's': (yc+1) < 64? yc++: yc=0; break;
		case 'd': (xc+1) < 64? xc++: xc=0; break;
		case 'p': xc = x/cellWidth; yc = y/cellWidth; break;
		case 13:  universe.u[yc] ^= (u64)1<<xc; break;
		case 'q' : parameters.Running ^= 1; break;
		case 'f' : universe.save(); break;
		case 'r' : universe.load(); break;
		case 'c' : universe.clear(); break;
		}
	parameters.keyboardxcell = xc;
	parameters.keyboardycell = yc;
	}
	Display();
}

