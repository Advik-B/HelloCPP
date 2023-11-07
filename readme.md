The compiler being used is Cmake with MSVC

## How to build

### Prerequisites
- Cmake
- Ninja
- A C++ compiler (MSVC or Clang)

1. Clone the repository
2. Create a build directory and cd into it
```
mkdir build
cd build
```
3. Get the path to ninja
4. Run cmake in the build directory with the following command:
```
cmake \
   -DCMAKE_BUILD_TYPE=Release \
   -DCMAKE_MAKE_PROGRAM ninja \
    -G Ninja \
    -DCMAKE_PREFIX_PATH ../SDL2 \
    -S .. \
    -B .
```

5. Run ninja in the build directory with the following command:
```
ninja
```

6. Copy the required *.dll or *.so files to the build directory

> Windows

```
cp ../SDL2/lib/x64/*.dll .
```

> Other

```
cp ../SDL2/lib/x64/*.so .
```

7. Run the executable
```
Hello_SDL2.exe
```