cmake_minimum_required(VERSION 3.24)

project(final_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DGROUND_WINDOWS)
elseif(APPLE)
	add_definitions(-DGROUND_MAC)
else()
	add_definitions(-DGROUND_LINUX)
endif()

add_definitions(-DGROUND_DEBUG)
add_definitions(-DGROUND_OPENGL)

add_subdirectory(Winter)
add_subdirectory(Ground)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)

set(VS_STARTUP_PROJECT Winter)

file(COPY Winter/Assets DESTINATION ${PROJECT_BINARY_DIR}/Winter)
file(COPY Winter/Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Winter/Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)