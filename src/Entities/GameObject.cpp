#include "Entities/GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::setPosition(sf::Vector2f coords)
{
    m_position = coords;
}

void GameObject::setPosition(float x, float y)
{
    m_position = {x, y};
}

sf::Vector2f GameObject::getPosition() const
{
    return m_position;
}

void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (sf::Sprite spr : m_sprites)
    {
        target.draw(spr);
    }    

}