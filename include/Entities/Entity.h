#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Entities/GameObject.h"

class Entity : public GameObject
{
public:
    Entity(std::string textureName);

    void setPosition(sf::Vector2f coords);
    void setPosition(float x, float y);
    void move(sf::Vector2f dcoodrs);

    void setHealth(int health);
    int getHealth() const;

    void setStamina(int stamina);
    int getStamina() const;

    void update(float deltaTime);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    int health_;
    int stamina_;

    sf::RectangleShape healthBar_;
    sf::RectangleShape staminaBar_;
    void setBarsPositions(sf::Vector2f pos);
};

#endif