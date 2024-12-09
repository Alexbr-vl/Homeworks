add_library(TransportLib SHARED 
	${CMAKE_CURRENT_SOURCE_DIR}/Transport.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Ground_transport.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Camel.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Fast_camel.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Centaur.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/All_terrain_boots.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Air_transport.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Broomstick.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Eagle.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Magic_carpet.cpp
)

set_target_properties(TransportLib PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_include_directories(TransportLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})







