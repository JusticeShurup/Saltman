#ifndef _ASSETS_CONTAINER_H_
#define _ASSETS_CONTAINER_H_

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/*
TODO: 
LoadSounds()
*/

class AssetsContainer
{
public:
    static AssetsContainer* getInstance();

    sf::Texture* getTexture(std::string folderName, std::string textureName);
    sf::Texture* getCharacterTexture(std::string textureName);
    sf::Texture* getCharacterTextureSheet(std::string sheetName);
    
private:
    AssetsContainer();
    
    void loadTextures();
    void loadSounds();

    //<FolderName, Map<TextureName, Texture>>
    std::map<std::string, std::map<std::string, sf::Texture*>> textures_; 
    std::map<std::string, std::map<std::string, sf::Sound*>> sounds_; 
    static AssetsContainer* instance;
};

#endif