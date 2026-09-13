cmake_minimum_required(VERSION 3.16)

project(GitLearning LANGUAGES CXX)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_WARNINGS "Enable compiler warnings" ON)

message(STATUS "ENABLE_WARNINGS=${ENABLE_WARNINGS}")

add_library(greeting STATIC
    src/greeting.cpp
)

add_executable(bounds_demo
    src/bounds_demo.cpp
)

add_executable(memory_demo
    src/memory_demo.cpp
)

add_executable(thread_demo
    src/thread_demo.cpp
)

add_executable(gdb_demo
    src/gdb_demo.cpp
)

add_executable(git_learning 
    src/main.cpp
)

add_executable(greeting_demo
    src/greeting_demo.cpp
)


target_include_directories(greeting
    PUBLIC
    include
)

target_link_libraries(git_learning
    PRIVATE
    greeting
)

target_link_libraries(thread_demo
    PRIVATE
    Threads::Threads
)

target_link_libraries(greeting_demo
    PRIVATE
    greeting
)

add_library(project_warnings INTERFACE)

if(ENABLE_WARNINGS)
    target_compile_options(project_warnings
        INTERFACE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

target_link_libraries(greeting
    PRIVATE
    project_warnings
)

target_link_libraries(git_learning
    PRIVATE
    project_warnings
)

target_link_libraries(greeting_demo
    PRIVATE
    project_warnings
)

target_link_libraries(thread_demo
    PRIVATE
    project_warnings
)

target_link_libraries(bounds_demo
    PRIVATE
    project_warnings
)

target_link_libraries(gdb_demo
    PRIVATE
    project_warnings
)

target_link_libraries(memory_demo
    PRIVATE
    project_warnings
)


