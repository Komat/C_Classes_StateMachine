/**
 * @fileName main.c
 * @author
 * @version
 * @copyright
 * @description
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "classes/core/PubSub/PubSub.h"
#include "State.h"
#include "StateMachine.h"


/**
 *
 */
extern char *STATE_TOPIC_LIST[];


/**
 * 購読開始
 */
void state_exit_handler(State *state) {
    printf("%s::EXIT\n", state->id);
}



/**
 * 購読開始
 */
void state_stay_handler(State *state) {
    printf("%s::STAY\n", state->id);
}



/**
 * 購読開始
 */
void state_enter_handler(State *state) {
    printf("%s::ENTER\n", state->id);
}


int sleep(unsigned long x) {
    clock_t c1 = clock(), c2;

    do {

        if ((c2 = clock()) == (clock_t) -1)
            return 0;
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);

    return 1;

}


State *main_state_new(void) {
    State *self = state_new();
    self->id = "MAIN";
    return self;
}



State *intro_state_new(void) {
    State *self = state_new();
    self->id = "INTRO";
    return self;
}


int main(void) {


    pubsub_new();
    pubsub_subscribe(STATE_TOPIC_LIST[ENTER_STATE], (Subscriber) state_enter_handler);
    pubsub_subscribe(STATE_TOPIC_LIST[STAY_STATE], (Subscriber) state_stay_handler);
    pubsub_subscribe(STATE_TOPIC_LIST[EXIT_STATE], (Subscriber) state_exit_handler);

    hash *state_machine = state_machine_new();

    State *Intro = intro_state_new();
    State *Main = main_state_new();

    state_machine_add(state_machine, Intro);
    state_machine_add(state_machine, Main);

    dictionary *state_machine_list = state_machine_ready(state_machine);

    state_machine_goto(state_machine, Intro);
    sleep(5000);
    state_machine_goto(state_machine, Main);
    sleep(5000);
    state_machine_goto(state_machine, Intro);


    state_destroy(Intro);
    state_destroy(Main);

    return EXIT_SUCCESS;
}

