	#version 460 core

	layout(location = 0) in vec4 vPosition;
	layout(location = 1) in vec2 vTextCoord;

	out vec2 texCoord;

	uniform float time;
	uniform mat4 camera;
	uniform mat4 projection;
	uniform mat4 acumTrans;
	uniform sampler2D height; //esto es para abrir la text en el shad



	void main()
	{
		vec4 color = texture(height, vTextCoord);
		vec4 newPosition = vPosition;

		newPosition.y =2.0f * (color.r * 0.2126f + color.g * 0.7152f + color.b * 0.0722f);


		texCoord = vTextCoord;
		gl_Position = 
			projection * 
			camera * 
			acumTrans * 
		newPosition;  
	}
