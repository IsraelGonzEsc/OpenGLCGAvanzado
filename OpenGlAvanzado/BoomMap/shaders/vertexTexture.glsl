#version 460 core

layout(location = 0) in vec4 vPosition;
layout(location = 1) in vec2 vTexCoord;

out vec2 texCoord;
out vec3 FragPos;
out vec3 TangentLightPos;
out vec3 TangentViewPos;

uniform mat4 camera;
uniform mat4 projection;
uniform mat4 acumTrans;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
    FragPos = vec3(acumTrans * vPosition);
    texCoord = vTexCoord;

    TangentLightPos = lightPos;
    TangentViewPos = viewPos;

    gl_Position = projection * camera * acumTrans * vPosition;
}
