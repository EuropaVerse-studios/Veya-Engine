# 🎮 Veya Engine

**A specialized game engine for Visual Novels with interactive gameplay elements**

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![C++](https://img.shields.io/badge/C++-17-00599C.svg?logo=c%2B%2B)](https://isocpp.org/)
[![SDL3](https://img.shields.io/badge/SDL-3.x-red.svg)](https://www.libsdl.org/)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey.svg)](https://github.com/EuropaVerse-studios/veya-engine)

---

## 📖 What is Veya Engine?

Veya Engine is a **lightweight, modular game engine** designed specifically for creating **Visual Novels with interactive gameplay**. Unlike traditional VN engines that focus purely on dialogue and choices, Veya Engine bridges the gap between narrative storytelling and gameplay mechanics.

Think of games like:
- **Ace Attorney** (investigation + courtroom gameplay)
- **Danganronpa** (VN + mini-games + trials)
- **VA-11 Hall-A** (dialogue + bartending mechanics)

Veya Engine makes creating these hybrid experiences **simple and accessible**.

---

## 🎯 Why Veya Engine?

### The Problem
- **Ren'Py**: Great for pure VN, but adding custom gameplay is painful
- **Visual Novel Maker**: Limited, closed-source, expensive
- **Godot/Unity**: Overkill for VN, steep learning curve

### The Solution
Veya Engine provides:
- ✅ **VN-first design** - Dialogue, choices, characters built-in
- ✅ **Gameplay modules** - Easy integration of mini-games, puzzles, exploration
- ✅ **Simple scripting** - Custom language designed for narrative
- ✅ **Visual editor** - No coding required for basic VNs
- ✅ **Cross-platform** - Windows, Linux, Web (planned)
- ✅ **Open source** - Free, transparent, community-driven

---

## ⚡ Features

### Current (v0.1.0-alpha)
- [x] Modular architecture (Core, Rendering, UI systems)
- [x] Pixel-art text rendering
- [x] State management (Menu, Game, Pause)
- [x] Input handling
- [x] Professional build system

### In Development
- [ ] SDL_ttf font rendering
- [ ] Sprite system with animations
- [ ] Dialog system with choices
- [ ] Save/Load system
- [ ] Audio manager (music + SFX)

### Planned (v1.0)
- [ ] Visual scripting editor
- [ ] VeyaScript language parser
- [ ] Scene management
- [ ] Mini-game framework
- [ ] Asset pipeline

See our [Roadmap](https://github.com/EuropaVerse-studios/veya-engine/wiki/Roadmap) for detailed plans.

---

## 🏗️ Architecture

Veya Engine is built with a **clean, modular architecture**:

```
VeyaEngine/
├── Core/           # Engine core, game loop, state management
├── Rendering/      # Graphics, sprites, text, effects
├── UI/             # Menus, dialog boxes, HUD
├── Audio/          # Music, sound effects, voice
├── VN/             # Visual novel systems (dialogue, choices, characters)
├── Gameplay/       # Mini-games, inventory, point-and-click
└── Scripting/      # VeyaScript parser and runtime
```

Each module is **independent and reusable**. Want just the dialogue system? Use it standalone. Need the full engine? Everything works together seamlessly.

---

## 🚀 Quick Start

### Prerequisites
- **C++ Compiler** (MSVC, GCC, or Clang)
- **SDL3** library
- **CMake** 3.15+ (recommended) or Visual Studio

### Build from Source

#### Windows (Visual Studio)
```bash
# Clone the repository
git clone https://github.com/EuropaVerse-studios/veya-engine.git
cd veya-engine

# Download SDL3
# Extract to SDL3/ folder

# Open Developer Command Prompt x64
cd VeyaEngine
compila.bat
```

#### Linux
```bash
# Install dependencies
sudo apt install libsdl3-dev cmake g++

# Build
mkdir build && cd build
cmake ..
make

# Run
./VeyaEngine
```

See [Building Guide](https://github.com/EuropaVerse-studios/veya-engine/wiki/Building) for detailed instructions.

---

## 📚 Documentation

- **[Wiki](https://github.com/EuropaVerse-studios/veya-engine/wiki)** - Complete documentation
- **[Getting Started](https://github.com/EuropaVerse-studios/veya-engine/wiki/Getting-Started)** - Your first project
- **[API Reference](https://github.com/EuropaVerse-studios/veya-engine/wiki/API-Reference)** - Module documentation
- **[Tutorials](https://github.com/EuropaVerse-studios/veya-engine/wiki/Tutorials)** - Step-by-step guides
- **[Examples](examples/)** - Sample projects

---

## 🎓 Learning Resources

New to C++ or game development? We've got you covered:

- **[C++ Basics for Veya](https://github.com/EuropaVerse-studios/veya-engine/wiki/CPP-Basics)** - Learn C++ while building
- **[Architecture Guide](https://github.com/EuropaVerse-studios/veya-engine/wiki/Architecture)** - Understanding the engine
- **[Creating Your First VN](https://github.com/EuropaVerse-studios/veya-engine/wiki/First-VN)** - Tutorial series

---

## 🤝 Contributing

We welcome contributions! Veya Engine is built by the community, for the community.

### Ways to Contribute
- 🐛 **Report bugs** - Open an [issue](https://github.com/EuropaVerse-studios/veya-engine/issues)
- 💡 **Suggest features** - Share your ideas!
- 📝 **Improve docs** - Help others learn
- 💻 **Submit code** - Check [good first issues](https://github.com/EuropaVerse-studios/veya-engine/labels/good%20first%20issue)

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

---

## 📜 License

Veya Engine is released under the **MIT License**. See [LICENSE](LICENSE) for details.

**TL;DR:** You can use Veya Engine for anything (personal, commercial, closed-source) with no restrictions. Just include the license file and mention the engine in the credits.

---

## 💖 Acknowledgments

Built with:
- **[SDL3](https://www.libsdl.org/)** - Cross-platform multimedia
- **[stb_image](https://github.com/nothings/stb)** - Image loading
- **[SDL_ttf](https://github.com/libsdl-org/SDL_ttf)** - Font rendering (planned)

Inspired by:
- **Ren'Py** - The gold standard of VN engines
- **Godot** - Modular architecture and open-source philosophy

---

## 🌟 Project Status

**Current Version:** `v0.1.0-alpha` (Early Development)

Veya Engine is in **active development**. The core architecture is stable, but APIs may change. We're working towards a v1.0 release with full VN capabilities.

⭐ **Star this repo** to follow development!

---

## 📬 Contact & Community

- **Discord:** [Join our community](https://discord.gg/veya-engine) (coming soon)
- **Bluesky:** [@VeyaEngine](https://bluesky.com/veyaengine) (coming soon)
- **Email:** europaverse.studios@gmail.com

---

## 🎮 Made with Veya Engine

Have you created something with Veya Engine? [Submit it here](https://github.com/EuropaVerse-studios/veya-engine/wiki/Showcase)!

---

<div align="center">

**[⬆ Back to Top](#-veya-engine)**

Made with ❤️ by developers, for developers

</div>
