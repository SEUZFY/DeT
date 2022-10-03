#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "DeT.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h" // mind the orders, include glew.h first and include glfw3.h next -> to use newest OpenGL functions

using namespace std;

int main()
{	
    /* Initialize the window pointer with nullptr */
    GLFWwindow* window(nullptr);

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* User Modification */
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    return EXIT_SUCCESS;
}
