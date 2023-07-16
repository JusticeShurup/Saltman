
#include "Game.h"


Game::Game()
{
    window_ = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Game");
    state_ = new ActiveGameState(this);

    window_->setFramerateLimit(165);
}

Game::~Game()
{
    delete window_;
    delete state_;
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
        state_->handleUpdate(event_);
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
    state_->update(deltaTime);
}

void Game::render()
{
    window_->clear();
    state_->render(*window_, sf::RenderStates::Default);
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
