#version 330 core
out vec4 FragColor;

in vec2 fTex;
in vec3 fcolor;
uniform sampler2D tex;
    
void main()
{
    FragColor = texture2D(tex, fTex) * vec4(fcolor,1);
};