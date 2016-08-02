/**
 * @description
 * @fileName MainState.c.
 * @author komatsu
 * @date 8/2/16.
 * @version 0.0
 */

#include "MainState.h"

void onMainEnter(State *self) {
    pubsub_publish(getStateTopicString(CHANGE_STATE), self->id);
    pubsub_publish(getStateTopicString(ENTER_STATE), self->id);
}


void onMainExit(State *self) {
    pubsub_publish(getStateTopicString(CHANGE_STATE), self->id);
    pubsub_publish(getStateTopicString(EXIT_STATE), self->id);
}


State *main_state_new(void) {
    State *self = state_new();
    self->id = "MAIN",
    self->isCurrent = TRUE,
    self->onEnter = onMainEnter;
    self->onExit = onMainExit;
    return self;
}
