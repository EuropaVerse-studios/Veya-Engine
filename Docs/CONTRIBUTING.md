# Contributing to Veya Engine

First off, **thank you** for considering contributing to Veya Engine! 🎉

This project is built by the community, and we welcome contributions from developers of all skill levels.

---

## 🤔 How Can I Contribute?

### 🐛 Reporting Bugs

Found a bug? Help us squash it!

**Before submitting:**
1. Check [existing issues](https://github.com/EuropaVerse-studios/veya-engine/issues) to avoid duplicates
2. Use the latest version of Veya Engine
3. Collect relevant information (OS, compiler, SDL version)

**Submit a bug report:**
- Use the [Bug Report template](https://github.com/EuropaVerse-studios/veya-engine/issues/new?template=bug_report.md)
- Include steps to reproduce
- Add error messages, logs, screenshots
- Describe expected vs actual behavior

### 💡 Suggesting Features

Have an idea? We'd love to hear it!

**Feature requests should:**
- Explain the problem you're solving
- Describe your proposed solution
- Consider alternatives you've thought of
- Explain why this fits Veya Engine's goals (VN + gameplay hybrid)

Use the [Feature Request template](https://github.com/EuropaVerse-studios/veya-engine/issues/new?template=feature_request.md)

### 📝 Improving Documentation

Documentation is crucial! You can help by:
- Fixing typos and grammar
- Adding examples and tutorials
- Clarifying confusing sections
- Translating to other languages

Edit directly on GitHub or submit a PR.

### 💻 Contributing Code

Ready to code? Awesome!

#### Getting Started

1. **Fork the repository**
2. **Clone your fork:**
   ```bash
   git clone https://github.com/EuropaVerse-studios/veya-engine.git
   ```
3. **Create a branch:**
   ```bash
   git checkout -b feature/your-feature-name
   ```

#### Development Setup

See [Building Guide](https://github.com/EuropaVerse-studios/veya-engine/wiki/Building) for detailed setup instructions.

#### Coding Guidelines

**Style:**
- Follow existing code style
- Use meaningful variable names
- Comment complex logic
- Keep functions focused (do one thing well)

**Architecture:**
- Respect module boundaries
- Keep .h files clean (declarations only)
- Use namespaces appropriately
- Avoid circular dependencies

**Example:**
```cpp
// Good
namespace Rendering {
    void drawSprite(SDL_Renderer* renderer, const Sprite& sprite);
}

// Bad
void DrawSpriteOnScreen(SDL_Renderer* r, Sprite s); // No namespace, unclear function
```

#### Commit Messages

Write clear, descriptive commit messages:

```
Add sprite animation system

- Implement frame-based animation
- Add Animation class with play/pause/stop
- Update Sprite to support animations
- Add example in examples/animated-sprite

Closes #42
```

**Format:**
- First line: Brief summary (50 chars max)
- Blank line
- Detailed description (wrap at 72 chars)
- Reference issues/PRs

#### Submitting a Pull Request

1. **Push your branch:**
   ```bash
   git push origin feature/your-feature-name
   ```

2. **Open a Pull Request** on GitHub

3. **Fill out the PR template:**
   - Describe what you changed and why
   - Link related issues
   - Add screenshots/videos if relevant
   - Check all boxes in the checklist

4. **Respond to feedback:**
   - Be open to suggestions
   - Make requested changes
   - Push updates to your branch

5. **Celebrate!** 🎉 Your PR will be reviewed and merged.

---

## 🎯 Good First Issues

New to the project? Look for issues labeled [`good first issue`](https://github.com/EuropaVerse-studios/veya-engine/labels/good%20first%20issue).

These are beginner-friendly tasks that help you get familiar with the codebase.

---

## 📋 Pull Request Checklist

Before submitting, ensure:

- [ ] Code follows project style
- [ ] All tests pass (when we have tests!)
- [ ] Documentation updated (if needed)
- [ ] Commit messages are clear
- [ ] No merge conflicts
- [ ] Added comments for complex code
- [ ] Tested on your platform

---

## 🏗️ Module Ownership

Want to become a maintainer of a specific module? We're looking for dedicated contributors to own:

- **Rendering System**
- **Audio System**
- **VN System (dialogue, characters)**
- **Scripting Engine**
- **Editor Tools**

Interested? Open a [discussion](https://github.com/EuropaVerse-studios/veya-engine/discussions)!

---

## 🤝 Code of Conduct

Be respectful, inclusive, and constructive. We're all here to build something awesome together.

Harassment, discrimination, or toxic behavior will not be tolerated.

See our [Code of Conduct](CODE_OF_CONDUCT.md) for details.

---

## 🆘 Need Help?

Stuck? Questions? We're here to help!

- **Discord:** [Join our community](https://discord.gg/veya-engine)
- **Discussions:** [Ask on GitHub](https://github.com/EuropaVerse-studios/veya-engine/discussions)
- **Wiki:** [Documentation](https://github.com/EuropaVerse-studios/veya-engine/wiki)

---

## 📜 License

By contributing to Veya Engine, you agree that your contributions will be licensed under the MIT License.

---

**Thank you for making Veya Engine better!** ❤️
