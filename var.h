#pragma once

int
Generation = 0,
Population = 0,
Generation_Save = 0,
Population_Save = 0,
kbPosX = 32, kbPosY = 32,
cellWidth = 14,
windowWidth = cellWidth * 64,
ColorScheme = 0;

bool
FLAGS[] = { 1, 0, 1, 0 },
UNIVERSE[64][64],
UNIVERSE_SAVE[64][64],
UNIVERSE_NEXT[64][64],
toTerminate = false;

float Color[4][3][3] =
{ 
	{ {0.2, 1.0, 1.0}, {0.22, 0.22, 0.24}, {0.2, 0.2, 0.2} },
	{ {0.7, 0.2, 0.2}, {0.12, 0.1, 0.1}, {0.1, 0.1, 0.1} },
	{ {0.9, 0.9, 0.9}, {0.12, 0.12, 0.12}, {0.1, 0.1, 0.1} },
	{ {0.3, 0.7, 0.3}, {0.15, 0.18, 0.15}, {0.12, 0.14, 0.12} }
};
