/**
 * @description
 * @fileName State.h.
 * @author komatsu
 * @date 8/2/16.
 * @version 0.0
 */

#ifndef STATEMACHINE_STATE_H
#define STATEMACHINE_STATE_H


#include <stdlib.h>
#include "classes/core/PubSub/PubSub.h"

#define TRUE 1
#define FALSE 0


typedef enum {
    STAY_STATE,
    CHANGE_STATE,
    ENTER_STATE,
    EXIT_STATE,
    STATE_LEN
} STATE_TYPE;



typedef struct state_tmp {
    char *id;
    int isCurrent;
    struct state_tmp *next;
    struct state_tmp *prev;

    void (*onEnter)(struct state_tmp *self);

    void (*onStay)(struct state_tmp *self);

    void (*onExit)(struct state_tmp *self);

} State;


State *state_new(void);

void state_destroy(State *self);

char *get_state_current_bool(State *self);

#endif //STATEMACHINE_STATE_H
