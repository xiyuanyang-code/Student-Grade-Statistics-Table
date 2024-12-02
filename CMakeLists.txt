cmake_minimum_required(VERSION 3.30)
project(CODE_for_clion)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
#让链接器静态链接GCC和C++标准库

add_executable(CODE_for_clion main.cpp
        thestudent.h)
