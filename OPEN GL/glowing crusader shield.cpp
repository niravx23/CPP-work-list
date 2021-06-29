#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <ShaderParser.h>

int main() {
	ShaderParser main1("C:/Users/na/Desktop/programming/open gl/OPENGL/main.gl/shaders/shader_for_attrib2.glsl");
	string a = main1.GET_VERTEX_SHADER();
	string  b = main1.GET_FRAGMENT_SHADER();

	const char* VertexShaderSource = a.c_str();
	const char* FragmentShaderSource = b.c_str();

	cout << a << endl << b;

	glfwInit();
	glfwDefaultWindowHints();

	float  vertex[] = {
			   -0.5f, 0.3f, 0.0f,
			   0.5f, 0.3f, 0.0f,
			   -0.5f, -0.3f, 0.0f,
			   0.5f, -0.3f, 0.0f,
			   0.0f, 0.5f, 0.0f,
				  0.0f, -0.8f, 0.0f

	};
	float holy_cross[] = {
	-0.00f, 0.0f, 0.0f, 

		-0.1f, 0.35f, 0.0f, // upper part
		0.0f, 0.28f, 0.0f, 
			0.1f, 0.35f, 0.0f,

		0.35f, 0.1f, 0.0f, // right part 4
		0.28f, 0.0f, 0.0f, //5
		0.35f,-0.1f, 0.0f , // 6


		-0.35f, 0.1f, 0.0f , // left 7
		-0.28f, 0.0f, 0.0f, //8
		-0.35f, -0.1f, 0.0f,//9


		-0.1f, -0.35f, 0.0f, // btm 10
		0.0f, -0.28f, 0.0f, //11
		0.1f, -0.35f, 0.0f//12
	};

	unsigned int cross[] = {
	0 , 1, 2, 
	2, 3,0 , 

	0, 4, 5, 
	0, 5, 6,

	7, 8, 0,
	9, 8, 0, 

	0, 10, 11, 
	0, 11, 12

	};
	unsigned int ShieldSquare[] = {
		 0, 1, 2 ,
		 2, 3 , 1,
		 0, 1, 4 ,
		 2, 3 , 5

	};
	GLFWwindow* screen = glfwCreateWindow(900, 700, "Shield", NULL, NULL);
	glfwMakeContextCurrent(screen);

	// shaders 
	gladLoadGL();
	unsigned int vertexshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexshader, 1, &VertexShaderSource, NULL);
	glCompileShader(vertexshader);

	unsigned int fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentshader, 1, &FragmentShaderSource, NULL);
	glCompileShader(fragmentshader);

	unsigned int prg = glCreateProgram();
	glAttachShader(prg, vertexshader);
	glAttachShader(prg, fragmentshader);
	glLinkProgram(prg);

	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);

	glViewport(0, 0, 900, 900);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);



	// shield
	unsigned int vao, vbo, ebo;
	glGenVertexArrays(1, &vao);

	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);



	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);




	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ShieldSquare), ShieldSquare, GL_STATIC_DRAW);



	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	int vertexcolorloc = glGetUniformLocation(prg, "color_main");



glUseProgram(prg);

	glBindVertexArray(vao);
	
	


	//sheild over

	float time; 


	// holy cros

	unsigned int vao1, vbo1, ebo1;
	glGenVertexArrays(1, &vao1);

	glGenBuffers(1, &vbo1);
	glGenBuffers(1, &ebo1);



	glBindVertexArray(vao1);
	glBindBuffer(GL_ARRAY_BUFFER, vbo1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(holy_cross),holy_cross, GL_STATIC_DRAW);




	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo1);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cross), cross, GL_STATIC_DRAW);



	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);





	// holy cross -

	


	





	while (!glfwWindowShouldClose(screen)) {


		time = glfwGetTime();

		glBindVertexArray(vao);

		glUniform4f(vertexcolorloc, 0.9960f, 0.625f, 0.65234f, 1.0f);
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);




		glBindVertexArray(vao1);
		glUniform4f(vertexcolorloc,sin(time), 0.0f, 0.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, 0);


		glfwSwapInterval(1);
glfwSwapBuffers(screen);
		glfwPollEvents();
	}

	//glDeleteVertexArrays(1, &vao1);
	//glDeleteBuffers(1, &vbo1);
	//glDeleteBuffers(1, &ebo1);
	//glDeleteProgram(prg);

	glfwTerminate();
	return 0;
}