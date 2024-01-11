cmake_minimum_required(VERSION 3.25)
project(VSCODEC__)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(VSCODEC__
        main.cpp
        meniu.cpp
        meniu.h
        reprezentanta.cpp
        reprezentanta.h
        vehicul.cpp
        vehicul.h
        moto.cpp
        moto.h
        masina.h
        masina.cpp
        masina.cpp
        camion.h
        camion.cpp
        exceptii.h
        templates.h
        exceptii.cpp)
