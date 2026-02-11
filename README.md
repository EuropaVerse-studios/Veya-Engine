# 🎮 IL TUO PRIMO GAME ENGINE IN C++

Benvenuto! Questo è il tuo primo passo per creare un game engine.

---

## 📋 COSA SERVE

✅ Windows 11 (ce l'hai già!)
✅ Visual Studio 2022 (installato!)
✅ SDL3 (lo scarichi ora)

---

## 🚀 SETUP - PASSO PER PASSO

### STEP 1: Scarica SDL3

1. Vai su: https://github.com/libsdl-org/SDL/releases/latest
2. Cerca il file: **SDL3-x.x.x-VC.zip** (quello con "VC" nel nome)
3. Scaricalo

### STEP 2: Estrai SDL3

1. Estrai il file .zip scaricato
2. Dentro troverai una cartella con dentro altre cartelle: `include`, `lib`, ecc.
3. **COPIA** tutta quella cartella e **INCOLLALA** dentro questa cartella del progetto
4. **RINOMINALA** in `SDL3` (esattamente così, senza numeri di versione)

La struttura finale deve essere:
```
GameEngine/
├── main.cpp           (il tuo programma)
├── compila.bat        (lo script di compilazione)
├── README.md          (questo file)
└── SDL3/              (la cartella di SDL3)
    ├── include/       (file .h)
    └── lib/           (file .lib e .dll)
        └── x64/
```

### STEP 3: Compila ed Esegui!

1. Apri il **Menu Start** di Windows
2. Cerca: **"Developer Command Prompt for VS 2022"**
3. Aprilo (è un terminale speciale con il compilatore configurato)
4. Vai nella cartella del progetto:
   ```
   cd C:\percorso\dove\hai\estratto\GameEngine
   ```
5. Esegui:
   ```
   compila.bat
   ```

**BOOM!** 💥 Dovrebbe compilare e aprirsi una finestra blu con un quadrato rosso!

---

## 🎯 COSA FA IL PROGRAMMA

- Apre una finestra 800x600 pixel
- Sfondo blu scuro
- Quadrato rosso al centro
- Puoi chiuderla con la X o premendo ESC

---

## 🐛 SE QUALCOSA VA STORTO

### Errore: "SDL3.dll non trovata"

**Soluzione:** Copia il file `SDL3.dll` da `SDL3/lib/x64/` nella stessa cartella di `main.exe`

### Errore: "cl non è riconosciuto"

**Soluzione:** Devi usare "Developer Command Prompt for VS 2022", non il CMD normale!

### Errore: "cannot open file SDL3/SDL.h"

**Soluzione:** La cartella SDL3 non è al posto giusto. Controlla la struttura sopra.

---

## 📚 PROSSIMI PASSI

Una volta che vedi la finestra blu funzionare:

1. **Esperimenta!** Cambia i colori nel codice
2. **Muovi il quadrato** (ti spiego come)
3. **Aggiungi input** (tastiera/mouse)
4. **Carica immagini**
5. **Crea un vero gioco!**

---

## 💬 DOMANDE?

Ogni riga di codice in `main.cpp` è commentata e spiegata.

**LEGGILO CON CALMA** e se qualcosa non è chiaro, chiedi pure!

C++ non è difficile se lo capisci passo per passo. 💪

---

**Ora vai, compila e fammi sapere se funziona!** 🚀
