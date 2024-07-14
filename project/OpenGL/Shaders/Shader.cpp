#include "Shader.h"

#include <fstream>

#include "GL/glew.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../../project/Math/Vector3D/Vector3D.h"
#include <iostream>
#include <sstream>

unsigned int Shader::GetId()
{
    return m_id;
}

void Shader::SetMatrix(const Vector3D& _pos, const Vector3D& _scale)
{
    glUseProgram(m_id);

    //MVP matrix
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(_pos.X, _pos.Y, _pos.Z));
    model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(_scale.X, _scale.Y, _scale.Z));

    glm::mat4 proj = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);

    glm::mat4 view = glm::mat4(1.0f);
    //view = glm::translate(view, glm::vec3(0.0f, 0.0f, 2.0f));

    glm::mat4 mvp = view * proj * model;

    //Set MVP matrix to shader
    unsigned int transformLoc = glGetUniformLocation(m_id, "mvp");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(mvp));
}

Shader* Shader::Load(const char* _vertexFile, const char* _fragmentFile)
{
    Shader* newShader = new Shader();
    //Retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    
    //Ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try 
    {
        //Open files
        vShaderFile.open(_vertexFile);
        fShaderFile.open(_fragmentFile);
        std::stringstream vShaderStream, fShaderStream;
        
        //Read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        
        //Close file handlers
        vShaderFile.close();
        fShaderFile.close();
        
        //Convert stream into string
        vertexCode   = vShaderStream.str();
        fragmentCode = fShaderStream.str();		
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    
    newShader->vertexShaderSource = vertexCode.c_str();
    newShader->fragmentShaderSource = fragmentCode.c_str();

    const char* vShaderCode =  vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    
    //Compile vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
    glCompileShader(vertexShader);

    //Check for shader compile errors in vertex shader
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //Compile fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);
    glCompileShader(fragmentShader);

    //Check for shader compile errors in fragment shader
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //Create Shader
    newShader->m_id = glCreateProgram();
    glAttachShader(newShader->m_id, vertexShader);
    glAttachShader(newShader->m_id, fragmentShader);
    glLinkProgram(newShader->m_id);
    //Check for linking errors
    glGetProgramiv(newShader->m_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(newShader->m_id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return newShader;
}
