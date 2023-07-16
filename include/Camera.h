#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <SFML/Graphics.hpp>

class Camera 
{
public:
    Camera(sf::Vector2f size, sf::Vector2f position, sf::RenderWindow* window);

    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition() const;

    void setSize(sf::Vector2f size);
    sf::Vector2f getSize() const;

private:
    sf::View view_;
    sf::RenderWindow* window_;
};

#endif 