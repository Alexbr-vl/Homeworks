cmake_minimum_required(VERSION 3.10) 
project(MyVectorExample)

set(CMAKE_CXX_STANDARD 17) 

# Добавляем исполняемый файл
add_executable(MyVectorExample main.cpp patern.h )