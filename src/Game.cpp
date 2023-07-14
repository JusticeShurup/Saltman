#include "Game.h"


Game::Game()
{

}

Game::~Game()
{

}

void Game::handleInput()
{
    while (m_window.pollEvent(m_event))
    {
        // state_.handleInput()
    }
}

void Game::update()
{
    float deltaTime = m_clock.restart().asSeconds(); 
    // state_.update(event_)
}

void Game::render()
{
    m_window.clear();
    //state_.render(window_)
    m_window.display();
}

sf::RenderWindow* Game::getWindow()
{
    return &m_window;
}

sf::Time Game::getElapsedTime()
{
    return m_clock.getElapsedTime();
}