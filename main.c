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
#include "states/MainState.h"



/**
 * 購読開始
 */
void state_exit_handler(void *data) {
    printf("%s::EXIT\n", (char *)data);
//    pusub_unsubscribe(getStateTopicString(EXIT_STATE), state_exit_handler);
}



/**
 * 購読開始
 */
void state_enter_handler(void *data) {
    printf("%s::ENTER\n", (char *)data);
//    pusub_unsubscribe(getStateTopicString(ENTER_STATE), state_enter_handler);
//    pubsub_subscribe(getStateTopicString(EXIT_STATE), state_exit_handler);
}

int main(void) {

    // イベント初期化
    pubsub_new();
    pubsub_subscribe(getStateTopicString(ENTER_STATE), state_enter_handler);
    pubsub_subscribe(getStateTopicString(EXIT_STATE), state_exit_handler);

    State *Intro = intro_state_new();
    State *Main = main_state_new();

    /**
     * intro state test
     */
    Intro->onEnter(Intro);
    printf("%s::isCurrent %s\n", Intro->id, get_state_current_bool(Intro));
    Intro->onExit(Intro);

    /**
     * main state test
     */
    Main->onEnter(Main);
    printf("%s::isCurrent %s\n", Main->id, get_state_current_bool(Main));
    Main->onExit(Main);


    hash *state_list = hash_new();
    hash_template *_intro_state = dictionary_set(state_list, Intro->id, &Intro);
    hash_template *_main_state = dictionary_set(state_list, Main->id, &Main);

    dictionary *_state_list_iterator = dictionary_new(state_list);

    hash_template *pair;

    while ((pair = dictionary_next(_state_list_iterator))) {
        printf("KEY : %s, VAL: %s\n", pair->key, ((State *) pair->val)->id);
    }

    hash_template *target_state = dictionary_get(state_list, Main->id);

    printf("LANG: %s\n",  (char *) *(((State *) target_state->val)->id));

    state_destroy(Intro);
    state_destroy(Main);

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

