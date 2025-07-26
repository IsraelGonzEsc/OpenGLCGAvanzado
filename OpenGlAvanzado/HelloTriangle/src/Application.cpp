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

void Application::SetupGeometrySingleArray()
{
	std::vector<float> triangle{
		-1.0f,1.0f,-1.0f,1.0f,
		-1.0f,-1.0f,-1.0f,1.0f,
		1.0f,-1.0f,-1.0f,1.0f,
	
			1.0f,0.0f,0.0f,1.0f,//red
			0.0f,1.0f,0.0f,1.0f,//green
			0.0f,0.0f,1.0f,1.0f,//blue
	};


	//crear vao
	GLuint VAO_id, VBO_id;
	glGenVertexArrays(1, &VAO_id);
	glBindVertexArray(VAO_id);

	geometria["triangulo"] = VAO_id;
	//crear vbo vert
	glGenBuffers(1, &VBO_id);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_id);

	glBufferData(GL_ARRAY_BUFFER,
		sizeof(float) * triangle.size(),
		&triangle[0],
		GL_STATIC_DRAW
	);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, (void*) &triangle[0]);
	glEnableVertexAttribArray(0);
	//pasar arreglo vertices

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)&triangle[11]);
	glEnableVertexAttribArray(1);
}


void Application::SetupGeometry()
{
	std::vector<float> triangle{
		-1.0f,1.0f,-1.0f,1.0f, 
		-1.0f,-1.0f,-1.0f,1.0f,
		1.0f,-1.0f,-1.0f,1.0f,
	};

	std::vector<float> TriangleColor{
	1.0f,0.0f,0.0f,1.0f,
	0.0f,1.0f,0.0f,1.0f,
	0.0f,0.0f,1.0f,1.0f,
	};

	//crear vao
	GLuint VAO_id, VBO_id, VBO_idColor;
	glGenVertexArrays(1, &VAO_id);
	glBindVertexArray(VAO_id);

	geometria["triangulo"] = VAO_id;
	//crear vbo vert
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

	glGenBuffers(1, &VBO_idColor);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_idColor);


	glBufferData(GL_ARRAY_BUFFER,
		sizeof(float) * TriangleColor.size(),
		&TriangleColor[0],
		GL_STATIC_DRAW
	);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
}

void Application::SetUp()
{

	SetupShaders();
	SetupGeometry();
	SetupGeometrySingleArray();

}
void Application::Update(){
	
}
void Application::Draw(){
	

	//sleccionamso programa
	glUseProgram(shaders["passthru"]);

	//selecciona la geometria
	glBindVertexArray(geometria["triangulo"]);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}
void Application::Keyboard()
{

}