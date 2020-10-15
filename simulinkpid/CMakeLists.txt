cmake_minimum_required(VERSION 3.16)
project(simulinkpid)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(simulinkpid
        main.cpp

        pidmodel.cpp
        pidmodel.h
        pidmodel_private.h
        pidmodel_types.h
        rtwtypes.h)
