cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)

project(sortingAlgos VERSION 0.1.0)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)

set(Headers 
    sortingAlgos.hpp
)

set(Sources
    sortingAlgos.cpp
)

add_library(sortingAlgos STATIC ${Sources} ${Headers})

target_link_libraries(
	sortingAlgos
	GTest::gtest_main
)

add_subdirectory(test)
