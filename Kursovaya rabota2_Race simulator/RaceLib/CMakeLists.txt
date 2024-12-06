add_library(RaceLib SHARED 
	${CMAKE_CURRENT_SOURCE_DIR}/Race.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Ground_race.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Air_race.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Mix_race.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Interface.cpp
)

set_target_properties(RaceLib PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_include_directories(RaceLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(RaceLib PRIVATE TransportLib)




