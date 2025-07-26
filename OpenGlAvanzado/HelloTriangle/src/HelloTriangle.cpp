#include "glad.h"
#include "GLFW/glfw3.h"
#include "Application.h"
#include <iostream>

Application application;

void checkKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, 1);
    }
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(940, 980, "Hello triangle", NULL, NULL);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    

    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "error al inciar glad" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(window, checkKeyboard);

    application.SetUp();


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        /* Poll for and process events */
        glfwPollEvents();
        application.Update();

        /* Render here */


        /* Swap front and back buffers */
        glClear(GL_COLOR_BUFFER_BIT);
        application.Draw();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}