#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include "Containers/AssetsContainer.h"

class Game
{    
public:
    Game();
    ~Game();

    void run();

    void handleInput();
    void update();
    void render();

    sf::RenderWindow* getWindow();

    sf::Time getElapsedTime();

private:
    sf::RenderWindow* window_;
    sf::Clock clock_;
    sf::Event event_;
    bool is_running_;


    sf::Sprite character_;

};

#endif