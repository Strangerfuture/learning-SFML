# Learning SFML

A hands-on C++ project for learning **SFML (Simple and Fast Multimedia Library)** through graphics experiments, window management, shape movement, and a basic Flappy Bird implementation.

## Projects

### 1. Basic SFML Window
- Create and manage an SFML window.
- Explore the basic structure of an SFML application.
- Experiment with rendering graphical objects.

### 2. Moving Circles
- Render circles and move them around the window.
- Learn the fundamentals of shape positioning and movement.

### 3. Flappy Bird
- A basic, experimental implementation of Flappy Bird.
- Explore the fundamentals of game loops, input handling, movement, and real-time rendering.

## Technologies

- **C++**
- **SFML**
- **Make**
- **Linux**

## Repository Structure

```text
learning-SFML/
├── flappy.cpp
├── flappybird.cpp
├── sfml.cpp
├── Makefile
├── compile.txt
├── NotesDarling.otf
└── README.md
```


## Getting Started

### Prerequisites

- A C++ compiler, such as `g++`
- SFML development libraries
- GNU Make

On Arch Linux, install the tools with:

```bash
sudo pacman -S gcc make sfml
```

### Clone the Repository

```bash
git clone https://github.com/Strangerfuture/learning-SFML.git
cd learning-SFML
```

### Compile and Run

Check `compile.txt` or the `Makefile` for the project's specific compilation commands.

A typical SFML 2.x compilation command is:

```bash
g++ file_name.cpp -o executable_name -lsfml-graphics -lsfml-window -lsfml-system
./executable_name
```


## Purpose

This repository documents my journey learning SFML and C++ game development by experimenting with graphics, movement, and a simple Flappy Bird-style game.

The focus is on learning by building, experimenting, and improving step by step.

## Author

**Strangerfuture**

- GitHub: [@Strangerfuture](https://github.com/Strangerfuture)
- Repository: [learning-SFML](https://github.com/Strangerfuture/learning-SFML)
