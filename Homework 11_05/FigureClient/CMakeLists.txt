add_executable(FigureClient main.cpp)

target_link_libraries(FigureClient PRIVATE FigureLibrary)
target_include_directories(FigureClient PRIVATE ${CMAKE_SOURCE_DIR}/LeaverLibrary)