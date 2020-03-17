#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

extern int ColorScheme;

void Output();
void Keyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
void Mouse(GLFWwindow* window, int Button, int Action, int mods);
void HelpOutput();
void SwitchColors();