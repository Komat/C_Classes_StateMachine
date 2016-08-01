cmake_minimum_required(VERSION 3.5)
project(StateMachine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c classes/StateMachine/StateMachine.c classes/StateMachine/StateMachine.h classes/StateMachine/states/intro_state.c classes/StateMachine/states/intro_state.h classes/StateMachine/states/loading_state.c classes/StateMachine/states/loading_state.h classes/StateMachine/states/main_state.c classes/StateMachine/states/main_state.h)
add_executable(StateMachine ${SOURCE_FILES})