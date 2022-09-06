cmake_minimum_required(VERSION 3.20)

project(hw1)

include(FetchContent)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG        v1.x
)

FetchContent_GetProperties(spdlog)
if (NOT spdlog_POPULATED)
    FetchContent_Populate(spdlog)
    add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR})
endif()


set(CMAKE_CXX_STANDARD 20)

file( GLOB_RECURSE SRC_FILES src/*cpp src/*h)

add_executable(${PROJECT_NAME} ${SRC_FILES} )

target_link_libraries(${PROJECT_NAME} spdlog::spdlog)

if(WIN32)
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()