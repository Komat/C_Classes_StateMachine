/**
 * @description
 * @fileName IntroState.h.
 * @author komatsu
 * @date 8/2/16.
 * @version 0.0
 */

#ifndef STATEMACHINE_INTROSTATE_H
#define STATEMACHINE_INTROSTATE_H

#include "../State.h"
#include "../classes/core/PubSub/PubSub.h"


void onIntroEnter(State *self);

void onIntroExit(State *self);

State *intro_state_new(void);

#endif //STATEMACHINE_INTROSTATE_H
