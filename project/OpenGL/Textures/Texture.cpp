#include "Texture.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image/stb_image.h"
#include "GL/glew.h"

Texture::Texture()
{
    texData.texWidth = 0;
    texData.texHeight = 0;
}

Texture* Texture::Load(const char* _filename)
{
    Texture* texture = new Texture();
    glGenTextures(1, &texture->tex);
    glBindTexture(GL_TEXTURE_2D, texture->tex);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(_filename, &texture->texData.texWidth, &texture->texData.texHeight, &nrChannels, 0);
    if(data)
    {
        if(nrChannels == 4)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->texData.texWidth, texture->texData.texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }
        else
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->texData.texWidth, texture->texData.texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    else
    {
        std::cout << "Texture not found" << std::endl;
    }

    stbi_image_free(data);

    return texture;
}

unsigned int Texture::GetId()
{
    return tex;
}

const Texture::TextureDimensions& Texture::GetTextureData() const
{
    return texData;
}

