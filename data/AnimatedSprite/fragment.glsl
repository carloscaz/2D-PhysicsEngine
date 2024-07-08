#version 330 core
out vec4 FragColor;

in vec2 fTex;
uniform sampler2D tex;
uniform vec2 frameSize;
uniform int frameIndex;
    
void main()
{
    vec2 fragmentOffset = vec2(frameIndex * frameSize.x, 0);
    vec2 uv = fTex * frameSize + fragmentOffset;
    FragColor = texture2D(tex,uv);
};