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


int sleep(unsigned long x) {
    clock_t c1 = clock(), c2;

    do {

        if ((c2 = clock()) == (clock_t) -1)
            return 0;
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);

    return 1;

}


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



/**
 * 購読開始
 */
void intro_enter_handler(State *state) {
    printf("[ONCE::%s::ENTER]\n", state->id);
    state_machie_unsubscribe(ENTER_STATE, intro_enter_handler);
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

    state_machine_init();

    state_machie_subscribe(ENTER_STATE, state_enter_handler);
    state_machie_subscribe(STAY_STATE, state_stay_handler);
    state_machie_subscribe(EXIT_STATE, state_exit_handler);

    hash *state_machine = state_machine_new();

    State *Intro = intro_state_new();
    State *Main = main_state_new();

    state_machine_add(state_machine, Intro);
    state_machine_add(state_machine, Main);

    dictionary *state_machine_list = state_machine_ready(state_machine);

    state_machie_subscribe(ENTER_STATE, intro_enter_handler);
    state_machine_goto(state_machine, Intro);
    sleep(1500);
    state_machine_goto(state_machine, Main);
    sleep(1500);
    state_machie_subscribe(ENTER_STATE, intro_enter_handler);
    state_machine_goto(state_machine, Intro);
    sleep(1500);
    state_machine_exit(state_machine, Intro);

    state_machie_unsubscribe(ENTER_STATE, state_enter_handler);
    state_machie_unsubscribe(STAY_STATE, state_stay_handler);
    state_machie_unsubscribe(EXIT_STATE, state_exit_handler);

    state_machine_destroy(state_machine, state_machine_list);

    return EXIT_SUCCESS;
}

