cmake_minimum_required(VERSION 3.10)
#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_MESSAGE_LOG_LEVEL VERBOSE)
include(cmake_cours.cmake)  
project(game)
file(GLOB ALL_FILES
	*.cpp
	*.hpp
    piece/*.cpp
    piece/*.hpp
    chessBoard/*.cpp
    chessBoard/*.hpp
    button/*.cpp
    button/*.hpp
    constantes/*.hpp
    check/*.hpp
    check/*.cpp
)

configurer_options_compilation_globales()  # Doit être avant le "add_executable".
configurer_Qt_auto_tout()                  # Doit être avant le "add_executable".
add_executable(${PROJECT_NAME} ${ALL_FILES})

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)  # Mettre ici ce qui est requis de Qt (et mettre Qt5 ou Qt6 selon la version que vous avez).
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)  # Doit être après le "add_executable" et lui passer le même nom.  Mettre encore ici ce qui est requis de Qt.


target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE "include")


