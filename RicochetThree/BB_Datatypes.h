#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "json.hpp"

using json = nlohmann::json;

// ReSharper disable once IdentifierTypo
namespace BB_Datatypes
{
    static const std::string ASSETS_PATH = "Assets\\";
    static const std::string MAIN_ATLAS_NAME = "mainAtlas.png";
    static const std::string MAIN_ATLAS_JSON_NAME = "mainAtlas.json";
    
    struct CoreSettingsData
    {
        std::string windowName;
        int resX, resY;

        CoreSettingsData()
        {
            windowName = "Bumbo Engine Test";
            resX = 1920;
            resY = 1080;
        }

        CoreSettingsData(const std::string& windowName_, const int resX_, const int resY_, const int setNumber_)
        {
            windowName = windowName_;
            resX = resX_;
            resY = resY_;
        }
    };

    struct SpriteData
    {
        std::string textureKey;
        sf::Sprite sprite;

        SpriteData()
        {
            textureKey = "";
            sprite = sf::Sprite();
        }

        SpriteData(const std::string& textureKey_, const sf::Sprite& sprite_)
        {
            textureKey = textureKey_;
            sprite = sprite_;
        }

        /*
         *Serializable* Load(json saveData) override
        {
            textureKey = saveData[JSON_SPRITE_TEXTURE_KEY];
            sprite = sf::Sprite(BB_Core::mainAtlas, BB_Core::mainAtlasCoords[textureKey]);
            sprite.setPosition(saveData[JSON_SPRITE_POS_X], saveData[JSON_SPRITE_POS_Y]);
            
            return this;
        }

        json Save() override
        {
            json saveData = json::object();
            saveData[JSON_SPRITE_TEXTURE_KEY] = textureKey;
            const sf::Vector2f& position = sprite.getPosition();
            saveData[JSON_SPRITE_POS_X] = position.x;
            saveData[JSON_SPRITE_POS_Y] = position.y;
            
            return saveData;
        }
        */
    };
}
