#include "Entities/GameObject.h"
#include "Containers/AssetsContainer.h"

GameObject::GameObject(std::string textureName)
{
    static AssetsContainer* assets = AssetsContainer::getInstance();

    sprite_.setTexture(*assets->getCharacterTextureSheet(textureName));
    sprite_.setOrigin(17 / 2, 17 / 2);

    direction_ = 0;
    animator = new Animator(&sprite_, &direction_, 2.f, 3);
}

GameObject::GameObject(std::vector<std::pair<std::string, std::string>> spritesTextures, std::vector<sf::Vector2f> spritesOrigins)
{

}

GameObject::~GameObject()
{

}

void GameObject::setPosition(sf::Vector2f coords)
{
    sprite_.setPosition(coords);
}

void GameObject::setPosition(float x, float y)
{
    sprite_.setPosition(x, y);
}   

void GameObject::move(sf::Vector2f dcoodrs)
{
    sprite_.move(dcoodrs);
}

sf::Vector2f GameObject::getPosition() const
{
    return sprite_.getPosition();
}

void GameObject::setScale(sf::Vector2f scale)
{
    sprite_.setScale(scale);
}

sf::Vector2f GameObject::getSpriteSize() const
{
    return sprite_.getGlobalBounds().getSize();
}

void GameObject::setDirection(int direction)
{
    direction_ = direction;
}

int GameObject::getDirection() const
{
    return direction_;
}

void GameObject::update(float deltaTime)
{
    animator->update(deltaTime);
}

void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite_);

}