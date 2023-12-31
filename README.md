# Toy C Parser
A parser of C written with C.

This is an experimental project.

## Build
Only Linux is supported.  
WSL is available for Windows.

**Tools**
- CMake
- Clang

```sh
cmake -B build -D CMAKE_TOOLCHAIN_FILE=./cmake/x86_64-linux-clang.cmake
cmake --build build
```

### Use Ninja instead of Make
```sh
cmake -B build -G Ninja -D CMAKE_TOOLCHAIN_FILE=./cmake/x86_64-linux-clang.cmake
cmake --build build
```

### Build a Windows binary
Clangの代わりにllvm-mingwを導入するとLinux上でWindowsバイナリをビルドできます。
```sh
cmake -B build -D CMAKE_TOOLCHAIN_FILE=./cmake/x86_64-windows-mingw.cmake
cmake --build build
```

## License
MIT License
