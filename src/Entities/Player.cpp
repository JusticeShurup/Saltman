#include "Entities/Player.h"
#include <iostream>
#include "Utils.h"

Player::Player(std::string textureName) : Entity(textureName)
{

}

Player::~Player()
{

}

void Player::handleUpdate(sf::Event& event)
{
}

void Player::update(float deltaTime, sf::Vector2f mousePos)
{
    Entity::update(deltaTime);
    float speed = 100;
    sf::Vector2f direction = {0, 0};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        direction += {0, -1};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        direction += {0, 1};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        direction += {-1, 0};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        direction += {1, 0};
    }
    float rotAngle = calculateMouseAngle(mousePos, getPosition());
    // Update this to formula
    if (rotAngle >= 337.5 || rotAngle <= 22.5) setDirection(0);
    else if (rotAngle >= 22.5 && rotAngle <= 67.5) setDirection(1);
    else if (rotAngle >= 67.5 && rotAngle <= 112.5) setDirection(2);
    else if (rotAngle >= 112.5 && rotAngle <= 157.5) setDirection(3);
    else if (rotAngle >= 157.5 && rotAngle <= 202.5) setDirection(4);
    else if (rotAngle >= 202.5 && rotAngle <= 247.5) setDirection(5);
    else if (rotAngle >= 247.5 && rotAngle <= 292.5) setDirection(6);
    else if (rotAngle >= 292.5 && rotAngle <= 337.5) setDirection(7);
    move(direction * speed * deltaTime);


}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    Entity::draw(target, states);
}