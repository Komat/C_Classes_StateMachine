/**
 * @description
 * @fileName State.c.
 * @author komatsu
 * @date 8/2/16.
 * @version 0.0
 */

#include "State.h"

State *state_new(void) {
    State *self;
    if (!(self = malloc(sizeof(State)))) {
        return NULL;
    }
    self->id = NULL;
    self->isCurrent = FALSE;
    self->next = NULL;
    self->prev = NULL;
    self->onEnter = NULL;
    self->onExit = NULL;
    return self;
}


/**
 *
 * @param self
 */
void state_destroy(State *self) {
    free(self);
}

char *get_state_current_bool(State *self) {
    return (self->isCurrent == 1 ? "true" : "false");
}


char *getStateTopicString(STATE_TYPE topic) {
    switch (topic) {
        case CHANGE_STATE:
            return "CHANGE";
        case ENTER_STATE:
            return "ENTER";
        case EXIT_STATE:
            return "EXIT";
        default:
            return "";
    }
}
