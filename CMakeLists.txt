cmake_minimum_required(VERSION 3.0)

enable_testing()

project(project VERSION 0.1.0 LANGUAGES C)

# app

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.c")
add_executable(main ${SOURCES})

# test suite

file(GLOB_RECURSE TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "test/*.c")
add_executable(test_suite ${TEST_SOURCES} ${SOURCES})
target_compile_definitions(test_suite PRIVATE TEST_MODE)

add_test(NAME test_list_add COMMAND test_suite test_list_add)
add_test(NAME test_list_insert COMMAND test_suite test_list_insert)
add_test(NAME test_list_seek_next COMMAND test_suite test_list_seek_next)
