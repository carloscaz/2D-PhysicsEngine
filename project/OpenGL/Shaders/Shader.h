#pragma once

class Vector3D;

class Shader
{
private:
    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "layout (location = 1) in vec2 vTex;\n"

        "out vec2 fTex;\n"
        "uniform mat4 mvp;\n"
    
        "void main()\n"
        "{\n"
            "gl_Position = mvp * vec4(aPos, 1.0);\n"
            "fTex = vTex;\n"
        "}\n\0";
    
    const char* fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"  

    "in vec2 fTex;\n"
    "uniform sampler2D tex;\n"
    
    "void main()\n"
    "{\n"
        "FragColor = texture2D(tex,fTex);\n"
    "}\n\0";

    unsigned int VertexShader;
    unsigned int FragmentShader;
    int retCode;
    char errorLog[1024];

    unsigned int m_id;
    Shader();
public:
    unsigned int GetId();
    static Shader* Load(const char* _vertexFile, const char* _fragmentFile);

    void SetMatrix(const Vector3D& _pos, const Vector3D& _scale);
    
};
