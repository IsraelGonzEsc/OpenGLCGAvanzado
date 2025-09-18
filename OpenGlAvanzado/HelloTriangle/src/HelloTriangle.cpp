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

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(940, 980, "Hello triangles", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "error al inciar glad" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(window, checkKeyboard);

    application.SetUp();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        application.Keyboard();
        application.Update();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        application.Draw();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
