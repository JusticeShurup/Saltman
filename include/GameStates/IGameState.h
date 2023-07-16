#ifndef _I_GAME_STATE_H_
#define _I_GAME_STATE_H_
#include <SFML/Graphics.hpp>

class Game;
class IGameState
{
protected:
    Game* game_;

public:
    IGameState(Game* game);

    virtual void handleUpdate(sf::Event& event) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderTarget& target, sf::RenderStates states) = 0;  
};



#endif