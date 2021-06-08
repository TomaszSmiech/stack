cmake_minimum_required(VERSION 3.10)
project(Stack)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE STACK_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(Stack_src ${STACK_SRC})
target_include_directories(Stack_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(Stack ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(Stack Stack_src)

file(GLOB_RECURSE STACK_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${STACK_TEST_SRC})

#target_link_libraries(Stack_src tests)
target_link_libraries(tests ${CONAN_LIBS})
