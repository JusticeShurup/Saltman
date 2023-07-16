#ifndef _UTILS_H_
#define _UTILS_H_
#define M_PI 3.14159265358979323846

#include <SFML/Graphics.hpp>
#include <math.h>

inline float calculateMouseAngle(sf::Vector2f mousePos, sf::Vector2f targetPos)
{
    float deltaX = targetPos.x - mousePos.x; 
    float deltaY = targetPos.y - mousePos.y;
    float angle = atan2(deltaY, deltaX) * 180 / M_PI;
    return int(angle + 270 ) % 360;
}

#endif
