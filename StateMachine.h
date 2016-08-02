/**
 * @fileName statemachine.h
 * @author
 * @version
 * @copyright
 * @description
 */

#ifndef STATEMACHINE_STATEMACHINE_H
#define STATEMACHINE_STATEMACHINE_H

#include <stdio.h>

#include "State.h"

#include "classes/StateMachine/states/loading_state.h"
#include "classes/StateMachine/states/intro_state.h"
#include "classes/StateMachine/states/main_state.h"

/**
 *
 * @param state
 */
void changeState(int state);

/**
 *
 */
void initializeState(void);


#endif //STATEMACHINE_STATEMACHINE_H
