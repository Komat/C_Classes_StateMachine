/**
 * @description
 * @fileName StateMachine.h
 * @author 小松
 * @date 8/3/16
 * @version 0.0.0
 */

#include "StateMachine.h"



void state_machine_init(void) {
}


hash *state_machine_new(void) {
    hash *state_list = hash_new();
    return state_list;
}



hash_template *state_machine_add(hash *state_list, State *state) {
    hash_template *state_machine = dictionary_set(state_list, state->id, state);
    return state_machine;
}



dictionary *state_machine_ready(hash *state_machine) {
    dictionary *state_machine_iterator = dictionary_new(state_machine);
    return state_machine_iterator;
}



static void state_handler(void *state) {
    State *next_state = ((State *) state)->next;
    next_state->onEnter(next_state);
    pusub_unsubscribe(STATE_TOPIC_LIST[EXIT_STATE], state_handler);
}



static void subscribe_state() {
    pubsub_subscribe(STATE_TOPIC_LIST[EXIT_STATE], state_handler);
}



static State *get_current_state(hash *state_machine) {

    dictionary *it = dictionary_new(state_machine);
    hash_template *state;

    while ((state = dictionary_next(it))) {
        if (((State *) state->val)->isCurrent == TRUE) {
            dictionary_destroy(it);
            return ((State *) state->val);
        }
    }

    dictionary_destroy(it);
    return NULL;
}




void state_machine_goto(hash *state_machine, State *state) {

    State *current_state;

    switch(state->isCurrent) {

        case FALSE:
            current_state = get_current_state(state_machine);
            if (current_state) {

                // TODO:
                state->prev = current_state;
                current_state->next = state;

                subscribe_state();
                current_state->onExit(current_state);
            } else {
                state->onEnter(state);
            }
            break;

        case TRUE:
            state->onStay(state);
            break;

        default:
            state->onStay(state);
            break;
    }
}


