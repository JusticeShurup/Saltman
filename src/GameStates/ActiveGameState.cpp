#include "GameStates/ActiveGameState.h"
#include "Containers/AssetsContainer.h"
#include "Game.h"
#include <iostream>

ActiveGameState::ActiveGameState(Game* game) : IGameState(game)
{
    obj = new Player("SaltmanTextures.png");
    obj->setPosition(500, 500);
    //camera = new Camera({1920 / 5, 1080 / 5}, {500, 500}, game->getWindow());

}

ActiveGameState::~ActiveGameState()
{
    delete obj;
}

void ActiveGameState::handleUpdate(sf::Event& event)
{

}

void ActiveGameState::update(float deltaTime) 
{
    obj->update(deltaTime, sf::Vector2f(sf::Mouse::getPosition(*game_->getWindow())));
    //camera->setPosition(obj->getPosition());
}

void ActiveGameState::render(sf::RenderTarget &target, sf::RenderStates states)
{
    target.draw(*obj);
}