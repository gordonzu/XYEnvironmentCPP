project(XYEnvironment)
cmake_minimum_required(VERSION 2.6)

include_directories("$ENV{GMOCK_HOME}/include" 
                    "$ENV{GMOCK_HOME}/gtest/include"
                    "$ENV{BOOST_INCLUDE}" 
                    "$ENV{HOME}/src/cpp/XYEnvironment/src/Environment") 
link_directories   ("$ENV{GMOCK_HOME}/mybuild" 
                    "$ENV{GMOCK_HOME}/gtest/mybuild"
                    "$ENV{BOOST_LIB}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -Wall -O0 -fmax-errors=1")

set(sources
    tests/Environment/XYEnvironmentTest.cpp
    main.cpp
  )

add_executable(xyenv ${sources})
target_link_libraries(xyenv gmock)
target_link_libraries(xyenv gtest)
target_link_libraries(xyenv boost_container)
target_link_libraries(xyenv pthread)

add_custom_command(TARGET xyenv 
                 POST_BUILD
                 COMMAND "make")

add_custom_command(TARGET xyenv
                 POST_BUILD
#                COMMAND valgrind --tool=memcheck --leak-check=yes ./xyenv)
                 COMMAND "xyenv")

