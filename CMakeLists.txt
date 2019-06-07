cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME Game)
set(VS_STARTUP_PROJECT ${PROJECT_NAME})
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

set(SFML2_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/SFML2)

message(${SFML2_DIRS})

file(GLOB_RECURSE PROJECT_SRC "src/*.cpp" "src/*.hpp")

add_executable(${PROJECT_NAME} ${PROJECT_SRC} ${SFML2_DIRS}/include)

target_include_directories(${PROJECT_NAME} PRIVATE ${SFML2_DIRS}/include)

target_link_libraries(${PROJECT_NAME} 
		${SFML2_DIRS}/lib/sfml-system-d.lib
        ${SFML2_DIRS}/lib/sfml-graphics-d.lib
        ${SFML2_DIRS}/lib/sfml-window-d.lib
        ${SFML2_DIRS}/lib/sfml-audio-d.lib)

file(COPY ${CMAKE_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_BINARY_DIR})