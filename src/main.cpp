#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::CircleShape shape(100.f);

    shape.setFillColor(sf::Color::Green);
    sf::Clock clock;

    float deltaTime = 0;
    
    sf::Vector2f direction = {1, 0};
    float speed = 500;


    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        shape.move(direction * speed * deltaTime);
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}