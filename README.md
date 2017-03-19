# Deans-Stars
My Stars made with SFML and C++

## Built With
- Languages:
  - C++ (https://en.wikipedia.org/wiki/C%2B%2B)
- Libs:
  - SFML2 (https://www.sfml-dev.org/)
     - Libs:
       - OpenAL (Audio)
       - MESA (Audio)
       - MS WAV Sampling (Audio) - libsndfile
       - GLEW (Graphics)
       - X11 (Linux Window System)
       - JPEG (Image/Sprites/2D Graphics) - libjpeg8
       - Threading (Multi-Threading)
     - Built With:
       - cmake
       - g++ (https://gcc.gnu.org/onlinedocs/gcc-3.3.6/gcc/index.html#Top) 
- Compiler:
  - g++ (https://gcc.gnu.org/onlinedocs/gcc-3.3.6/gcc/index.html#Top) 
- Linux Tools (used in build script):
  - find (http://man7.org/linux/man-pages/man1/find.1.html) 

## Installation
Simply Call:
 -  ./start

## Development
*Note: Always rememeber KISS (**K**eep **I**t **S**imple **S**tupid)*

For **ubuntu linux** flavours simply run the following to set up your development enviroment
 ```
    sudo apt-get install libpthread-stubs0-dev
    sudo apt-get install libgl1-mesa-dev
    sudo apt-get install libx11-dev
    sudo apt-get install libxrandr-dev
    sudo apt-get install libfreetype6-dev
    sudo apt-get install libglew1.5-dev
    sudo apt-get install libjpeg8-dev 
    sudo apt-get install libsndfile1-dev
    sudo apt-get install libopenal-dev
    sudo apt-get install cmake
    sudo apt-get install g++
  ```
**cd** to the project root directory

To **Compile**, call:
- ./build

To **Run**, call:
- ./start

To **Build** then **Run**, call:
- ./build && ./start

Author: https://github.com/DeanVanGreunen (Dean Van Greunen) a.k.a **MRX**
Keybase: https://www.keybase.io/DeanVanGreunen
