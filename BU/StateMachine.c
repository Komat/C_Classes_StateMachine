/**
 * @fileName statemachine.c
 * @author
 * @version
 * @copyright
 * @description
 */

#include "StateMachine.h"


/**
 *
 */
typedef enum {
    STATE_LOADING,
    STATE_INTRO,
    STATE_MAIN,
    STATE_MAX
} state_list;


/**
 *
 */
typedef enum {
    change_state,
    stay_state,
    enter_state,
    exit_state,
    time_out
} event_types;



/**
 *
 * @param id
 * @param event
 */
void stateHandler(event_types event);


void onLoadingEnterHandler(void);

void onIntroEnterHandler(void);

void onMainEnterHandler(void);


/**
 *
 */
typedef struct StateMachine {

    void (*print_id)(void);

    int isCurrent;

    state_list State;

    void (*stateHandler)(event_types event);

    void (*onEnter)(void);

    void (*onExit)(void);

} stateMachine;


/**
 * state list
 */
stateMachine stateMachineList[] = {
        {
                loading_print_id,
                FALSE,
                STATE_LOADING,
                stateHandler,
                onLoadingEnterHandler,
                loading_onExit
        },
        {
                intro_print_id,
                FALSE,
                STATE_INTRO,
                stateHandler,
                onIntroEnterHandler,
                intro_onExit
        },
        {
                main_print_id,
                FALSE,
                STATE_MAIN,
                stateHandler,
                onMainEnterHandler,
                main_onExit
        },
};


/**
 * 現在の state
 */
stateMachine *currentState = &stateMachineList[STATE_LOADING];


/**
 * 現在の state 取得
 * @return
 */
stateMachine *getState(void) {
    return currentState;
}


/**
 *
 * @param state
 */
void setState(state_list state) {
    if (state >= STATE_MAX) {
        state = STATE_INTRO;
    }

    currentState = &stateMachineList[state];
}


/**
 *
 */
void enterState() {
    getState()->isCurrent = TRUE;

//    getState()->stateHandler(change_state);
    getState()->stateHandler(enter_state);
    getState()->onEnter();
}


/**
 *
 */
void exitState() {
    getState()->isCurrent = FALSE;

    getState()->stateHandler(exit_state);
//    getState()->stateHandler(change_state);
    getState()->onExit();
}


/**
 *
 */
void stayState() {
    getState()->stateHandler(stay_state);
}


/**
 *
 * @param state
 */
void changeState(int state) {

    if (state < STATE_MAX) {
        if (state != getState()->State) {

            exitState();
            setState((state_list) state);
            enterState();

        } else {

            stayState();

        }
    } else {
        exitState();
        printf("FINISH");
    }

}


/**
 *
 */
void initializeState() {
    enterState();
}


/**
 *
 * @param event
 * @return
 */
char *getEventTypeString(event_types event) {
    switch (event) {
        case change_state:
            return "change";
        case stay_state:
            return "stay";
        case enter_state:
            return "enter";
        case exit_state:
            return "exit";
        case time_out:
            return "time_out";
        default:
            return "";
    }
}


/**
 *
 */
void stateHandler(event_types event) {

    puts("\n>>>>>>>>>>>>>>>>>");
    getState()->print_id();
    printf(" :: %s", getEventTypeString(event));
    puts("\n>>>>>>>>>>>>>>>>>\n");

    printf("\n");
}



void onLoadingEnterHandler(void) {
    loading_onEnter();
    changeState(STATE_INTRO);
}



void onIntroEnterHandler(void) {
    intro_onEnter();
    changeState(STATE_MAIN);
}


void onMainEnterHandler(void) {
    main_onEnter();
    changeState(STATE_MAX);
}
