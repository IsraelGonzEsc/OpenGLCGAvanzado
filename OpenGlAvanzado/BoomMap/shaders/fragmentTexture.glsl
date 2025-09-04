#version 460

in vec4 color;
in vec2 texCoord;
out vec4 fragColor;
uniform sampler2D RockTexture;

void main()
{    
    vec4 texelColor = texture(RockTexture, texCoord);

    fragColor = texelColor;
}
