cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME Game)
set(VS_STARTUP_PROJECT ${PROJECT_NAME})
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

set(SFML2_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/SFML2)

file(GLOB_RECURSE PROJECT_SRC "src/*.cpp" "src/*.hpp")

add_executable(${PROJECT_NAME} ${PROJECT_SRC} ${SFML2_DIRS}/include)

target_include_directories(${PROJECT_NAME} PRIVATE ${SFML2_DIRS}/include)

message("build type is " ${CMAKE_BUILD_TYPE})

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	target_link_libraries(${PROJECT_NAME} 
			${SFML2_DIRS}/lib/sfml-system-d.lib
			${SFML2_DIRS}/lib/sfml-graphics-d.lib
			${SFML2_DIRS}/lib/sfml-window-d.lib
			${SFML2_DIRS}/lib/sfml-audio-d.lib)

	file(COPY ${CMAKE_SOURCE_DIR}/resources/debug/ DESTINATION ${CMAKE_BINARY_DIR})
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
	target_link_libraries(${PROJECT_NAME} 
			${SFML2_DIRS}/lib/sfml-system.lib
			${SFML2_DIRS}/lib/sfml-graphics.lib
			${SFML2_DIRS}/lib/sfml-window.lib
			${SFML2_DIRS}/lib/sfml-audio.lib)

	file(COPY ${CMAKE_SOURCE_DIR}/resources/release/ DESTINATION ${CMAKE_BINARY_DIR})
endif()
