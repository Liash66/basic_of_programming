cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Main)		 
project("${PROJECT_NAME}")	

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_definitions(-DSFML_STATIC)

include_directories("SFML/include/")
include_directories("include/")
link_directories("SFML/lib/")	

add_executable("${PROJECT_NAME}" Main.cpp Planet.h Game.h Game.cpp)


target_link_libraries("${PROJECT_NAME}" sfml-graphics-s-d
						  sfml-window-s-d
						  sfml-system-s-d
						  sfml-audio-s-d)

target_link_libraries("${PROJECT_NAME}" opengl32 freetype gdi32 openal32 flac winmm vorbisenc vorbisfile vorbis ogg)