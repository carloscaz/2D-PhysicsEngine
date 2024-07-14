#pragma once

class Vector3D;

class Shader
{
private:
    const char* vertexShaderSource;
    const char* fragmentShaderSource;

    unsigned int VertexShader;
    unsigned int FragmentShader;
    int retCode;
    char errorLog[1024];

    unsigned int m_id;
    Shader(){}; //Private constructor. Method creation only available with Load function
public:
    unsigned int GetId();
    static Shader* Load(const char* _vertexFile, const char* _fragmentFile);

    void SetMatrix(const Vector3D& _pos, const Vector3D& _scale);
    
};
