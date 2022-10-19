#pragma once
#include "BB_Datatypes.h"

class BB_Serialization
{
public:
    static const std::string JSON_ATLAS_SPRITE_ARRAY;
    static const std::string JSON_ATLAS_SPRITE_NAME;
    static const std::string JSON_ATLAS_DIMENSIONS_ARRAY;

    static const std::string JSON_LEVEL_HEADER;
    static const std::string JSON_LEVEL_ENTITIES_HEADER;
    
    static const std::string JSON_SPRITE_HEADER;
    static const std::string JSON_SPRITE_TEXTURE_KEY;
    static const std::string JSON_SPRITE_POS_X;
    static const std::string JSON_SPRITE_POS_Y;
    
    static json Save(const BB_Datatypes::SpriteData&);
    static BB_Datatypes::SpriteData Load(const json&);
    static void ParseTextureAtlas(const std::string&, std::unordered_map<std::string, sf::IntRect>&);
};
