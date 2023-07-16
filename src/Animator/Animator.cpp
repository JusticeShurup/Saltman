#include "Animator/Animator.h"
#include <iostream>

Animator::Animator(sf::Sprite* sprite, int* direction, float animationDuration, int frameCount) 
    : sprite_(sprite), direction_(*direction), animationDuration_(animationDuration), frameCount_(frameCount)
{
    elapsedTime_ = 0;
    currentFrame_ = 1;
    animationStep_ = animationDuration_ / frameCount_;
}

void Animator::update(float deltaTime)
{
    elapsedTime_ += deltaTime;
    if (elapsedTime_ >= animationStep_)
    {
        elapsedTime_ -= animationStep_;
        currentFrame_ = ((currentFrame_) % frameCount_) + 1;
    }
    sprite_->setTextureRect(sf::IntRect((128 / 8) * direction_, (48 / frameCount_) * (currentFrame_ - 1), 16, 48 / 3));
}
