cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME Game)
set(VS_STARTUP_PROJECT ${PROJECT_NAME})
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

#add_executable(${PROJECT_NAME} main.cpp)

#include(FindPkgConfig)
#find_package(SFML2 REQUIRED)

#include_directories(${SFML2_INCLUDE_DIR})

set(SFML2_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/SFML2)

message(${SFML2_DIRS})

add_executable(${PROJECT_NAME} main.cpp ${SFML2_DIRS}/include)

# it doesn't work
set_property (DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ALL_BUILD)

target_include_directories(${PROJECT_NAME} PRIVATE ${SFML2_DIRS}/include)


target_link_libraries(${PROJECT_NAME} 
		${SFML2_DIRS}/lib/sfml-system.lib
        ${SFML2_DIRS}/lib/sfml-graphics.lib
        ${SFML2_DIRS}/lib/sfml-window.lib
        ${SFML2_DIRS}/lib/sfml-audio.lib)

set_target_properties( ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out )


