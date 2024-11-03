
#Auto Genrated CMake file by newton CLI
#Copyright 2023 Vishal Ahirwar. #replace with your copyright notice.
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
project(SignalSlot)
set(SOURCE ./src/main.cc)#add your additional source file here!
add_executable(${PROJECT_NAME} ${SOURCE}
    slot.hxx slot.cxx)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
