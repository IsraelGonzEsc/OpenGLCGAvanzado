#version 460 core
in vec2 texCoord;
out vec4 fragColor;

uniform sampler2D tex0; // lenna
uniform sampler2D tex1; // balatro
uniform float blendFactor;

void main()
{
    vec4 color0 = texture(tex0, texCoord);
    vec4 color1 = texture(tex1, texCoord);
    
    fragColor = mix(color0, color1, blendFactor);
}