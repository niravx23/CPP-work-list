#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

const char* VertexSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* FragmentSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = ourColor ;\n"
"}\n\0";

const char* FragmentSource1 = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor1 ;\n"
"void main()\n"
"{\n"
"   FragColor = ourColor1;\n"
"}\n\0";





int main() {
	glfwInit();

	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);


	GLFWwindow* window = glfwCreateWindow(1000, 1000, "d", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGL();

	glViewport(0, 0, 1000, 1000);
	float vertices[] = {
		-0.5f, 0.5f ,
		0.0f,0.5f ,
		-0.5f, 0.0f,
		-0.5f,-0.5f,
		0.0f,-0.5f,
		0.5f, 0.0f,
		0.5f, 0.5f,
		0.5f, -0.5f

	};

	unsigned int  index[] = {
		0, 1, 2,
		2, 3, 4,
		4, 5,7,
		1, 6, 5,
		1, 2, 5, 2, 4, 5

	};


	unsigned int VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShader, 1, &VertexSource, NULL);
	glCompileShader(VertexShader);


	unsigned int FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmentShader, 1, &FragmentSource, NULL);
	glCompileShader(FragmentShader);

	unsigned int program = glCreateProgram();
	glAttachShader(program, VertexShader);
	glAttachShader(program, FragmentShader);
	glLinkProgram(program);

	glDeleteShader(FragmentShader);

	unsigned int Frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(Frag, 1, &FragmentSource1, NULL);
	glCompileShader(Frag);

	unsigned int program2 = glCreateProgram();
	glAttachShader(program2, VertexShader);
	glAttachShader(program2, Frag);
	glLinkProgram(program2);

	unsigned int buffer, element1, element2;
	glGenBuffers(1, &buffer);
	glGenBuffers(1, &element1);

	glGenBuffers(1, &element2);

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element1);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 18 * sizeof(index), index, GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 18 * sizeof(index), index, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	glEnableVertexAttribArray(0);



	
	
	while (!glfwWindowShouldClose(window)) {

		float time = glfwGetTime();
    //    float timeValue = glfwGetTime();
	//float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
	 
	glUseProgram(program);
	int vertexColorLocation = glGetUniformLocation(program, "ourColor");
     glUniform4f(vertexColorLocation,sin(time)*cos(time), cos(time), sin(time)  , 1.0f);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, NULL);


	glUseProgram(program2);
	  int vertexLocation = glGetUniformLocation(program2, "ourColor1");
	  glUniform4f(vertexLocation, cos(time/2),  sin(4*time), cos(time) ,  1.0f);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(12 * sizeof(unsigned int)));
		glfwSwapBuffers(window);
		glfwSwapInterval(1);

		glfwPollEvents();

	}




	glDeleteProgram(program);
	glDeleteBuffers(1, &element1);
	glDeleteBuffers(1, &buffer);
	glfwTerminate();
	return  0;
}
