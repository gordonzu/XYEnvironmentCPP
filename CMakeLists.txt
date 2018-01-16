project(XYEnvironment)
cmake_minimum_required(VERSION 2.6)

include_directories("$ENV{GMOCK_HOME}/googlemock/include" 
                    "$ENV{GMOCK_HOME}/googletest/include"
                    "$ENV{HOME}/src/cpp/AICPP/src" ) 
link_directories   ("$ENV{GMOCK_HOME}/mybuild/googlemock" 
                    "$ENV{GMOCK_HOME}/mybuild/googlemock/gtest")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -ggdb3 -Wall -O0 -fmax-errors=1")

set(sources
    src/Environment/xyenv/cpp/Wall.cpp
    src/Environment/xyenv/cpp/XYEnvironment.cpp
    src/Agent/cpp/EnvironmentObject.cpp
    src/Agent/impl/cpp/AbstractEnvironment.cpp
    src/Util/datastructure/cpp/LocationPair.cpp
    src/tests/AgentTest/impl/cpp/MockAgent.cpp
    src/Agent/impl/cpp/AbstractAgent.cpp
    src/Agent/cpp/Agent.cpp
    src/Util/datastructure/cpp/XYLocation.cpp
    src/Environment/xyenv/cpp/XYEnvironmentState.cpp
    src/tests/EnvironmentTest/XYEnvironmentTest.cpp
    main.cpp
  )

add_executable(xyenv ${sources})
target_link_libraries(xyenv gmock)
target_link_libraries(xyenv gtest)
target_link_libraries(xyenv pthread)

add_custom_command(TARGET xyenv 
                 POST_BUILD
                 COMMAND "make")

add_custom_command(TARGET xyenv
                 POST_BUILD
                 COMMAND valgrind --tool=memcheck --leak-check=yes ./xyenv)
#                 COMMAND valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./xyenv)
#                 COMMAND "xyenv")

