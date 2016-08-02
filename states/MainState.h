/**
 * @description
 * @fileName MainState.h.
 * @author komatsu
 * @date 8/2/16.
 * @version 0.0
 */

#ifndef STATEMACHINE_MAINSTATE_H
#define STATEMACHINE_MAINSTATE_H

#include "../State.h"
#include "../classes/core/PubSub/PubSub.h"


void onMainEnter(State *self);

void onMainExit(State *self);

State *main_state_new(void);


#endif //STATEMACHINE_MAINSTATE_H
