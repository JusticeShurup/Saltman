#include "Entities/Entity.h"

Entity::Entity(std::string textureName) : GameObject(textureName)
{
    healthBar_.setSize({16, 1});
    healthBar_.setOrigin(0, 5);
    healthBar_.setFillColor(sf::Color::Red);
    healthBar_.setOutlineThickness(0.1f);
    healthBar_.setOutlineColor(sf::Color(128, 128, 128));

    staminaBar_.setSize({16, 1});
    staminaBar_.setOrigin(0, 3);
    staminaBar_.setFillColor(sf::Color::Green);
    staminaBar_.setOutlineThickness(0.1f);
    staminaBar_.setOutlineColor(sf::Color(128, 128, 128));
}

void Entity::setPosition(sf::Vector2f coords)
{
    GameObject::setPosition(coords);
    setBarsPositions(coords);
}

void Entity::setPosition(float x, float y)
{
    GameObject::setPosition(x, y);
    setBarsPositions({x, y});
}

void Entity::move(sf::Vector2f dcoords)
{
    GameObject::move(dcoords);
    setBarsPositions(getPosition());
}

void Entity::setHealth(int health)
{
    health_ = health;
}

int Entity::getHealth() const
{
    return health_;
}

void Entity::setStamina(int stamina)
{
    stamina_ = stamina;
}

int Entity::getStamina() const
{
    return stamina_;
}

void Entity::update(float deltaTime)
{
    GameObject::update(deltaTime);
}

void Entity::setBarsPositions(sf::Vector2f pos)
{
    healthBar_.setPosition(pos);
    staminaBar_.setPosition(pos);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    GameObject::draw(target, states);
    target.draw(healthBar_);
    target.draw(staminaBar_);
}