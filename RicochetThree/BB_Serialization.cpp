#include "BB_Serialization.h"

#include <fstream>

#include "BB_Core.h"

using namespace BB_Datatypes;

const std::string BB_Serialization::JSON_ATLAS_SPRITE_ARRAY = "frames";
const std::string BB_Serialization::JSON_ATLAS_SPRITE_NAME = "filename";
const std::string BB_Serialization::JSON_ATLAS_DIMENSIONS_ARRAY = "frame";

const std::string BB_Serialization::JSON_LEVEL_HEADER = "Level Name";
const std::string BB_Serialization::JSON_LEVEL_ENTITIES_HEADER = "Level Entities";
    
const std::string BB_Serialization::JSON_SPRITE_HEADER = "Sprite Data";
const std::string BB_Serialization::JSON_SPRITE_TEXTURE_KEY = "Texture Key";
const std::string BB_Serialization::JSON_SPRITE_POS_X = "X Position";
const std::string BB_Serialization::JSON_SPRITE_POS_Y = "Y Position";


json BB_Serialization::Save(const SpriteData& data)
{
    json saveData = json::object();
    saveData[JSON_SPRITE_TEXTURE_KEY] = data.textureKey;
    const sf::Vector2f& position = data.sprite.getPosition();
    saveData[JSON_SPRITE_POS_X] = position.x;
    saveData[JSON_SPRITE_POS_Y] = position.y;

    return saveData;
}

SpriteData BB_Serialization::Load(const json& saveData)
{
    auto newSprite = sf::Sprite(BB_Core::mainAtlas, BB_Core::mainAtlasCoords[saveData[JSON_SPRITE_TEXTURE_KEY]]);
    newSprite.setPosition(saveData[JSON_SPRITE_POS_X], saveData[JSON_SPRITE_POS_Y]);
    return {saveData[JSON_SPRITE_TEXTURE_KEY], newSprite};
    
    //return {saveData[JSON_SPRITE_TEXTURE_KEY], sf::Sprite(BB_Core::mainAtlas, BB_Core::mainAtlasCoords[saveData[JSON_SPRITE_TEXTURE_KEY]])};
}

void BB_Serialization::ParseTextureAtlas(const std::string& atlasJsonFilePath, std::unordered_map<std::string, sf::IntRect>& atlasCoords)
{
    std::ifstream f(atlasJsonFilePath);
    const json data = json::parse(f);
    for (int i = 0; i < data[JSON_ATLAS_SPRITE_ARRAY].size(); i++)
    {
        const json currentFrame = data[JSON_ATLAS_SPRITE_ARRAY][i][JSON_ATLAS_DIMENSIONS_ARRAY];

        atlasCoords[data[JSON_ATLAS_SPRITE_ARRAY][i][JSON_ATLAS_SPRITE_NAME]] = 
            sf::IntRect(currentFrame["x"], currentFrame["y"], currentFrame["w"], currentFrame["h"]);
    }
}
