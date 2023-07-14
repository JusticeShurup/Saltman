#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <SFML/Graphics.hpp>
#include <vector>

class GameObject : public sf::Drawable
{
public:
    GameObject();
    ~GameObject();

    void setPosition(sf::Vector2f coords);
    void setPosition(float x, float y);
    void move(sf::Vector2f dcoodrs);

    sf::Vector2f getPosition() const;


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    sf::Vector2f position;
    std::vector<sf::Sprite> sprites;
};

#endif 