/**
 * @fileName main.c
 * @author
 * @version
 * @copyright
 * @description
 */

#include <stdio.h>
#include <stdlib.h>

//#include "StateMachine.h"
#include "State.h"
#include "classes/core/PubSub/PubSub.h"
#include "states/IntroState.h"



/**
 * 購読開始
 */
void state_exit_handler(void *data) {
    printf("%s::EXIT\n", (char *)data);
    pusub_unsubscribe(getStateTopicString(EXIT_STATE), state_exit_handler);
}



/**
 * 購読開始
 */
void state_enter_handler(void *data) {
    printf("%s::ENTER\n", (char *)data);
    pusub_unsubscribe(getStateTopicString(ENTER_STATE), state_enter_handler);
    pubsub_subscribe(getStateTopicString(EXIT_STATE), state_exit_handler);
}



int main(void) {

    // イベント初期化
    pubsub_new();

    State *Intro = intro_new();

    pubsub_subscribe(getStateTopicString(ENTER_STATE), state_enter_handler);

    Intro->onEnter(Intro);

    printf("%s::isCurrent %s\n", Intro->id, get_state_current_bool(Intro));

    Intro->onExit(Intro);

    state_destroy(Intro);


//    int input;
//
//    initializeState();
//
//    while (1) {
//        printf("Please input number: \n");
//        scanf("%d", &input);
//
//        if (input == -1)
//            break;
//
//        fflush(stdout);
//        changeState(input);
//    }

    return EXIT_SUCCESS;
}

