/**
 * @description
 * @fileName IntroState.c.
 * @author komatsu
 * @date 8/2/16.
 * @version 0.0
 */

#include "IntroState.h"

void onIntroEnter(State *self) {
    pubsub_publish(getStateTopicString(CHANGE_STATE), self->id);
    pubsub_publish(getStateTopicString(ENTER_STATE), self->id);
}


void onIntroExit(State *self) {
    pubsub_publish(getStateTopicString(CHANGE_STATE), self->id);
    pubsub_publish(getStateTopicString(EXIT_STATE), self->id);
}


State *intro_new(void) {
    State *self = state_new();
    self->id = "INTRO",
    self->isCurrent = TRUE,
    self->onEnter = onIntroEnter;
    self->onExit = onIntroExit;
    return self;
}
