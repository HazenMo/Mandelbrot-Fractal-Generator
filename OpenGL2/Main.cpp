/*
#include <iostream>
#include <stdlib.h>
#include <string>

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <GL/gl.h>
#include <GL/glut.h>

#include "Shader.h"

int screenWidth{ 1080 };
int screenHeight{ 1080 };

#define INIT_VIRTUAL_GRID_XMIN -2.0
#define INIT_VIRTUAL_GRID_XMAX 2.0
#define INIT_VIRTUAL_GRID_YMIN -2.0
#define INIT_VIRTUAL_GRID_YMAX 2.0

//int numFrames{ 0 };
//float lastTime{ 0.0f };

float vertices[] =
{
	//	  x	     y	    z
		-1.0f, -1.0f, -0.0f,
		 1.0f,  1.0f, -0.0f,
		-1.0f,  1.0f, -0.0f,
		 1.0f, -1.0f, -0.0f
};

unsigned int indicies[] =
{
	//	2---,1
	//	| .' |
	//  0'___3
		0, 1, 2,
		0, 3, 1
};


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
	drawPoint(0, 0, 255, 255, 255);
	glutSwapBuffers();
}

void initGL(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(screenWidth, screenHeight);
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




int main2()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "Mandelbrot", NULL, NULL);

	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window!\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit())
	{
		std::cout << "Failed initializing GLEW\n";
	}

	glViewport(0, 0, screenWidth, screenHeight);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	lastTime = glfwGetTime();

	unsigned int VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	Shader ourShader("shader.vert", "shader.frag");
	
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		countFPS();

		ourShader.use_shader();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	glfwTerminate();
	return 0;
}

int main3(int argc, char** argv)
{
	initGL(argc, argv);
	glutMainLoop(); // Starts the infinite loop that draws the window
	return 0;
}*/