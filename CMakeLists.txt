project(XYEnvironment)
cmake_minimum_required(VERSION 2.6)

include_directories("/home/gordonzu/.local/googletest-release-1.8.0/googlemock/include"
                    "/home/gordonzu/.local/googletest-release-1.8.0/googletest/include"
                    "/home/gordonzu/src/cpp/AICPP/src")
link_directories   ("/home/gordonzu/.local/googletest-release-1.8.0/mybuild/googlemock"
                    "/home/gordonzu/.local/googletest-release-1.8.0/mybuild/googlemock/gtest")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -ggdb3 -Wall -Wno-unused-variable -O0 -fmax-errors=1")

set(sources
    src/agent/environment.cpp
    src/agent/object.cpp
    src/environment/xyenv/xy_environment.cpp
    src/util/datastructure/xy_location.cpp
    src/util/datastructure/matrix.cpp
    src/environment/xyenv/xy_environment_test.cpp
    main.cpp)

add_executable(xyenv ${sources})
target_link_libraries(xyenv gmock)
target_link_libraries(xyenv gtest)
target_link_libraries(xyenv pthread)

add_custom_command(TARGET xyenv 
                 POST_BUILD
                 COMMAND "make")

add_custom_command(TARGET xyenv
                 POST_BUILD
                 COMMAND valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./xyenv)
#                COMMAND valgrind --tool=memcheck --leak-check=yes ./xyenv)
#                COMMAND "xyenv")

