cmake_minimum_required(VERSION 3.0.0)
project(sortingAlgosTests VERSION 0.1.0)

set(Sources
    sortingAlgosTests.cpp
)

add_executable(${PROJECT_NAME} ${Sources})

target_link_libraries(${PROJECT_NAME} PUBLIC
    gtest_main
    sortingAlgos
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)