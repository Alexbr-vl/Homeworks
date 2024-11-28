add_library(GreeterLib STATIC Greeter.cpp Greeter.h)
target_include_directories(GreeterLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})