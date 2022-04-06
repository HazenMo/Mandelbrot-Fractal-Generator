#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <GL/gl.h>
#include <GL/glut.h>

#include "Complex.h"
#include "Point.h"

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 1080

#define INIT_VIRTUAL_GRID_XMIN -2.0
#define INIT_VIRTUAL_GRID_XMAX 2.0
#define INIT_VIRTUAL_GRID_YMIN -2.0
#define INIT_VIRTUAL_GRID_YMAX 2.0

int numFrames{0};
float lastTime{0.0f};

std::vector <Point*> points;

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void countFPS()
{
	double currentTime = glfwGetTime();
	numFrames++;
	if (currentTime - lastTime >= 1.0)
	{
		std::cout << 1000.0 / numFrames << "ms / frame\n";
		numFrames = 0;
		lastTime += 1.0;
	}
}

void drawPoint(float x, float y, int r, int g, int b)
{
	glBegin(GL_POINTS);
	glColor3f(r / 255.0, g / 255.0, b / 255.0);
	glVertex2f(x, y);
	glEnd();
}


void drawCallback()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	for (std::vector <Point*> ::iterator it = points.begin(); it != points.end(); ++it)
	{
		drawPoint((*it)->getPosX(), (*it)->getPosY(), 0, (*it)->getColor() / 2, (*it)->getColor());
	}
	glutSwapBuffers();
}

void initGL(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Mandelbrot - C++");
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(INIT_VIRTUAL_GRID_XMIN, INIT_VIRTUAL_GRID_XMAX,
		INIT_VIRTUAL_GRID_YMIN, INIT_VIRTUAL_GRID_YMAX); // Set grid size

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutDisplayFunc(drawCallback); // Run the drawing function
	//glutMouseFunc(mouseCallback);
	glutIdleFunc(drawCallback);
}

int main(int argc, char** argv)
{

	for (int i = 0; i < 1080; i++)
	{
		for (int j = 0; j < 1080; j++)
		{
			float posX = -2 + (i / 270.0);
			float posY = -2 + (j / 270.0);
			
			Complex c = Complex(posY, posX);
			Complex z = Complex(0, 0);
			int counter = 0;
			while (z.zInBounds() && counter < 255)
			{
				Complex placeHolder = z * z;
				z = placeHolder + c;
				counter++;
			}
			Point* point = new Point(posX, posY, counter);
			points.push_back(point);
		}
	}

	initGL(argc, argv);
	glutMainLoop(); // Starts the infinite loop that draws the window

	return 0;
}
