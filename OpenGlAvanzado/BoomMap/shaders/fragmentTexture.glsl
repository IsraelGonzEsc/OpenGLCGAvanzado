#version 460 core

in vec2 texCoord;
in vec3 FragPos;
in vec3 TangentLightPos;
in vec3 TangentViewPos;

out vec4 fragColor;

uniform sampler2D diffuse;
uniform sampler2D normalMap;

void main()
{
    // Obtener normal del normal map
    vec3 normal = texture(normalMap, texCoord).rgb;
    normal = normalize(normal * 2.0 - 1.0); // map 0..1 a -1..1

    // Luz simple
    vec3 lightDir = normalize(TangentLightPos - FragPos);
    float diff = max(dot(normal, lightDir), 1.0);

    // Difuso
    vec3 color = texture(diffuse, texCoord).rgb;
    vec3 result = diff * color;

    fragColor = vec4(result, 1.0);
}
