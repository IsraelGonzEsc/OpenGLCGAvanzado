#pragma once
#include <map>
#include <string>
#include <vector>
#include "glad.h"

class Application
{
private:
    std::map<std::string, GLuint> shaders;
    std::map<std::string, GLuint> geometria;
    void SetupShaders();
    void SetupGeometry2();

    GLuint VBOColor1_id;
    GLuint VBOColor2_id;


    std::vector<float> currentColors1;
    std::vector<float> currentColors2;

    
    bool targetColorState = false;

    float colorStep = 0.02f; 

public:
    void SetUp();
    void Update();
    void Draw();
    void Keyboard();
};
