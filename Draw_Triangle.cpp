#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "vec.h"

//static const char* pVS = "                                                    \n\
//#version 330                                                                  \n\
//                                                                              \n\
//layout (location = 0) in vec3 Position;                                       \n\
//                                                                              \n\
//void main()                                                                   \n\
//{                                                                             \n\
//    gl_Position = vec4(0.5 * Position.x, 0.5 * Position.y, 0.5 * Position.z, 1.0);  \n\
//}";
//
//static const char* pFS = "                                                          \n\
//#version 330                                                                        \n\
//                                                                                    \n\
//out vec4 FragColor;                                                                 \n\
//                                                                                    \n\
//void main()                                                                         \n\
//{                                                                                   \n\
//    FragColor = vec4(1.0, 0.0, 0.0, 1.0);                                           \n\
//}";



static void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
}


static void CreateVertexBuffer(int quadrant)
{
	vec3 Vertices[3];
	
	switch (quadrant)
	{
	case 1:
		Vertices[0] = vec3(-0.5f, 0.5f, 0.0f);
		Vertices[1] = vec3(-0.25f, 0.0f, 0.0f);
		Vertices[2] = vec3(-0.75f, 0.0f, 0.0f);
		break;

	case 2:
		Vertices[0] = vec3(-0.5f, 0.0f, 0.0f);
		Vertices[1] = vec3(-0.25f, -0.5f, 0.0f);
		Vertices[2] = vec3(-0.75f, -0.5f, 0.0f);
		break;

	case 3:
		Vertices[0] = vec3(0.5f, 0.0f, 0.0f);
		Vertices[1] = vec3(0.25f, -0.5f, 0.0f);
		Vertices[2] = vec3(0.75f, -0.5f, 0.0f);
		break;

	default:
		Vertices[0] = vec3(-0.5f, -0.5f, 0.0f);
		Vertices[1] = vec3(0.5f, -0.5f, 0.0f);
		Vertices[2] = vec3(0.0f, 0.5f, 0.0f);

	}

	for (int i = 0; i < 3; i++)
	{
		printf("%f\t",Vertices[i]);
	}

	printf("\n");
	
	// Create and initialize a buffer object
	GLuint buffer;
 	glGenBuffers(1, &buffer);

	// Create a vertex array object
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
}

//static void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
//{
//	GLuint ShaderObj = glCreateShader(ShaderType);
//
//	if (ShaderObj == 0) {
//		fprintf(stderr, "Error creating shader type %d\n", ShaderType);
//		exit(0);
//	}
//
//	const GLchar* p[1];
//	p[0] = pShaderText;
//	GLint Lengths[1];
//	Lengths[0] = strlen(pShaderText);
//	glShaderSource(ShaderObj, 1, p, Lengths);
//
//	glCompileShader(ShaderObj);
//	GLint success;
//	glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		GLchar InfoLog[1024];
//		glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
//		fprintf(stderr, "Error compiling shader type %d: '%s'\n", ShaderType, InfoLog);
//		exit(1);
//	}
//
//	glAttachShader(ShaderProgram, ShaderObj);
//}
//
//static void CompileShaders()
//{
//	GLuint ShaderProgram = glCreateProgram();
//
//	if (ShaderProgram == 0) {
//		fprintf(stderr, "Error creating shader program\n");
//		exit(1);
//	}
//
//	AddShader(ShaderProgram, pVS, GL_VERTEX_SHADER);
//	AddShader(ShaderProgram, pFS, GL_FRAGMENT_SHADER);
//
//	GLint Success = 0;
//	GLchar ErrorLog[1024] = { 0 };
//
//	glLinkProgram(ShaderProgram);
//	glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);
//	if (Success == 0) {
//		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
//		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
//		exit(1);
//	}
//
//	glValidateProgram(ShaderProgram);
//	glGetProgramiv(ShaderProgram, GL_VALIDATE_STATUS, &Success);
//	if (!Success) {
//		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
//		fprintf(stderr, "Invalid shader program: '%s'\n", ErrorLog);
//		exit(1);
//	}
//
//	glUseProgram(ShaderProgram);
//}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Draw A Triangle");
	glutDisplayFunc(myDisplay);

	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	printf("GL version: %s\n", glGetString(GL_VERSION));

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	CreateVertexBuffer(1);
	CreateVertexBuffer(2);
	CreateVertexBuffer(3);

	//CompileShaders();

    glutMainLoop();
    return 0;
}


