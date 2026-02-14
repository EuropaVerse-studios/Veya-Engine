#ifndef ENGINE_H
#define ENGINE_H

#include <SDL3/SDL.h>
#include "GameState.h"
#include "../UI/Menu.h"

class Engine {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    GameState currentState;
    Menu menu;
    float playerX;
    float playerY;
    
    void handleEvents();
    void update();
    void render();
    
public:
    Engine();
    ~Engine();
    bool init();
    void run();
    void shutdown();
};

#endif
