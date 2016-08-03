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


/**
 * イベントインデックスリスト
 */
typedef enum {
    STAY_STATE,
    CHANGE_STATE,
    ENTER_STATE,
    EXIT_STATE,
    STATE_LEN
} STATE_TYPE;


/**
 * ひな型
 */
typedef struct state_tmp {
    char *id;
    int isCurrent;
    struct state_tmp *next;
    struct state_tmp *prev;

    /**
     * 個別State毎に上書き
     */
    void (*onEnter)(struct state_tmp *self);
    void (*onStay)(struct state_tmp *self);
    void (*onExit)(struct state_tmp *self);

    /**
     * 個別State毎に上書きした際に通知する用
     */
    void (*superOnEnter)(struct state_tmp *self);

    void (*superOnStay)(struct state_tmp *self);

    void (*superOnExit)(struct state_tmp *self);

} State;


/**
 *
 * State を生成
 *
 * @return
 */
State *state_new(void);

/**
 *
 * State 削除
 *
 * @param self
 */
void state_destroy(State *self);

/**
 *
 * isCurrent を TRUE / FALSE の文字列で返すだけ
 * 特にいらないかも
 *
 * @param self
 * @return
 */
char *get_state_current_bool(State *self);


#endif //STATEMACHINE_STATE_H
