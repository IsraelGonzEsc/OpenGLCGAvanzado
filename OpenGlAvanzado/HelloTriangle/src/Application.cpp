#include "Application.h"
#include "ShaderFuncs.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <algorithm>

void Application::SetupShaders()
{
    std::string vertexShader{ loadTextFile("Shaders/vertexPassthru.glsl") };
    std::string fragmentShader{ loadTextFile("Shaders/fragmentPassthru.glsl") };
    shaders["passthru"] = InitializeProgram(vertexShader, fragmentShader);
}

void Application::SetupGeometry2()
{

    std::vector<float> triangle1{
        -1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f, 1.0f,
         0.0f,-1.0f, 1.0f, 1.0f
    };
    currentColors1 = {1,0,0,1, 1,0,0,1, 1,0,0,1}; 

    GLuint VAO1, VBO1;
    glGenVertexArrays(1,&VAO1); glBindVertexArray(VAO1);
    geometria["triangulo1"] = VAO1;

    glGenBuffers(1,&VBO1); glBindBuffer(GL_ARRAY_BUFFER,VBO1);
    glBufferData(GL_ARRAY_BUFFER,sizeof(float)*triangle1.size(),&triangle1[0],GL_STATIC_DRAW);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,0,0); glEnableVertexAttribArray(0);

    glGenBuffers(1,&VBOColor1_id); glBindBuffer(GL_ARRAY_BUFFER,VBOColor1_id);
    glBufferData(GL_ARRAY_BUFFER,sizeof(float)*currentColors1.size(),&currentColors1[0],GL_DYNAMIC_DRAW);
    glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,0,0); glEnableVertexAttribArray(1);


    std::vector<float> triangle2{
         -1.0f, 0.0f, -0.75f, 1.0f,
         1.0f, 0.0f, -0.75f, 1.0f,
         1.0f,-1.0f, -0.75f, 1.0f
    };
    currentColors2 = {0,0,1,1, 0,0,1,1, 0,0,1,1}; 

    GLuint VAO2, VBO2;
    glGenVertexArrays(1,&VAO2); glBindVertexArray(VAO2);
    geometria["triangulo2"] = VAO2;

    glGenBuffers(1,&VBO2); glBindBuffer(GL_ARRAY_BUFFER,VBO2);
    glBufferData(GL_ARRAY_BUFFER,sizeof(float)*triangle2.size(),&triangle2[0],GL_STATIC_DRAW);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,0,0); glEnableVertexAttribArray(0);

    glGenBuffers(1,&VBOColor2_id); glBindBuffer(GL_ARRAY_BUFFER,VBOColor2_id);
    glBufferData(GL_ARRAY_BUFFER,sizeof(float)*currentColors2.size(),&currentColors2[0],GL_DYNAMIC_DRAW);
    glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,0,0); glEnableVertexAttribArray(1);
}

void Application::SetUp() { SetupShaders(); SetupGeometry2(); }

void Application::Keyboard()
{
    if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_RIGHT) == GLFW_PRESS)
        targetColorState = true; // azul
    if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_LEFT) == GLFW_PRESS)
        targetColorState = false; // rojo
}

void Application::Update()
{
 
    std::vector<float> targetColor = targetColorState ? std::vector<float>{0,0,1,1} : std::vector<float>{1,0,0,1};

  
    for(int i=0;i<currentColors1.size();i+=4){
        for(int c=0;c<3;c++){
            float diff = targetColor[c]-currentColors1[i+c];
            if(std::abs(diff) > colorStep) currentColors1[i+c] += (diff>0?colorStep:-colorStep);
            else currentColors1[i+c] = targetColor[c];
        }
    }

 
    for(int i=0;i<currentColors2.size();i+=4){
        for(int c=0;c<3;c++){
            float diff = targetColor[c]-currentColors2[i+c];
            if(std::abs(diff) > colorStep) currentColors2[i+c] += (diff>0?colorStep:-colorStep);
            else currentColors2[i+c] = targetColor[c];
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER,VBOColor1_id);
    glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(float)*currentColors1.size(),&currentColors1[0]);

    glBindBuffer(GL_ARRAY_BUFFER,VBOColor2_id);
    glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(float)*currentColors2.size(),&currentColors2[0]);
}

void Application::Draw()
{
    glUseProgram(shaders["passthru"]);

    glBindVertexArray(geometria["triangulo1"]);
    glDrawArrays(GL_TRIANGLES,0,3);

    glBindVertexArray(geometria["triangulo2"]);
    glDrawArrays(GL_TRIANGLES,0,3);
}
