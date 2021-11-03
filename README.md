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

# How To Build
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