cmake_minimum_required(VERSION 3.16)
project(simulinkwave)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(simulinkwave
        main.cpp
        rtwtypes.h
        rtw_continuous.h
        rtw_solver.h
        wave.cpp
        wave.h
        wave_private.h
        wave_types.h)
