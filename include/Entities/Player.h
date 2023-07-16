#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entities/Entity.h"

class Player : public Entity
{
public:
    Player(std::string textureName);
    ~Player();

    void handleUpdate(sf::Event& event);
    void update(float deltaTime, sf::Vector2f mousePos);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

};


#endif
