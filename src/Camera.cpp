#include "Camera.h"

Camera::Camera(sf::Vector2f size, sf::Vector2f position, sf::RenderWindow* window) : window_(window)
{
    view_.setSize(size);
    view_.setCenter(position);
    window_->setView(view_);
}

void Camera::setPosition(sf::Vector2f position)
{
    view_.setCenter(position);
    window_->setView(view_);
}

sf::Vector2f Camera::getPosition() const
{
    return view_.getCenter();
}

void Camera::setSize(sf::Vector2f size) 
{
    view_.setSize(size);
    window_->setView(view_);
}

sf::Vector2f Camera::getSize() const
{
    return view_.getSize();
}