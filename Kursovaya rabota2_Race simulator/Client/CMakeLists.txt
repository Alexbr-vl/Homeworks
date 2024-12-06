# Название исполняемого файла
add_executable(Client main.cpp)

# Указываем зависимости
target_link_libraries(Client PRIVATE RaceLib TransportLib)

# Заголовочные файлы для доступа
target_include_directories(Client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
