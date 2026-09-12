cmake_minimum_required(VERSION 3.16)

project(GitLearning LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(greeting STATIC
    src/greeting.cpp
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


target_link_libraries(greeting_demo
    PRIVATE
    greeting
)
