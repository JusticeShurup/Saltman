#ifndef _GAME_H_
#define _GAME_H_
#include <SFML/Graphics.hpp>

class Game
{    
public:
    Game();
    ~Game();

    void handleInput();
    void update();
    void render();

    sf::RenderWindow* getWindow();

    sf::Time getElapsedTime();

private:
    sf::RenderWindow m_window;
    sf::Clock m_clock;
    sf::Event m_event;

};

#endif