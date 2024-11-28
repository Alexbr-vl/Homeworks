cmake_minimum_required(VERSION 3.22.0)
project(Homework_06_03 CXX)

# Источники
set(SOURCES
    main.cpp
    equilateral_triangle.cpp
    error_creating_figure.cpp
    figure.cpp
    isosceles_triangle.cpp
    parallelogram.cpp
    quadrangle.cpp
    rectangle.cpp
    rhomb.cpp
    right_triangle.cpp
    square.cpp
    triangle.cpp
)

# Заголовочные
set(HEADERS
    equilateral_triangle.h
    error_creating_figure.h
    figure.h
    isosceles_triangle.h
    parallelogram.h
    quadrangle.h
    rectangle.h
    rhomb.h
    right_triangle.h
    square.h
    triangle.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
