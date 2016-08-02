cmake_minimum_required(VERSION 3.5)
project(StateMachine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(
        SOURCE_FILES
        main.c
        State.c State.h
        classes/StateMachine/states/intro_state.c classes/StateMachine/states/intro_state.h
        classes/StateMachine/states/loading_state.c classes/StateMachine/states/loading_state.h
        classes/StateMachine/states/main_state.c classes/StateMachine/states/main_state.h
        classes/core/Dictionary/Hash.c classes/core/Dictionary/Hash.h
        classes/core/Dictionary/Dictionary.c classes/core/Dictionary/Dictionary.h
        classes/core/ItemList/Item.c classes/core/ItemList/Item.h
        classes/core/ItemList/ItemList.c classes/core/ItemList/ItemList.h
        classes/core/PubSub/PubSub.c classes/core/PubSub/PubSub.h
        states/IntroState.c states/IntroState.h
        states/MainState.c states/MainState.h)

add_executable(StateMachine ${SOURCE_FILES})