/**
 * @fileName main.c
 * @author
 * @version
 * @copyright
 * @description
 */

#include <stdio.h>
#include <stdlib.h>

#include "classes/StateMachine/StateMachine.h"

int main(void) {

    int input;

    initializeState();

    while (1) {
        printf("Please input number: \n");
        scanf("%d", &input);

        if (input == -1)
            break;

        fflush(stdout);
        changeState(input);
    }

    return EXIT_SUCCESS;
}

