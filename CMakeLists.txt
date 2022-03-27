cmake_minimum_required(VERSION 3.2)

project(aisd2_1)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/googletest" "googletest")

add_executable(project cli/source.cpp headers/node.h headers/set.h)
add_executable(test test/test.cpp)

target_include_directories(test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/cli" "${CMAKE_CURRENT_SOURCE_DIR}/headers")

target_link_libraries(test PRIVATE gtest gtest_main)

if (MSVC)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	target_compile_options(project PRIVATE /W4)
	target_compile_options(test PRIVATE /W4)
else()
	target_compile_options(project PRIVATE -Wall -Wextra -pedantic -Werror)
	target_compile_options(test PRIVATE -Wall -Wextra -pedantic -Werror)
endif()