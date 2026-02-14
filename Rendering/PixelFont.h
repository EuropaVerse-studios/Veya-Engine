// ========================================
// PIXELFONT.H - HEADER
// Dichiara COSA esiste nel modulo PixelFont
// ========================================

#ifndef PIXELFONT_H
#define PIXELFONT_H

#include <SDL3/SDL.h>

namespace PixelFont {
    
    // Dichiarazione dei pattern
    extern const int LETTER_S[7][5];
    extern const int LETTER_T[7][5];
    extern const int LETTER_A[7][5];
    extern const int LETTER_R[7][5];
    extern const int LETTER_O[7][5];
    extern const int LETTER_P[7][5];
    extern const int LETTER_I[7][5];
    extern const int LETTER_N[7][5];
    extern const int LETTER_G[7][5];
    extern const int LETTER_Q[7][5];
    extern const int LETTER_U[7][5];
    
    // Dichiarazione funzioni
    void drawPixel(SDL_Renderer* renderer, int x, int y, int size);
    void drawLetter(SDL_Renderer* renderer, const int pattern[7][5], 
                    int startX, int startY, int pixelSize);
    void drawWord(SDL_Renderer* renderer, const char* word, 
                  int x, int y, int pixelSize, int spacing);
}

#endif