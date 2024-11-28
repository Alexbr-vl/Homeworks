add_library(FigureLibrary SHARED 
	${CMAKE_CURRENT_SOURCE_DIR}/figure.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/isosceles_triangle.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/parallelogram.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/quadrangle.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/rectangle.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/rhomb.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/right_triangle.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/square.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/triangle.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/equilateral_triangle.cpp
)

set_target_properties(FigureLibrary PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_include_directories(FigureLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})