#include "Menu.h"
#include "../Rendering/PixelFont.h"

Menu::Menu() {
    options[0] = "START";
    options[1] = "OPTIONS";
    options[2] = "QUIT";
    numOptions = 3;
    selectedOption = 0;
}

int Menu::handleInput(SDL_Event& event) {
    if (event.type == SDL_EVENT_KEY_DOWN) {
        if (event.key.key == SDLK_UP) {
            selectedOption--;
            if (selectedOption < 0) selectedOption = numOptions - 1;
        }
        if (event.key.key == SDLK_DOWN) {
            selectedOption++;
            if (selectedOption >= numOptions) selectedOption = 0;
        }
        if (event.key.key == SDLK_RETURN) {
            return selectedOption;
        }
    }
    return -1;
}

void Menu::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 20, 20, 40, 255);
    SDL_RenderClear(renderer);
    
    int startY = 200;
    int spacing = 80;
    
    for (int i = 0; i < numOptions; i++) {
        if (i == selectedOption) {
            SDL_SetRenderDrawColor(renderer, 255, 200, 50, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
        }
        int y = startY + (i * spacing);
        PixelFont::drawWord(renderer, options[i], 250, y, 4, 2);
    }
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 100, 255);
    int arrowY = startY + (selectedOption * spacing) + 12;
    for (int i = 0; i < 5; i++) {
        PixelFont::drawPixel(renderer, 200, arrowY + i, 4);
        PixelFont::drawPixel(renderer, 204, arrowY + i - 1, 4);
        PixelFont::drawPixel(renderer, 208, arrowY + i - 2, 4);
    }
}
