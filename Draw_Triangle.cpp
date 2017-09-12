#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "vec.h"

static void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
}


static void CreateVertexBuffer()
{
    vec3 Vertices[3];
    Vertices[0] = vec3(-0.5f, -0.5f, 0.0f);
    Vertices[1] = vec3(0.5f, -0.5f, 0.0f);
    Vertices[2] = vec3(0.0f, 0.5f, 0.0f);

	// Create and initialize a buffer object
	GLuint buffer;
 	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	// Create a vertex array object
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(0);
}


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

	CreateVertexBuffer();

    glutMainLoop();
    return 0;
}


