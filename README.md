# Voxel Engine

Fuck it, we ball\
Wanted to make Minecraft, wanted to write C, wanted to use OpenGL, decided C++ was more convenient\
This is very spaghetti\
Likely not the most efficient either\
DEFINITELY not unique\
Totally didn't copy the greedy meshing code from some random research paper I found\
Eventually I will replace the UI draw calls with texture draw calls\
Not today tho

## AI Usage Disclaimer
I did use Copilot for the `CMakeLists.txt` and `main.yml` files (mainly because IDK the first thing about either).\
Copilot didn't touch the rest of my code, I did ask it questions on how to do XYZ, but it never generated code for me.\
***All code is written by me, someone who has never written C++ before and is generally not the best programmer ever, if there are security or memory issues, it is because of my dumbass. Please create an issue. Thanks <3***

## Dependencies
- OpenGL
- SDL3 (both the runtime and the dev kit)
- GLM 1.0.3
- stb_image
- ImGUI
- C++17
- Clang compiler (recommended, but not necessary)

## Compiling from Source
In the project's root folder:
```bash
mkdir build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
cd build
./VoxelEngine
```
