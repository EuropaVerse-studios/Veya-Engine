# 🎮 VEYA ENGINE - MENU PIXEL-ART

## 🎯 COSA HAI IMPARATO IN QUESTO PROGETTO

### 1. **ENUM (Enumerazioni)**
```cpp
enum GameState {
    STATE_MENU,
    STATE_PLAYING,
    STATE_PAUSED
};
```
Un enum è un tipo che può avere solo certi valori predefiniti.
Serve per tenere traccia dello "stato" del programma.

**In GDScript:** È come avere costanti che rappresentano stati diversi.

---

### 2. **FUNZIONI**
```cpp
void drawPixel(SDL_Renderer* renderer, int x, int y, int size) {
    // Codice della funzione
}
```

Le funzioni sono pezzi di codice riutilizzabili.
- `void` = non restituisce nulla
- I parametri sono dentro le parentesi
- Chiami la funzione con: `drawPixel(renderer, 100, 200, 5);`

**In GDScript:** È come `func draw_pixel(x, y, size):`

---

### 3. **ARRAY MULTIDIMENSIONALI**
```cpp
const int LETTER_S[7][5] = {
    {0,1,1,1,0},
    {1,0,0,0,1},
    ...
};
```

Un array 2D (matrice) - come una griglia!
- `[7][5]` = 7 righe, 5 colonne
- Accedi con: `LETTER_S[riga][colonna]`

**In GDScript:** È come array annidati: `[[0,1,1], [1,0,0]]`

---

### 4. **LOOP ANNIDATI**
```cpp
for (int i = 0; i < 7; i++) {        // Loop esterno (righe)
    for (int j = 0; j < 5; j++) {    // Loop interno (colonne)
        // Codice eseguito 7*5 = 35 volte!
    }
}
```

Loop dentro loop - per iterare su griglie!

---

### 5. **SWITCH STATEMENT**
```cpp
switch(carattere) {
    case 'S': drawLetter(LETTER_S, ...); break;
    case 'T': drawLetter(LETTER_T, ...); break;
    default: break;
}
```

Come una serie di `if-else`, ma più pulito per molti casi.

**In GDScript:** È come `match carattere:`

---

### 6. **STATE MACHINE (Macchina a Stati)**
```cpp
if (currentState == STATE_MENU) {
    // Logica del menu
} else if (currentState == STATE_PLAYING) {
    // Logica del gioco
}
```

Comportamento diverso in base allo stato!

**Fondamentale per game engine!** Ogni schermata è uno stato.

---

## 🎮 COME FUNZIONA IL MENU

### Navigazione:
- **↑/↓** = Naviga tra le opzioni
- **INVIO** = Seleziona
- **ESC** = Chiudi

### Opzioni:
1. **START** → Vai al gioco (quadrato rosso controllabile)
2. **OPTIONS** → (Per ora stampa solo un messaggio)
3. **QUIT** → Chiudi il programma

### Nel Gioco:
- **Frecce** = Muovi il quadrato
- **P** = Pausa
- **ESC** = Chiudi

### In Pausa:
- **P** = Riprendi
- **M** = Torna al menu
- **ESC** = Chiudi

---

## 📝 COMPILA ED ESEGUI

1. **Copia SDL3** nella cartella (come hai fatto prima)
2. **Compila:**
   ```
   compila.bat
   ```
3. **Esegui:**
   ```
   main.exe
   ```

---

## 🎨 SPERIMENTA!

### Sfida 1: Aggiungi una lettera
Crea il pattern per una nuova lettera (es: 'E', 'L', 'M')
```cpp
const int LETTER_E[7][5] = {
    {1,1,1,1,1},
    {1,0,0,0,0},
    {1,1,1,1,0},
    {1,0,0,0,0},
    {1,1,1,1,1},
    {0,0,0,0,0},
    {0,0,0,0,0}
};
```

Poi aggiungi il case nello switch:
```cpp
case 'E': drawLetter(renderer, LETTER_E, currentX, y, pixelSize); break;
```

### Sfida 2: Cambia i colori
Cambia i colori del menu, del testo selezionato, ecc.

### Sfida 3: Aggiungi una quarta opzione
Aggiungi "CREDITS" nel menu!

---

## 🧠 CONCETTI CHIAVE PER ENGINE

Questo progetto ti ha insegnato:

✅ **State Management** - Come gestire schermate diverse
✅ **Input Handling** - Come reagire agli input in base allo stato
✅ **Rendering Procedurale** - Come disegnare senza immagini
✅ **Menu System** - Base di qualsiasi UI di gioco
✅ **Code Organization** - Come strutturare codice complesso

**Questi sono i FONDAMENTI di un game engine!** 🚀

---

## 🔥 PROSSIMI PASSI

Ora che hai un menu funzionante:

1. **Pong** → Collision detection + AI
2. **Text Rendering avanzato** → Font completo
3. **Dialog System** → Base per le Visual Novel!

**Sei sulla strada giusta!** 💪
