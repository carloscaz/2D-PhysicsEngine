#version 330 core
layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vColor;
layout (location = 2) in vec2 vTex;


out vec2 fTex;
out vec3 fcolor;
uniform mat4 mvp;
    
void main()
{
    gl_Position = mvp * vec4(vPos, 1.0);
    fTex = vTex;
    fcolor = vColor;
}