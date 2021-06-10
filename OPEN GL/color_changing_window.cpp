#include"glad/glad.h" // include before the glfw
#include "glfw3.h"
#include<iostream>
using namespace std;
/*     //IMPORTANT - !\\ 
* ALWAYS INTIALIZE GLAD IN  VALID WINDOW ;
* I.E WHEN THE WINDOW IS MADE THE CURRENT CONTEXT ! !!!!!!
* OR ELSE ACESS VIOLATION ERROR .


*/
// need to be called   only once since  it sets the Viewport  when swap buffers occurs with the window s .
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0,1200, 1200);
}

// key press recognitions and the functions to be implemented . .. . .. .
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	else if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	else if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		glClearColor(1.0f, 1.0f, 1.0f, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
	{
		glClearColor(0.0f, 1.0f, 0.0f, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
	{
		glClearColor(0.0f, 0.0f, 1.0f, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
	{
		glClearColor(0.5f, 0.0f, 1.0f, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	else if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
	{
		glClearColor(0.1f, 0.7f, 1.0f, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	else if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
	{
		glClearColor(0.7f, 0.1f, 1.0f, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	else if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
	{
		glClearColor(0.0f, 0.4f, 0.8f, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	else if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
	{
		glClearColor(0.3f, 0.1f, 1.0f, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}
	else if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)
	{
		glClearColor(0.8f, 0.8f, 1.0f, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glViewport(0, 0, 1000, 800);
		glfwSwapBuffers(window);
	}

} 

int main() {
glfwInit();

// TO mention which versions are going to be used windows Hint  functions are used ;
//PROFILE --> CORE (MODERN FUNCTIONS INCLUSIVLE)
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
glfwWindowHint(GLFW_RESIZABLE , GLFW_TRUE);


	GLFWwindow* window = glfwCreateWindow(1920, 1080, "K", NULL, NULL);
	if (window == NULL)
	{
		cout << "ERROR IN  INIT  GLFW WINDOW ! " << endl;

	} 
	glfwMakeContextCurrent(window);

	// glad default check 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// unclear usage 
	glViewport(0 , 0 , 900, 900);

	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glClearColor(0.5f, 0.5f, 0.5f, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);     // at this call the color specif above is set permanently OR DEFAULT COLOR SWAPPED.
	while (!glfwWindowShouldClose(window)) {
		processInput(window); //  checks for glfw key press  
		glClearColor(0.5f, 0.5f, 0.5f, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	    glfwPollEvents(); // interact with the window if disabled cant be closed directly 
	}
	glfwTerminate(); //  terminated glfw   -> destructor
	return  0;
}
//
