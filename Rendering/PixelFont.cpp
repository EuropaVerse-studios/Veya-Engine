#include "PixelFont.h"

namespace PixelFont {
    const int LETTER_S[7][5] = {
        {0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,0}, {0,1,1,1,0},
        {0,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0}
    };
    
    const int LETTER_T[7][5] = {
        {1,1,1,1,1}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0},
        {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}
    };
    
    const int LETTER_A[7][5] = {
        {0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,1},
        {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}
    };
    
    const int LETTER_R[7][5] = {
        {1,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,0},
        {1,0,1,0,0}, {1,0,0,1,0}, {1,0,0,0,1}
    };
    
    const int LETTER_O[7][5] = {
        {0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1},
        {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0}
    };
    
    const int LETTER_P[7][5] = {
        {1,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,0},
        {1,0,0,0,0}, {1,0,0,0,0}, {1,0,0,0,0}
    };
    
    const int LETTER_I[7][5] = {
        {0,1,1,1,0}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0},
        {0,0,1,0,0}, {0,0,1,0,0}, {0,1,1,1,0}
    };
    
    const int LETTER_N[7][5] = {
        {1,0,0,0,1}, {1,1,0,0,1}, {1,0,1,0,1}, {1,0,0,1,1},
        {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}
    };
    
    const int LETTER_G[7][5] = {
        {0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,0}, {1,0,1,1,1},
        {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0}
    };
    
    const int LETTER_Q[7][5] = {
        {0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1},
        {1,0,1,0,1}, {1,0,0,1,0}, {0,1,1,0,1}
    };
    
    const int LETTER_U[7][5] = {
        {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1},
        {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0}
    };
    
    void drawPixel(SDL_Renderer* renderer, int x, int y, int size) {
        SDL_FRect rect = {(float)x, (float)y, (float)size, (float)size};
        SDL_RenderFillRect(renderer, &rect);
    }
    
    void drawLetter(SDL_Renderer* renderer, const int pattern[7][5], int startX, int startY, int pixelSize) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 5; j++) {
                if (pattern[i][j] == 1) {
                    drawPixel(renderer, startX + j * pixelSize, startY + i * pixelSize, pixelSize);
                }
            }
        }
    }
    
    void drawWord(SDL_Renderer* renderer, const char* word, int x, int y, int pixelSize, int spacing) {
        int currentX = x;
        for (int i = 0; word[i] != '\0'; i++) {
            char c = word[i];
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
            currentX += (5 * pixelSize) + spacing;
        }
    }
}
