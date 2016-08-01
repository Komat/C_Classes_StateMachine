/**
 * @fileName intro_state.c.
 * @author komatsu
 * @version 0.0
 * @date 8/1/16.
 * @description
 */

#include "intro_state.h"


char *intro_id = "intro_id";


void intro_print_id(void) {
    printf("%s", intro_id);
}

/**
 *
 */
void intro_onEnter(void) {

    int key_type;


    printf("\n\n*********************************************\n\n");
    printf("              GAME START\n\n");
    printf("            [ PRESS ENTER ]\n\n");
    printf("*********************************************\n\n");

    while ((key_type = getchar()) != EOF) {
        if (key_type == '\n') {
            break;
        }
    }

}


/**
 *
 */
void intro_onExit(void) {

    printf("\n\n\n");
    intro_print_id();
    printf("\n\n\n");

}


