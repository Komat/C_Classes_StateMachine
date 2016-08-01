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

#include "states/loading_state.h"
#include "states/intro_state.h"
#include "states/main_state.h"

#define TRUE     1
#define FALSE     0

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
