#pragma once

class Texture
{
private:
    struct TextureDimensions
    {
        int texWidth = 0;
        int texHeight = 0;
    };
    TextureDimensions texData;
    Texture(); //Private constructor. Creation method only with Load function
public:
    unsigned int tex = 0;
    
    static Texture* Load(const char* _filename);

    unsigned int GetId();
    const TextureDimensions& GetTextureData() const;
};
