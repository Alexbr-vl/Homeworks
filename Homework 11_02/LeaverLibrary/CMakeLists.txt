add_library(LeaverLibrary SHARED Leaver.cpp Leaver.h)

target_include_directories(LeaverLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(LeaverLibrary PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
