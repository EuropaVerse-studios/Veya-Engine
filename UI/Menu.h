#ifndef MENU_H
#define MENU_H

#include <SDL3/SDL.h>

class Menu {
private:
    const char* options[3];
    int numOptions;
    int selectedOption;
    
public:
    Menu();
    int handleInput(SDL_Event& event);
    void render(SDL_Renderer* renderer);
};

#endif
