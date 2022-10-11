cmake_minimum_required(VERSION 3.20)

project(midterm)

set(CMAKE_CXX_STANDARD 20)

file( GLOB_RECURSE SRC_FILES src/*cpp src/*h)

add_executable(${PROJECT_NAME} ${SRC_FILES} )

target_link_libraries(${PROJECT_NAME})

if(WIN32)
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()