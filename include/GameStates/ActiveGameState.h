#ifndef _ACTIVE_GAME_STATE_H_
#define _ACTIVE_GAME_STATE_H_
#include "GameStates/IGameState.h"
#include "Entities/Player.h"
#include "Camera.h"

class ActiveGameState : public IGameState
{
public:
    ActiveGameState(Game* game);

    ~ActiveGameState();

    virtual void handleUpdate(sf::Event& event) override;
    virtual void update(float deltaTime) override;
    virtual void render(sf::RenderTarget& target, sf::RenderStates states) override;  
private:
    Player* obj;
    Camera* camera;
};
#endif