#include "BB_Core.h"
#include "json.hpp"
#include "BB_Serialization.h"
#include "SFML/Graphics.hpp"

using namespace BB_Datatypes;
using json = nlohmann::json;

sf::RenderWindow BB_Core::mainWindow;

int BB_Core::entityCount;
std::vector<int> BB_Core::entityIds;

sf::Texture BB_Core::mainAtlas;
std::unordered_map<std::string, sf::IntRect> BB_Core::mainAtlasCoords; 
std::unordered_map<int, SpriteData> BB_Core::loadedSprites;
std::unordered_map<int, sf::Sprite*> BB_Core::activeSprites;


void BB_Core::Init(const CoreSettingsData& initSettings)
{
    mainWindow.create(sf::VideoMode(initSettings.resX, initSettings.resY), initSettings.windowName);
    mainWindow.setVerticalSyncEnabled(true);

    mainAtlas.loadFromFile(ASSETS_PATH + MAIN_ATLAS_NAME);
    BB_Serialization::ParseTextureAtlas(ASSETS_PATH + MAIN_ATLAS_JSON_NAME, mainAtlasCoords);
    
    entityCount = 0;
}

void BB_Core::ProcessInput()
{
    sf::Event event{};
    if (mainWindow.pollEvent(event) && event.type == sf::Event::Closed)
        mainWindow.close();
}

void BB_Core::RenderMainWindow()
{
    mainWindow.clear();

    for (const auto& s : activeSprites)
        mainWindow.draw(*s.second);

    mainWindow.display();
}

int BB_Core::CreateEntity()
{
    /*
     *std::pair<std::string, int> newEntity;
    if (name.empty())
        newEntity.first = name;
    else
        newEntity.first = "";
    entities.insert(newEntity);
    */

    entityIds.push_back(entityCount);
    return entityCount++;
}

void BB_Core::LoadSprite(const int id, const std::string& fileName)
{
    loadedSprites[id] = SpriteData(fileName, sf::Sprite(mainAtlas, mainAtlasCoords[fileName]));
}

void BB_Core::LoadAddSprite(const int id, const std::string& fileName, const float posX, const float posY)
{
    LoadSprite(id, fileName);
    loadedSprites[id].sprite.setPosition(posX, posY);
    SetSpriteActive(id, true);
}

void BB_Core::SetSpriteActive(const int id, const bool setActive)
{
    if (setActive && loadedSprites.find(id) != loadedSprites.end())
        activeSprites[id] = &loadedSprites[id].sprite;
    else
        activeSprites.erase(id);
}


