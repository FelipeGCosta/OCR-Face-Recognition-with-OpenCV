cmake_minimum_required(VERSION 2.8)
project( Trab2_opencv )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( include )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set( SOURCES
src/Usuario.cpp
src/Reserva.cpp
src/GerenteBD.cpp
src/GerenteLogin.cpp
src/SistemaLinf.cpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
message(${EXECUTABLE_OUTPUT_PATH})
add_executable( Trab2_opencv src/Main.cpp ${SOURCES} )
target_link_libraries( Trab2_opencv ${OpenCV_LIBS} )


