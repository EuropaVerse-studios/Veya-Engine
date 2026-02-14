# Veya Engine Architecture

This document explains the high-level architecture and design decisions of Veya Engine.

---

## 🏗️ Design Philosophy

Veya Engine follows these core principles:

1. **Modularity** - Each system is independent and reusable
2. **Simplicity** - Clear APIs, minimal boilerplate
3. **Performance** - Efficient C++, optimized for 2D
4. **Extensibility** - Easy to add new features
5. **VN-First** - Designed for narrative games, not general-purpose

---

## 📦 Module Structure

```
VeyaEngine/
├── Core/           # Engine foundation
├── Rendering/      # Graphics and display
├── UI/             # User interface
├── Audio/          # Sound and music
├── VN/             # Visual novel systems
├── Gameplay/       # Interactive gameplay
├── Scripting/      # VeyaScript language
└── Editor/         # Visual editor (future)
```

### Core Module
**Responsibility:** Engine lifecycle, game loop, state management

**Key Components:**
- `Engine` - Main engine class, coordinates all systems
- `GameState` - State machine (Menu, Playing, Paused, etc.)
- `GameLoop` - Update/render cycle, timing
- `InputManager` - Unified input handling

**Dependencies:** SDL3 (minimal)

---

### Rendering Module
**Responsibility:** All visual output

**Key Components:**
- `Renderer` - Abstraction over SDL_Renderer
- `Sprite` - 2D images with transforms
- `Animation` - Frame-based sprite animation
- `TextRenderer` - Text drawing (pixel fonts, TTF)
- `Camera` - Viewport and scrolling

**Dependencies:** Core, SDL3, SDL_image, SDL_ttf

---

### UI Module
**Responsibility:** Menus, dialogs, HUD

**Key Components:**
- `Menu` - Menu systems with navigation
- `Button` - Interactive buttons
- `TextBox` - Input fields
- `DialogBox` - VN-style dialogue display
- `Panel` - Layout containers

**Dependencies:** Core, Rendering

---

### Audio Module
**Responsibility:** Sound effects and music

**Key Components:**
- `AudioManager` - Global audio control
- `Music` - Background music with crossfade
- `SoundEffect` - Short sound clips
- `VoiceClip` - Character voice acting

**Dependencies:** Core, SDL_mixer

---

### VN Module
**Responsibility:** Visual novel functionality

**Key Components:**
- `DialogSystem` - Display dialogue with typing effect
- `Character` - Character data (sprites, emotions)
- `Choice` - Branching dialogue choices
- `SaveSystem` - Save/load game state
- `ScriptRunner` - Execute VeyaScript

**Dependencies:** Core, Rendering, UI, Audio, Scripting

---

### Gameplay Module
**Responsibility:** Interactive gameplay elements

**Key Components:**
- `Inventory` - Item collection system
- `Minigame` - Framework for mini-games
- `PointAndClick` - Investigation scenes
- `Puzzle` - Puzzle interfaces

**Dependencies:** Core, Rendering, UI

---

### Scripting Module
**Responsibility:** VeyaScript language

**Key Components:**
- `Parser` - Convert script text to AST
- `Interpreter` - Execute script commands
- `ScriptContext` - Runtime variables/state

**Dependencies:** Core, VN

---

### Editor Module (Planned)
**Responsibility:** Visual development tools

**Key Components:**
- `SceneEditor` - Visual scene builder
- `DialogEditor` - Node-based dialogue editor
- `AssetManager` - Import and organize assets

**Dependencies:** All modules, ImGui

---

## 🔄 Data Flow

### Typical Game Loop:
```
1. InputManager polls events
2. GameState determines active systems
3. Active systems update (VN, Gameplay, etc.)
4. Systems queue render commands
5. Renderer draws everything
6. AudioManager plays sounds
7. Repeat
```

### Example: Showing Dialogue
```
VeyaScript → Parser → DialogSystem → TextRenderer → Screen
              ↓                ↓
         Variables        Character sprites
```

---

## 🎨 Design Patterns Used

### State Pattern
- `GameState` enum + state-specific logic
- Clean separation of menu/gameplay/pause

### Component Pattern
- Future: GameObject + Components (Transform, Sprite, etc.)

### Observer Pattern
- Event system for loose coupling
- Example: `OnDialogueComplete` event

### Factory Pattern
- Asset loading (create Sprite from file)

### Singleton (sparingly!)
- AudioManager, InputManager
- Only for truly global systems

---

## 🔌 External Dependencies

### Required:
- **SDL3** - Window, rendering, input, events
- **SDL_image** - PNG/JPG loading
- **SDL_ttf** - Font rendering
- **SDL_mixer** - Audio playback

### Optional:
- **stb_image** - Alternative image loading
- **ImGui** - Editor UI (future)

---

## 📏 Coding Standards

### File Organization:
- `.h` files: Declarations, interfaces, documentation
- `.cpp` files: Implementations only
- One class per file pair

### Naming Conventions:
- `PascalCase` for classes: `DialogSystem`
- `camelCase` for functions: `showDialogue()`
- `snake_case` for variables: `player_name`
- `SCREAMING_SNAKE_CASE` for constants: `MAX_CHOICES`

### Header Guards:
```cpp
#ifndef MODULENAME_H
#define MODULENAME_H
// ...
#endif
```

### Namespaces:
```cpp
namespace VeyaEngine {
    namespace Rendering {
        class Sprite { /* ... */ };
    }
}
```

---

## 🚀 Performance Considerations

### Optimizations:
- Object pooling for frequently created objects
- Spatial partitioning for collision detection
- Texture atlases for sprite rendering
- Audio streaming for large music files

### Profiling:
- Use built-in profiler (future)
- Measure frame time, render calls, allocations

---

## 🔮 Future Architecture

### Planned Improvements:
1. **ECS (Entity Component System)** - For gameplay objects
2. **Multi-threading** - Background asset loading
3. **Scripting Hot-reload** - Edit scripts while running
4. **Plugin System** - Community extensions

---

## 📚 Further Reading

- [Contributing Guide](CONTRIBUTING.md)
- [API Reference](https://github.com/EuropaVerse-studios/veya-engine/wiki/API-Reference)
- [VeyaScript Specification](https://github.com/EuropaVerse-studios/veya-engine/wiki/VeyaScript)

---

Questions about the architecture? [Open a discussion](https://github.com/EuropaVerse-studios/veya-engine/discussions)!
