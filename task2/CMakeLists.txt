cmake_minimum_required(VERSION 3.20)
project(ACS_task_2)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        # Headers
        complex.h
        container.h
        fraction.h
        number.h
        polar.h
        # Sources
        complex.cpp
        container.cpp
        fraction.cpp
        number.cpp
        polar.cpp
        main.cpp
        )

add_executable(ACS_task_2 ${SOURCE_FILES})
