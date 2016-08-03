/**
 * @description
 * @fileName StateMachine.h
 * @author 小松
 * @date 8/3/16
 * @version 0.0.0
 */

#ifndef STATEMACHINE_STATEMACHINE_H
#define STATEMACHINE_STATEMACHINE_H


#include "State.h"

/**
 *
 */
extern char *STATE_TOPIC_LIST[];

/**
 *
 */
void state_machine_init(void);

/**
 *
 * @param param
 * @param fun
 */
void state_machine_subscribe(STATE_TYPE param, void (*fun)(State *));

/**
 *
 * @param param
 * @param fun
 */
void state_machine_unsubscribe(STATE_TYPE param, void (*fun)(State *));

/**
 *
 * @return
 */
hash *state_machine_new(void);

/**
 *
 * @param state_machine
 * @param state_machine_list
 */
void state_machine_destroy(hash *state_machine, dictionary *state_machine_list);

/**
 *
 * @param state_list
 * @param state
 * @return
 */
hash_template *state_machine_add(hash *state_list, State *state);

/**
 *
 * @param state_list
 * @return
 */
dictionary *state_machine_ready(hash *state_list);

/**
 *
 * @param state_machine
 * @param state
 */
void state_machine_goto(hash *state_machine, State *state);

/**
 *
 * @param state_machine
 * @param state
 */
void state_machine_exit(hash *state_machine, State *state);

#endif //STATEMACHINE_STATEMACHINE_H
