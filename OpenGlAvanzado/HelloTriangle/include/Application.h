#pragma once
#include <map>
#include <string>
#include "glad.h"
class Application
{
	private:

		std::map<std::string, GLuint> shaders;
		std::map<std::string, GLuint> geometria;
		void SetupShaders();
		void SetupGeometry();
	public:
		void SetUp();
		void Update();
		void Draw();
		void Keyboard();
};