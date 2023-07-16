#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_
#include <SFML/Graphics.hpp>

enum Direction {N = 0, NE = 1, E = 2, SE = 3, S = 4, SW = 5, W = 6, NW = 7};

class Animator
{
public:
    Animator(sf::Sprite* sprite, int* direction, float animationDuration, int frameCount);

    void update(float deltaTime);
private:
    sf::Sprite* sprite_; // Animator will change sprite's texture
    int& direction_;
    
    float animationDuration_;
    float animationStep_;
    float elapsedTime_;
    int frameCount_;

    int currentFrame_;
};

#endif 