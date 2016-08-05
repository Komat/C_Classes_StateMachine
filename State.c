/**
 * @description
 * @fileName State.c.
 * @author komatsu
 * @date 8/2/16.
 * @version 0.0
 */

#include "State.h"

/**
 *
 */
char *_STATE_TOPIC_LIST[] = {
    "stay_state",
    "change_state",
    "enter_state",
    "exit_state"
};


char **STATE_TOPIC_LIST = _STATE_TOPIC_LIST;

/**
 *
 * @param state
 */
static void onEnter(State *state) {
    state->isCurrent = TRUE;
    pubsub_publish(STATE_TOPIC_LIST[CHANGE_STATE], state);
    pubsub_publish(STATE_TOPIC_LIST[ENTER_STATE], state);
}

/**
 *
 * @param state
 */
static void onStay(State *state) {
    if (state->isCurrent != TRUE) {
        state->isCurrent = TRUE;
    }
    pubsub_publish(STATE_TOPIC_LIST[STAY_STATE], state);
}

/**
 *
 * @param state
 */
static void onExit(State *state) {
    state->isCurrent = FALSE;
    pubsub_publish(STATE_TOPIC_LIST[CHANGE_STATE], state);
    pubsub_publish(STATE_TOPIC_LIST[EXIT_STATE], state);
}


/**
 *
 * @return
 */
State *state_new(void) {
    State *self;
    if (!(self = malloc(sizeof(State)))) {
        return NULL;
    }
    self->id = NULL;
    self->isCurrent = FALSE;
    self->next = NULL;
    self->prev = NULL;
    self->onEnter = onEnter;
    self->onStay = onStay;
    self->onExit = onExit;
    self->superOnEnter = onEnter;
    self->superOnStay = onStay;
    self->superOnExit = onExit;
    return self;
}


/**
 *
 * @param self
 */
void state_destroy(State *self) {
    free(self);
}

/**
 *
 * @param self
 * @return
 */
char *get_state_current_bool(State *self) {
    return (self->isCurrent == 1 ? "true" : "false");
}


