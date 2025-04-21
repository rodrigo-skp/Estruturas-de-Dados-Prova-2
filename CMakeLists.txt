cmake_minimum_required(VERSION 3.26)
project(ed)

enable_testing()

include(GoogleTest)
include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(pilha_test test/pilha.cpp)
target_link_libraries(pilha_test gtest gtest_main)
gtest_add_tests(TARGET pilha_test)


add_executable(fila_test test/fila.cpp)
target_link_libraries(fila_test gtest gtest_main)
gtest_add_tests(TARGET fila_test)

add_executable(posfixa_test test/posfixa.cpp src/posfixa.cpp)
target_link_libraries(posfixa_test gtest gtest_main)
gtest_add_tests(TARGET posfixa_test)