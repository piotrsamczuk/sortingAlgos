cmake_minimum_required(VERSION 3.0.0)
project(sortingAlgos VERSION 0.1.0)

include(CTest)
enable_testing()
add_subdirectory(googletest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(Headers 
    sortingAlgos.hpp
)

set(Sources
    sortingAlgos.cpp
)

add_library(sortingAlgos STATIC ${Sources} ${Headers})
add_subdirectory(test)