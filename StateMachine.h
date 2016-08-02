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

extern char *STATE_TOPIC_LIST[];

void state_machine_init(void);


void state_machie_subscribe(STATE_TYPE param, void (*fun)(State *));

void state_machie_unsubscribe(STATE_TYPE param, void (*fun)(State *));

hash *state_machine_new(void);

void state_machine_destroy(hash *state_machine, dictionary *state_machine_list);

hash_template *state_machine_add(hash *state_list, State *state);

dictionary *state_machine_ready(hash *state_list);

void state_machine_goto(hash *state_machine, State *state);

void state_machine_exit(hash *state_machine, State *state);

#endif //STATEMACHINE_STATEMACHINE_H
