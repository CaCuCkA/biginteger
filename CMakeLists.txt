cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME BigInteger)
set(LIB_NAME, bigint)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME} LANGUAGES CXX)

add_subdirectory(library)
add_subdirectory(tests)