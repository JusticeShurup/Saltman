#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include "Animator/Animator.h"

class GameObject : public sf::Drawable
{
public:
    GameObject();
    GameObject(std::string textureName);
    GameObject(std::vector<std::pair<std::string, std::string>> spriteTextures, std::vector<sf::Vector2f> spriteOrigins);

    ~GameObject();

    void setPosition(sf::Vector2f coords);
    void setPosition(float x, float y);
    void move(sf::Vector2f dcoodrs);
    sf::Vector2f getPosition() const;

    void setScale(sf::Vector2f scale);
        
    sf::Vector2f getSpriteSize() const;

    void setDirection(int direction);
    int getDirection() const;

    void update(float deltaTime);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    sf::Sprite sprite_;
    sf::Vector2f origin_;
    Animator* animator;
    int direction_;
};

#endif 