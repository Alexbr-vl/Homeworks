cmake_minimum_required(VERSION 3.10)
project(TestProject)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Основной файл с реализацией списка и тестов
add_executable(ListTests Tests.cpp "my_list.cpp" "my_list.h")

# Подключение Catch2
add_subdirectory(catch2)
target_link_libraries(ListTests PRIVATE Catch2::Catch2WithMain)
