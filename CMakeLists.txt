cmake_minimum_required(VERSION 3.10)
project(gameoflife)

# Force C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Equivalent to (CFLAGS) -g
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Binary app will go to: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "CMakeLists.txt contents:")
execute_process(COMMAND sed "s/^/\t/" CMakeLists.txt
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	RESULT_VARIABLE CMD_ERROR)

# Equivalent to (CFLAGS) -g
set(CMAKE_C_FLAGS "-g")

include_directories(include)
add_executable(gameoflife-text src/controller.cpp src/view-text.cpp)

add_executable(gameoflife-ncurses src/controller.cpp src/view-ncurses.cpp)
target_link_libraries(gameoflife-ncurses ncurses)

add_executable(gameoflife-sfml src/controller.cpp src/view-sfml.cpp)
target_link_libraries(gameoflife-sfml sfml-graphics sfml-window sfml-system)
