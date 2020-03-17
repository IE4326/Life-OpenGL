#include "Render.h"

void DrawUniverse()
{
	for (int y = 0; y < 64; y++) {
		for (int x = 0; x < 64; x++) {
			DrawCell(x, y);
		}
	}
}

void DrawCell(int x, int y)
{
	if (UNIVERSE[x][y])
	{
		glColor3f(Color[ColorScheme][0][0], Color[ColorScheme][0][1], Color[ColorScheme][0][2]);
	} 
	else 
	{ 
		if (FLAGS[RUN])
		{
			glColor3f(Color[ColorScheme][1][0], Color[ColorScheme][1][1], Color[ColorScheme][1][2]);
		} 
		else
		{
			glColor3f(Color[ColorScheme][2][0], Color[ColorScheme][2][1], Color[ColorScheme][2][2]);
		}
	}

	int leftCorner = x * cellWidth, 
		topCorner = y * cellWidth;

	glBegin(GL_QUADS);
		glVertex2i(leftCorner, topCorner);
		glVertex2i(leftCorner + cellWidth, topCorner);
		glVertex2i(leftCorner + cellWidth, topCorner + cellWidth);
		glVertex2i(leftCorner, topCorner + cellWidth);
	glEnd();
}

void DrawGrid()
{
	glColor3f(0.3, 0.3, 0.3);
	glLineWidth(1);

	for (int i = 0; i < 64; i++) {
		glBegin(GL_LINES);
			glVertex2i(0, cellWidth * i);
			glVertex2i(windowWidth, cellWidth * i);
			glVertex2i(cellWidth * i, 0);
			glVertex2i(cellWidth * i, windowWidth);
		glEnd();
	}

	if (FLAGS[KB_INPUT]) {
		glColor3f(0.6, 0.6, 0.6);
		int leftCorner = kbPosX * cellWidth;
		int topCorner = kbPosY * cellWidth;
		glBegin(GL_LINE_LOOP);
			glVertex2i(leftCorner, topCorner);
			glVertex2i(leftCorner + cellWidth, topCorner);
			glVertex2i(leftCorner + cellWidth, topCorner + cellWidth);
			glVertex2i(leftCorner, topCorner + cellWidth);
		glEnd();
	}
}

void SwitchAlive(int x, int y)
{
	UNIVERSE[x][y] ^= 1;
}

void ComputeCells()
{
	static std::mutex c_lock;
	Population = 0;
	int neighborsCount;
	bool CurrentAlive;

	c_lock.lock();
	for (int x = 0; x < 64; x++) {
		for (int y = 0; y < 64; y++) {

			neighborsCount = 0;
			CurrentAlive = UNIVERSE[x][y];

			for (int xc = -1; xc < 2; xc++) {
				for (int yc = -1; yc < 2; yc++) {

					if (UNIVERSE[(x + xc + 64) % 64][(y + yc + 64) % 64])
						neighborsCount++;

				}
			}

			neighborsCount -= CurrentAlive;

			if (CurrentAlive)
			{
				if (neighborsCount == 2 || neighborsCount == 3)
				{
					UNIVERSE_NEXT[x][y] = 1;
					Population++;
				}
				else
				{
					UNIVERSE_NEXT[x][y] = 0;
				}
			}
			else
			{
				if (neighborsCount == 3)
				{
					UNIVERSE_NEXT[x][y] = 1;
					Population++;
				}
				else
				{
					UNIVERSE_NEXT[x][y] = 0;
				}
			}

		}
	}

	for (int x = 0; x < 64; x++) {
		for (int y = 0; y < 64; y++) {
			UNIVERSE[x][y] = UNIVERSE_NEXT[x][y];
		}
	}

	Generation++;
	c_lock.unlock();
}

void RunTime()
{
	while (!toTerminate)
	{
		if (FLAGS[RUN]) {
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			ComputeCells();
		}
	}
}

void ClearUniverse()
{
	for (int x = 0; x < 64; x++) {
		for (int y = 0; y < 64; y++) {
			UNIVERSE[x][y] = 0;
		}
	}
}

void SaveUniverse()
{
	for (int x = 0; x < 64; x++) {
		for (int y = 0; y < 64; y++) {
			UNIVERSE_SAVE[x][y] = UNIVERSE[x][y];
		}
	}
}

void LoadUniverse()
{
	for (int x = 0; x < 64; x++) {
		for (int y = 0; y < 64; y++) {
			UNIVERSE[x][y] = UNIVERSE_SAVE[x][y];
		}
	}
}

void DrawPoint()
{
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2i(0, 0);
	glEnd();
}