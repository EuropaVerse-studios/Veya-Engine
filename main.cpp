// ========================================
// IL TUO PRIMO GAME ENGINE - STEP 1
// Obiettivo: Aprire una finestra blu
// ========================================

// Include SDL3 - la libreria per finestre/grafica/input
#include <SDL3/SDL.h>
#include <stdio.h>

// Funzione principale - da qui parte tutto
int main(int argc, char* argv[]) {
    
    // ========================================
    // STEP 1: Inizializza SDL
    // ========================================
    // SDL_Init prepara SDL per funzionare
    // SDL_INIT_VIDEO = vogliamo usare finestre e grafica
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("Errore inizializzazione SDL: %s\n", SDL_GetError());
        return -1;
    }
    
    // ========================================
    // STEP 2: Crea la finestra
    // ========================================
    // SDL_Window* = puntatore alla finestra (come in C)
    SDL_Window* window = SDL_CreateWindow(
        "Il Mio Primo Engine!",  // Titolo della finestra
        800,                      // Larghezza in pixel
        600,                      // Altezza in pixel
        0                         // Flags (0 = finestra normale)
    );
    
    // Controlla se la finestra è stata creata
    if (!window) {
        printf("Errore creazione finestra: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    
    // ========================================
    // STEP 3: Crea il renderer
    // ========================================
    // Il renderer è quello che disegna sullo schermo
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    
    if (!renderer) {
        printf("Errore creazione renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    
    // ========================================
    // STEP 4: Game Loop (ciclo principale)
    // ========================================
    // Questa variabile controlla se il gioco sta girando
    bool running = true;
    
    // SDL_Event gestisce eventi (chiusura finestra, tastiera, ecc.)
    SDL_Event event;
    // Posizione del quadrato (variabili che cambieranno)
    float playerX = 350;
    float playerY = 250;
    
    // IL CUORE DEL ENGINE: loop infinito finché running = true
    while (running) {
        
        // --- Gestione Eventi ---
        // Controlla se è successo qualcosa (click, tasti, chiusura)
        while (SDL_PollEvent(&event)) {
            // Se l'utente clicca la X per chiudere
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            
            // EXTRA: Se premi ESC chiudi anche
            if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.key == SDLK_ESCAPE) {
                    running = false;
                }
            }
        }
        
        // --- Rendering (disegno) ---
        
        // Imposta colore di sfondo (R, G, B, A) da 0-255
        // Qui: blu scuro
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        
        // Pulisce lo schermo col colore impostato
        SDL_RenderClear(renderer);
        
        // Disegna un rettangolo rosso al centro
        SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
        SDL_FRect rect = {100, 100, 200, 150}; // x, y, larghezza, altezza
        SDL_RenderFillRect(renderer, &rect);
        // Quadrato verde
        SDL_SetRenderDrawColor(renderer, 50, 255, 50, 255);
        SDL_FRect rect2 = {500, 400, 80, 80};
        SDL_RenderFillRect(renderer, &rect2);
        
        // Mostra tutto sullo schermo (swap dei buffer)
        SDL_RenderPresent(renderer);
        
        // Piccolo delay per non usare 100% CPU
        SDL_Delay(16); // ~60 FPS (1000ms/60 = 16ms)
    }
    
    // ========================================
    // STEP 5: Pulizia e chiusura
    // ========================================
    // Importante! Libera la memoria allocata
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
