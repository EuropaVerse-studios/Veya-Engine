// ========================================
// VEYA ENGINE - MENU PIXEL-ART
// Step 2: Sistema di stati + Menu navigabile
// ========================================

#include <SDL3/SDL.h>
#include <stdio.h>

// ========================================
// ENUMERAZIONE DEGLI STATI DEL GIOCO
// ========================================
// Un enum è un tipo che può avere solo certi valori
// Serve per tenere traccia dello "stato" in cui si trova il gioco
enum GameState {
    STATE_MENU,      // Siamo nel menu
    STATE_PLAYING,   // Stiamo giocando
    STATE_PAUSED     // Gioco in pausa
};

// ========================================
// FUNZIONE PER DISEGNARE UN PIXEL (rettangolino)
// ========================================
// Questa è una "funzione" - un pezzo di codice riutilizzabile
// Parametri: renderer (dove disegnare), x e y (posizione), size (dimensione pixel)
void drawPixel(SDL_Renderer* renderer, int x, int y, int size) {
    SDL_FRect rect = {(float)x, (float)y, (float)size, (float)size};
    SDL_RenderFillRect(renderer, &rect);
}

// ========================================
// FUNZIONE PER DISEGNARE UNA LETTERA
// ========================================
// Ogni lettera è una griglia 5x7 di pixel
// pattern è un array che dice quali pixel accendere (1) o spegnere (0)
void drawLetter(SDL_Renderer* renderer, const int pattern[7][5], int startX, int startY, int pixelSize) {
    // Due loop annidati: uno per le righe (i), uno per le colonne (j)
    for (int i = 0; i < 7; i++) {        // Per ogni riga (7 righe)
        for (int j = 0; j < 5; j++) {    // Per ogni colonna (5 colonne)
            if (pattern[i][j] == 1) {    // Se il pixel deve essere acceso
                // Disegna un pixel alla posizione calcolata
                drawPixel(renderer, 
                         startX + j * pixelSize,  // X = start + colonna * dimensione
                         startY + i * pixelSize,  // Y = start + riga * dimensione
                         pixelSize);
            }
        }
    }
}

// ========================================
// PATTERN DELLE LETTERE (FONT PIXEL-ART)
// ========================================
// Ogni lettera è definita come una griglia 7x7
// 1 = pixel acceso, 0 = pixel spento

// Lettera S
const int LETTER_S[7][5] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,0},
    {0,1,1,1,0},
    {0,0,0,0,1},
    {1,0,0,0,1},
    {0,1,1,1,0}
};

// Lettera T
const int LETTER_T[7][5] = {
    {1,1,1,1,1},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0}
};

// Lettera A
const int LETTER_A[7][5] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1}
};

// Lettera R
const int LETTER_R[7][5] = {
    {1,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,1,1,1,0},
    {1,0,1,0,0},
    {1,0,0,1,0},
    {1,0,0,0,1}
};

// Lettera O
const int LETTER_O[7][5] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {0,1,1,1,0}
};

// Lettera P
const int LETTER_P[7][5] = {
    {1,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,1,1,1,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0}
};

// Lettera I
const int LETTER_I[7][5] = {
    {0,1,1,1,0},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,0,1,0,0},
    {0,1,1,1,0}
};

// Lettera N
const int LETTER_N[7][5] = {
    {1,0,0,0,1},
    {1,1,0,0,1},
    {1,0,1,0,1},
    {1,0,0,1,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1}
};

// Lettera G
const int LETTER_G[7][5] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,0},
    {1,0,1,1,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {0,1,1,1,0}
};

// Lettera Q
const int LETTER_Q[7][5] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,1,0,1},
    {1,0,0,1,0},
    {0,1,1,0,1}
};

// Lettera U
const int LETTER_U[7][5] = {
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {1,0,0,0,1},
    {0,1,1,1,0}
};

// ========================================
// FUNZIONE PER DISEGNARE UNA PAROLA
// ========================================
void drawWord(SDL_Renderer* renderer, const char* word, int x, int y, int pixelSize, int spacing) {
    int currentX = x;  // Posizione X corrente (si sposta per ogni lettera)
    
    // Loop attraverso ogni carattere della parola
    // word[i] prende il carattere alla posizione i
    // '\0' è il carattere di fine stringa (come in C)
    for (int i = 0; word[i] != '\0'; i++) {
        char c = word[i];  // Carattere corrente
        
        // Switch per scegliere quale pattern usare in base alla lettera
        switch(c) {
            case 'S': drawLetter(renderer, LETTER_S, currentX, y, pixelSize); break;
            case 'T': drawLetter(renderer, LETTER_T, currentX, y, pixelSize); break;
            case 'A': drawLetter(renderer, LETTER_A, currentX, y, pixelSize); break;
            case 'R': drawLetter(renderer, LETTER_R, currentX, y, pixelSize); break;
            case 'O': drawLetter(renderer, LETTER_O, currentX, y, pixelSize); break;
            case 'P': drawLetter(renderer, LETTER_P, currentX, y, pixelSize); break;
            case 'I': drawLetter(renderer, LETTER_I, currentX, y, pixelSize); break;
            case 'N': drawLetter(renderer, LETTER_N, currentX, y, pixelSize); break;
            case 'G': drawLetter(renderer, LETTER_G, currentX, y, pixelSize); break;
            case 'Q': drawLetter(renderer, LETTER_Q, currentX, y, pixelSize); break;
            case 'U': drawLetter(renderer, LETTER_U, currentX, y, pixelSize); break;
        }
        
        // Muovi X per la prossima lettera
        // 5 colonne per lettera + spacing tra lettere
        currentX += (5 * pixelSize) + spacing;
    }
}

// ========================================
// FUNZIONE MAIN - DA QUI PARTE TUTTO
// ========================================
int main(int argc, char* argv[]) {
    
    // Inizializza SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("Errore SDL: %s\n", SDL_GetError());
        return -1;
    }
    
    // Crea finestra
    SDL_Window* window = SDL_CreateWindow(
        "VEYA ENGINE - Menu Demo",
        800, 600, 0
    );
    
    if (!window) {
        printf("Errore finestra: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    
    // Crea renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        printf("Errore renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    
    // ========================================
    // VARIABILI DI GIOCO
    // ========================================
    
    // Stato corrente del gioco (inizia nel menu)
    GameState currentState = STATE_MENU;
    
    // Opzioni del menu (array di stringhe)
    const char* menuOptions[] = {
        "START",
        "OPTIONS",
        "QUIT"
    };
    int numOptions = 3;  // Numero di opzioni
    
    // Quale opzione è selezionata (0 = START, 1 = OPTIONS, 2 = QUIT)
    int selectedOption = 0;
    
    // Variabili per il gioco (quando premi START)
    float playerX = 350;
    float playerY = 250;
    
    bool running = true;
    SDL_Event event;
    
    // ========================================
    // GAME LOOP PRINCIPALE
    // ========================================
    while (running) {
        
        // --- GESTIONE EVENTI ---
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            
            // Gestione input in base allo stato
            if (event.type == SDL_EVENT_KEY_DOWN) {
                
                // ESC chiude sempre
                if (event.key.key == SDLK_ESCAPE) {
                    running = false;
                }
                
                // ========================================
                // INPUT NEL MENU
                // ========================================
                if (currentState == STATE_MENU) {
                    
                    // Freccia SU - vai all'opzione precedente
                    if (event.key.key == SDLK_UP) {
                        selectedOption--;
                        // Se vai sotto 0, torna all'ultima opzione (wrap around)
                        if (selectedOption < 0) {
                            selectedOption = numOptions - 1;
                        }
                    }
                    
                    // Freccia GIÙ - vai all'opzione successiva
                    if (event.key.key == SDLK_DOWN) {
                        selectedOption++;
                        // Se vai oltre l'ultima, torna alla prima (wrap around)
                        if (selectedOption >= numOptions) {
                            selectedOption = 0;
                        }
                    }
                    
                    // INVIO - seleziona l'opzione
                    if (event.key.key == SDLK_RETURN) {
                        if (selectedOption == 0) {
                            // START premuto
                            currentState = STATE_PLAYING;
                        } else if (selectedOption == 1) {
                            // OPTIONS premuto (per ora non fa nulla)
                            printf("Options selezionato!\n");
                        } else if (selectedOption == 2) {
                            // QUIT premuto
                            running = false;
                        }
                    }
                }
                
                // ========================================
                // INPUT NEL GIOCO
                // ========================================
                else if (currentState == STATE_PLAYING) {
                    // Movimento del quadrato
                    if (event.key.key == SDLK_UP)    playerY -= 10;
                    if (event.key.key == SDLK_DOWN)  playerY += 10;
                    if (event.key.key == SDLK_LEFT)  playerX -= 10;
                    if (event.key.key == SDLK_RIGHT) playerX += 10;
                    
                    // P = Pausa
                    if (event.key.key == SDLK_P) {
                        currentState = STATE_PAUSED;
                    }
                }
                
                // ========================================
                // INPUT IN PAUSA
                // ========================================
                else if (currentState == STATE_PAUSED) {
                    // P = Riprendi
                    if (event.key.key == SDLK_P) {
                        currentState = STATE_PLAYING;
                    }
                    // M = Torna al menu
                    if (event.key.key == SDLK_M) {
                        currentState = STATE_MENU;
                    }
                }
            }
        }
        
        // ========================================
        // RENDERING
        // ========================================
        
        // --- RENDERING DEL MENU ---
        if (currentState == STATE_MENU) {
            
            // Sfondo scuro
            SDL_SetRenderDrawColor(renderer, 20, 20, 40, 255);
            SDL_RenderClear(renderer);
            
            // Titolo "VEYA ENGINE" in alto
            SDL_SetRenderDrawColor(renderer, 100, 200, 255, 255);  // Azzurro
            // (Non abbiamo tutte le lettere, usiamo quello che abbiamo)
            // Per ora scriviamo solo alcune parole dimostrative
            
            // Disegna le opzioni del menu
            int startY = 200;  // Y iniziale per le opzioni
            int spacing = 80;  // Spazio tra le opzioni
            
            for (int i = 0; i < numOptions; i++) {
                // Se questa opzione è selezionata, usa colore diverso
                if (i == selectedOption) {
                    SDL_SetRenderDrawColor(renderer, 255, 200, 50, 255);  // Giallo/arancione
                } else {
                    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255); // Grigio
                }
                
                // Disegna la parola
                int y = startY + (i * spacing);
                drawWord(renderer, menuOptions[i], 250, y, 4, 2);
            }
            
            // Indicatore freccia (triangolo) accanto all'opzione selezionata
            SDL_SetRenderDrawColor(renderer, 255, 255, 100, 255);
            int arrowY = startY + (selectedOption * spacing) + 12;
            
            // Disegna un triangolino (freccia) a sinistra dell'opzione selezionata
            for (int i = 0; i < 5; i++) {
                drawPixel(renderer, 200, arrowY + i, 4);
                drawPixel(renderer, 204, arrowY + i - 1, 4);
                drawPixel(renderer, 208, arrowY + i - 2, 4);
            }
            
            // Istruzioni in basso
            SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
            // (Non possiamo scrivere tutto, ma l'idea c'è!)
            
        }
        
        // --- RENDERING DEL GIOCO ---
        else if (currentState == STATE_PLAYING) {
            
            // Sfondo blu
            SDL_SetRenderDrawColor(renderer, 30, 60, 120, 255);
            SDL_RenderClear(renderer);
            
            // Quadrato rosso controllabile
            SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
            SDL_FRect rect = {playerX, playerY, 100, 100};
            SDL_RenderFillRect(renderer, &rect);
            
            // Testo "PLAYING" in alto (con le lettere che abbiamo)
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            // drawWord(renderer, "PLAYING", 10, 10, 3, 2);  // Non abbiamo tutte le lettere!
            
        }
        
        // --- RENDERING PAUSA ---
        else if (currentState == STATE_PAUSED) {
            
            // Sfondo scuro
            SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
            SDL_RenderClear(renderer);
            
            // Testo "PAUSA" al centro
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            // drawWord(renderer, "PAUSA", 300, 250, 5, 3);  // Non abbiamo tutte le lettere!
            
            // Per ora scriviamo almeno qualcosa
            drawWord(renderer, "PAUSA", 280, 250, 5, 3);  // P-A-U-S-A (non abbiamo la S in minuscolo)
        }
        
        // Mostra tutto sullo schermo
        SDL_RenderPresent(renderer);
        
        // Delay per ~60 FPS
        SDL_Delay(16);
    }
    
    // ========================================
    // PULIZIA E CHIUSURA
    // ========================================
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
