cmake_minimum_required(VERSION 3.16)
project(simulinkmotor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(simulinkmotor

        main.cpp
        motor.cpp
        motor.h
        motor_private.h
        motor_types.h
        rtw_continuous.h
        rtw_solver.h
        rtwtypes.h)
