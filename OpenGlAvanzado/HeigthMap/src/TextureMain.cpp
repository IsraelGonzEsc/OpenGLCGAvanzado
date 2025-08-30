#include "glad.h"
#include "GLFW/glfw3.h"
#include "Application.h"
#include <iostream>

Application application;

void checkKeyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    application.Keyboard(key, scancode, action, mods);
}

static void my_cursor_callback(GLFWwindow* window, double xpos, double ypos)
{
    application.mouse(xpos, ypos);
}

int main(void)
{


    if (!glfwInit())
        return -1;

    application.window = glfwCreateWindow(1920, 1080, "Texture", NULL, NULL);
    if (!application.window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(application.window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Error al inicializar GLAD" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(application.window, checkKeyboard);

    glfwSetCursorPosCallback(application.window, my_cursor_callback);

    application.Setup();


    while (!glfwWindowShouldClose(application.window))
    {
        glfwPollEvents();
        application.Update();


        glClear(GL_COLOR_BUFFER_BIT);
        application.Draw();
        
        glfwSwapBuffers(application.window);
    }

    glfwTerminate();
    return 0;
}