add_executable(LeaverClient main.cpp)

target_link_libraries(LeaverClient PRIVATE LeaverLibrary)

target_include_directories(LeaverClient PRIVATE ${CMAKE_SOURCE_DIR}/LeaverLibrary)
