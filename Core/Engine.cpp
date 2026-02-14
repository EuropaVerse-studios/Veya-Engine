#include "Engine.h"
#include "../Rendering/PixelFont.h"
#include <stdio.h>

Engine::Engine() {
    window = nullptr;
    renderer = nullptr;
    running = false;
    currentState = STATE_MENU;
    playerX = 350;
    playerY = 250;
}

Engine::~Engine() {
}

bool Engine::init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("Errore SDL: %s\n", SDL_GetError());
        return false;
    }
    
    window = SDL_CreateWindow("VEYA ENGINE - Modular", 800, 600, 0);
    if (!window) {
        printf("Errore finestra: %s\n", SDL_GetError());
        return false;
    }
    
    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        printf("Errore renderer: %s\n", SDL_GetError());
        return false;
    }
    
    running = true;
    return true;
}

void Engine::run() {
    while (running) {
        handleEvents();
        update();
        render();
        SDL_Delay(16);
    }
}

void Engine::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            running = false;
        }
        if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) {
            running = false;
        }
        
        switch (currentState) {
            case STATE_MENU: {
                int selection = menu.handleInput(event);
                if (selection == 0) currentState = STATE_PLAYING;
                else if (selection == 1) printf("Options!\n");
                else if (selection == 2) running = false;
                break;
            }
            case STATE_PLAYING: {
                if (event.type == SDL_EVENT_KEY_DOWN) {
                    if (event.key.key == SDLK_UP) playerY -= 10;
                    if (event.key.key == SDLK_DOWN) playerY += 10;
                    if (event.key.key == SDLK_LEFT) playerX -= 10;
                    if (event.key.key == SDLK_RIGHT) playerX += 10;
                    if (event.key.key == SDLK_P) currentState = STATE_PAUSED;
                }
                break;
            }
            case STATE_PAUSED: {
                if (event.type == SDL_EVENT_KEY_DOWN) {
                    if (event.key.key == SDLK_P) currentState = STATE_PLAYING;
                    if (event.key.key == SDLK_M) currentState = STATE_MENU;
                }
                break;
            }
        }
    }
}

void Engine::update() {
}

void Engine::render() {
    switch (currentState) {
        case STATE_MENU:
            menu.render(renderer);
            break;
        case STATE_PLAYING:{
            SDL_SetRenderDrawColor(renderer, 30, 60, 120, 255);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
            SDL_FRect rect = {playerX, playerY, 100, 100};
            SDL_RenderFillRect(renderer, &rect);
            break;
        }
        case STATE_PAUSED:{
            SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            PixelFont::drawWord(renderer, "PAUSA", 280, 250, 5, 3);
            break;
        }
    }
    SDL_RenderPresent(renderer);
}

void Engine::shutdown() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}
