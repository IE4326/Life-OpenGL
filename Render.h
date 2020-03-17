#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <chrono>
#include <mutex>

#include "flags.h"

extern bool FLAGS[],
UNIVERSE[64][64],
UNIVERSE_SAVE[64][64],
UNIVERSE_NEXT[64][64],
toTerminate;

extern int
cellWidth,
windowWidth,
kbPosX, kbPosY,
Population,
Generation,
ColorScheme;

extern float Color[4][3][3];

void DrawUniverse();
void DrawCell(int x, int y);
void DrawGrid();
void SwitchAlive(int x, int y);
void ComputeCells();
void ClearUniverse();
void SaveUniverse();
void LoadUniverse();
void RunTime();