#include "Application.h"
#include "ShaderFuncs.h"
#include <iostream>


void Application::SetupShaders()
{
	std::string vertexShader{ loadTextFile("Shaders/vertexPassthru.glsl") };
	std::string fragmentShader{ loadTextFile("Shaders/fragmentPassthru.glsl") };
	//crear programa
	shaders["passthru"] = InitializeProgram(vertexShader, fragmentShader);
	std::cout << "shaders compilados" << std::endl;
}

void Application::SetupGeometry()
{
	std::vector<float> triangle{
		-1.0f,1.0f,-1.0f,1.0f, 
		-1.0f,-1.0f,-1.0f,1.0f,
		1.0f,-1.0f,-1.0f,1.0f,
	};
	//crear vao
	GLuint VAO_id, VBO_id;
	glGenVertexArrays(1, &VAO_id);
	glBindVertexArray(VAO_id);

	geometria["triangulo"] = VAO_id;
	//crear vbo
	// 
	glGenBuffers(1, &VBO_id);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_id);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(float)*triangle.size(),
		&triangle[0],
		GL_STATIC_DRAW
		);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	//pasar arreglo vertices

}

void Application::SetUp()
{
	std::cout << "Application::SetUp()";

}
void Application::Update(){
	std::cout << "Application::Update()";
}
void Application::Draw(){
	std::cout << "Application::Draw()";

	//sleccionamso programa
	glUseProgram(shaders["passthru"]);

	//selecciona la geometria
	glBindVertexArray(geometria["triangulo"]);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}
void Application::Keyboard()
{
	std::cout << "Application::Keyboard()";
}