#include "io.h"
#include "Render.h"

void Output()
{
	std::cout << "Generation: " << Generation << "; Population: " << Population << std::endl;
}

void Mouse(GLFWwindow* window, int Button, int State, int mods)
{
	if (State != GLFW_PRESS)
	{
		return;
	}
	double xPos, yPos;
	glfwGetCursorPos(window, &xPos, &yPos);

	if (Button == GLFW_MOUSE_BUTTON_LEFT)
	{
		int x = xPos / cellWidth,
			y = yPos / cellWidth;

		SwitchAlive(x, y);
		kbPosX = x;
		kbPosY = y;
	}
	if (Button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		FLAGS[RUN] ^= 1;
	}

}

void Keyboard(GLFWwindow* window, int Key, int scancode, int State, int mods)
{
	if (State != GLFW_PRESS && State != GLFW_REPEAT)
	{
		return;
	}

	if (Key == GLFW_KEY_G)
	{
		FLAGS[GRID] ^= 1;
		return;
	}

	if (Key == GLFW_KEY_I)
	{
		FLAGS[OUTPUT] ^= 1;
		return;
	}

	if (Key == GLFW_KEY_K)
	{
		FLAGS[KB_INPUT] ^= 1;
		return;
	}

	if (Key == GLFW_KEY_E)
	{
		ComputeCells();
		return;
	}

	if (Key == GLFW_KEY_H)
	{
		HelpOutput();
		return;
	}

	if (Key == GLFW_KEY_N)
	{
		SwitchColors();
		return;
	}

	if (FLAGS[KB_INPUT])
	{
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		switch (Key)
		{
		case GLFW_KEY_UP:
			kbPosY = (kbPosY + 63) % 64;
			return;

		case GLFW_KEY_DOWN:
			kbPosY = (kbPosY + 65) % 64;
			return;

		case GLFW_KEY_LEFT:
			kbPosX = (kbPosX + 63) % 64;
			return;

		case GLFW_KEY_RIGHT:
			kbPosX = (kbPosX + 65) % 64;
			return;

		case GLFW_KEY_P:
			kbPosX = xPos / cellWidth;
			kbPosY = yPos / cellWidth;
			return;

		case GLFW_KEY_ENTER:
			SwitchAlive(kbPosX, kbPosY);
			return;

		case GLFW_KEY_R:
			FLAGS[RUN] ^= 1;
			return;

		case GLFW_KEY_C:
			ClearUniverse();
			return;

		case GLFW_KEY_Z:
			SaveUniverse();
			return;

		case GLFW_KEY_X:
			LoadUniverse();
			return;

		}
	}
}

void HelpOutput()
{
	std::cout << "\n### HELP ###\n" <<
		"H - show help;\n" <<
		"G - Toggle grid;\n" <<
		"I - Toggle output\n" <<
		"E - Next generation\n" <<
		"N - Switch colors\n" <<
		"K - Switch keyboard edit mode\n\n" <<
		"--- KEYBOARD EDIT MODE ---\n" <<
		"ARROWS - Move edit cell\n" <<
		"ENTER - Switch cell\n" <<
		"P - Point edit cell at mouse cursor position\n" <<
		"R - Switch running\n" <<
		"Z - Save universe\n" <<
		"X - Load universe\n" <<
		"C - Clear universe\n";
}

void SwitchColors()
{
	ColorScheme += 1;
	ColorScheme %= 4;
}