
#include "Game.h"


Game::Game()
{
    window_ = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Game");
    character_.setTexture(*AssetsContainer::getInstance()->getTexture("CharacterTextures", "Stickman.png"), true);
    character_.setPosition(1920 / 2, 1080 / 2);
    character_.setScale(sf::Vector2f(5, 5));
}

Game::~Game()
{
    delete window_;
}

void Game::run()
{
    is_running_ = true;
    while (is_running_)
    {
        handleInput();
        update();
        render();
    }
}


void Game::handleInput()
{
    while (window_->pollEvent(event_))
    {
        // state_.handleInput()
        if (event_.type == sf::Event::Closed)
        {
            window_->close();
            is_running_ = false;
        }
    }
}

void Game::update()
{
    float deltaTime = clock_.restart().asSeconds(); 
    // state_.update(event_)
}

void Game::render()
{
    window_->clear(sf::Color::Red);
    window_->draw(character_);
    window_->display();
}

sf::RenderWindow* Game::getWindow()
{
    return window_;
}

sf::Time Game::getElapsedTime()
{
    return clock_.getElapsedTime();
}
