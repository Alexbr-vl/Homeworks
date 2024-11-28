add_library(LeaverLibrary SHARED Leaver.cpp)
set_target_properties(LeaverLibrary PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_include_directories(LeaverLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


