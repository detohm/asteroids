# Asteroids
This project is a clone of the "Asteroids" game for educational purpose. It provides minimal gameplay. It's built with C++ and SDL2.
# Screenshots
![Introduction Scene](https://github.com/detohm/asteroids/blob/main/docs/assets/1-intro.png?raw=true)
![Gameplay Scene](https://github.com/detohm/asteroids/blob/main/docs/assets/2-gameplay.png?raw=true)
![GameOver Scene](https://github.com/detohm/asteroids/blob/main/docs/assets/3-gameover.png?raw=true)
# Features
This project provides the following features,
- Player can use Up, Left, Right (arrow keys) to navigate the spaceship.
- The asteroids will be spawn randomly.
- Player can press Space to fire the bullet to hit the asteroids.
- If the spaceship hit with any asteroids, you will lose one life point.
- If you run out of the life points, game will be over.
# Technical Details & Project Rubrics
## Overview
This project uses `SDL2` and `SDL2_TTF` as main libraries for interfacing with OS stuffs such as graphic & UI rendering, io-event polling, and timer.

Main components
- **Scene Manager** (`scene_manager.h`, `scene_manager.cpp`) : It contains game state manager, using stack-based with Singleton scene pattern. This is where the main game loop occurs.
- **Scene** (`scene.h`, `scene.cpp`) : This is a base class for all the scene classes. It provides interface to be invoked in game loop like handleInput, update, render. It also provides interface for handling the state lifecycle such as init and cleanup.
- **Renderer** (`renderer.h`, `renderer.cpp`) : This is a wrapper class for SDL Renderer.
- **GameObject** (`game_object.h`, `game_object.cpp`) : All the game object classes such as asteroids, spaceship, and bullets inherit this base class. It provides several base methods for collision detection and screen wrapping for the inherited game objects.
- **Game** (`game.h`, `game.cpp`) : This is the gameplay scene. Most of the game logics are in here such as asteroids spawning, interaction between game objects, collision detection and its consequences, life points and score handling, HUD updating and etc. 
- **Main** (`main.cpp`): Starting point of the execution !!!

## Project Rubrics
Please find the addressed rubric points below,
- **The project demonstrates an understanding of C++ functions and control structures** : In [game.cpp](https://github.com/detohm/asteroids/blob/main/src/game.cpp), there are separated functions like `HandleInputs`,`Update`,`Render` to group the related logics together. This file also contains control usage of `switch-case`,`if-else`,`while`,`for`,`return`.
- **The project reads data from a file and process the data** : In [scene_intro.cpp:L24](https://github.com/detohm/asteroids/blob/main/src/scene_intro.cpp#L24), it uses SDL_TTF library to load the font file.
- **The project accepts user input and processes the input** : In [game.cpp L39](https://github.com/detohm/asteroids/blob/main/src/game.cpp#L39), this HandleInputs function demonstate input handling by detecting the event from SDL Poll Event and executing the expected behaviors.
- **The project uses Object Oriented Programming techniques** : All of the files such `game.h`, `game.cpp`, `game_object.h`, `game_object.cpp` are contructed using OOP approach as Classes and its methods. Please find details in the 'main components' section above.
- **Classes use appropriate access specifiers for class members** : The example is in [renderer.h](https://github.com/detohm/asteroids/blob/main/include/renderer.h). It demonstrates using of 'public' and 'private' class members.
- **Class constructors utilize member initialization lists** : In [scene_manager.cpp L10](https://github.com/detohm/asteroids/blob/main/src/scene_manager.cpp#L10), there is usage of initialization list at the class contructor.
- **Classes follow an appropriate inheritance hierarchy** : In [spaceship.h L9](https://github.com/detohm/asteroids/blob/main/include/spaceship.h#L9), the Spaceship class inherits GameObject class to obtain several base class members like object's position and rotation, object's speed. There are also useful base class methods like collision detection and screen wrapping.
- **Derived class functions override virtual base class functions** : In [scene.h](https://github.com/detohm/asteroids/blob/main/include/scene.h), there are several pure virtual functions such as HandleInputs,Update,Render, and etc. These particular methods are required implementation in derived classes. you can find the example of derived class in [scene_intro.cpp](https://github.com/detohm/asteroids/blob/main/src/scene_intro.cpp), as you can see, all the virtual functions are implemented.
# Project Dependencies
You requires C++ compiler with C++17 standard capability to build this project. This project use make This project also uses `SDL2` and `SD2_TTF` as its dependencies.
## Linux
Use `apt` to install the dependencies with the following commands.
```shell
sudo apt-get update
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-ttf-dev
```
## MacOS
Use `brew` to install the dependencies
```shell
brew update
brew install sdl2
brew install sdl2_ttf
```
## Windows
Please find runtime binaries and installation details below,
- [https://www.libsdl.org/download-2.0.php](https://www.libsdl.org/download-2.0.php)
- [https://www.libsdl.org/projects/SDL_ttf/](https://www.libsdl.org/projects/SDL_ttf/)

# How To Build and Run
Before go through this section, please ensure that `SDL2` and `SDL2_TTF` are successfully installed. Plase find instruction in the [above section](#project-dependencies). 

This project uses `CMake` as a cross-platform build automation tool. For example, in Linux and macOS, you can use the following command to build and run.
```shell
# supposing that you are at the project directory (where the CMakeLists.txt is hosted.)
mkdir build
cd build
cmake ..
make
./Asteroids
```
# References
There are several meterials I went through for building this project.
- **Game Loop** : [Game Programming Pattern](https://gameprogrammingpatterns.com/game-loop.html), [Fix your Timestep](https://gafferongames.com/post/fix_your_timestep/)
- **State Management** : [Managing Game States in C++](http://gamedevgeek.com/tutorials/managing-game-states-in-c/)
- **SDL2 Tutorials** : [Lazy Foo' SDL2 Tutorials](https://lazyfoo.net/tutorials/SDL/)
- **CMAKE** : [SDL2 CMake Module](https://github.com/aminosbh/sdl2-cmake-modules) from Amine B. Hassouna, Kitware, Inc. and Contributors.
# License
[MIT](https://github.com/detohm/asteroids/blob/main/LICENSE), Attaphong Rattanaveerachanon