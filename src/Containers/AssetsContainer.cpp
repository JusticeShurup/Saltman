#include "Containers/AssetsContainer.h"
#include <iostream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

std::vector<std::string> getAllFileNamesInPath(std::string pathName)
{
    std::vector<std::string> fileNames;

    fs::path path = pathName;
    fs::directory_iterator it(path);
    for (auto fullPath : it) fileNames.push_back(fullPath.path().filename().string());
    return fileNames;
} 

AssetsContainer* AssetsContainer::instance = nullptr;

AssetsContainer* AssetsContainer::getInstance()
{
    if (!instance)
    {
        instance = new AssetsContainer;
    }
    return instance;
}

sf::Texture* AssetsContainer::getTexture(std::string folderName, std::string textureName)
{
    return textures_[folderName][textureName];
}

sf::Texture* AssetsContainer::getCharacterTexture(std::string textureName)
{
    return textures_["CharacterTexture"][textureName];
}

sf::Texture* AssetsContainer::getCharacterTextureSheet(std::string sheetName)
{
    return textures_["CharacterTextureSheets"][sheetName];
}

AssetsContainer::AssetsContainer()
{
    loadTextures();
    //loadSounds();
}

void AssetsContainer::loadTextures()
{
    std::vector<std::string> textureFolderNames = getAllFileNamesInPath("../assets/Textures"); 

    for (std::string folderName : textureFolderNames)
    {
        std::map<std::string, sf::Texture*> folderTextures;
        std::vector<std::string> texturesFileNames = getAllFileNamesInPath("../assets/Textures/" + folderName);
        for (std::string fileName : texturesFileNames)
        {
            sf::Texture* texture = new sf::Texture;
            if (texture->loadFromFile("../assets/Textures/" + folderName + "/" + fileName))
            {
                std::cout << "../assets/Textures/" + folderName + "/" + fileName << ": Texture loaded" << std::endl; 
            }

            folderTextures[fileName] = texture;
        }
        textures_[folderName] = folderTextures;
    }
}

void AssetsContainer::loadSounds()
{
    /*
    std::vector<std::string> soundFolderNames = getAllFileNamesInPath("../assets/Sounds"); 

    for (std::string folderName : soundFolderNames)
    {
        std::map<std::string, sf::Texture*> folderSounds;
        std::vector<std::string> soundsFileNames = getAllFileNamesInPath("../assets/Sounds/" + folderName);
        for (std::string fileName : soundsFileNames)
        {
            sf::Sound* sound = new sf::Sound;
            if (sound->loadFromFile("../assets/Sounds/" + folderName + "/" + fileName))
            {
                std::cout << "../assets/Sounds/" + folderName + "/" + fileName << ": Texture loaded" << std::endl; 
            }

            folderSounds[fileName] = texture;
        }
        textures_[folderName] = folderSounds;
    }
    */
}
