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
public:
    unsigned int tex = 0;

    Texture();
    static Texture* Load(const char* _filename);

    unsigned int GetId();
    const TextureDimensions& GetTextureData() const;
};
