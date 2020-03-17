#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <chrono>

#include "var.h"
#include "flags.h"
#include "Render.h"
#include "io.h"

int main(int argc, char* argv[])
{	
	if (!glfwInit())
		return -1;

	GLFWwindow* window = glfwCreateWindow(windowWidth, windowWidth, "LIFE", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetMouseButtonCallback(window, Mouse);
	glfwSetKeyCallback(window, Keyboard);

	glOrtho(0.f, windowWidth, windowWidth, 0.f, 0.f, 1.f);

	std::thread RunTime(RunTime);

	HelpOutput();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.7, 0.7, 0.7, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);

		DrawUniverse();
		
		if (FLAGS[GRID])
		{
			DrawGrid();
		}

		if (FLAGS[OUTPUT])
		{
			Output();
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	toTerminate = true;

	RunTime.join();

	glfwTerminate();
	return 0;
	
}