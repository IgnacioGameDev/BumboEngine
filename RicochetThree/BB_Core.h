#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "BB_Datatypes.h"



class BB_Core
{
public:

    static sf::RenderWindow mainWindow;

    static int entityCount;
    static std::vector<int> entityIds;

    static sf::Texture mainAtlas;
    static std::unordered_map<std::string, sf::IntRect> mainAtlasCoords;
    static std::unordered_map<int, BB_Datatypes::SpriteData> loadedSprites;
    static std::unordered_map<int, sf::Sprite*> activeSprites;
    
    static void Init(const BB_Datatypes::CoreSettingsData&);
    static void ProcessInput();
    static void RenderMainWindow();
    
    static int CreateEntity();
    
    static void LoadSprite(int, const std::string&);
    static void LoadAddSprite(int, const std::string&, float, float);
    static void SetSpriteActive(int, bool);
};