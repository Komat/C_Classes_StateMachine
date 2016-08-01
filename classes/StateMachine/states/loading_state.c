/**
 * @fileName loading_state.c.
 * @author komatsu
 * @version 0.0
 * @date 8/1/16.
 * @description
 */


#include "loading_state.h"


char *loading_id = "loading_id";


int sleep(unsigned long x) {
    clock_t c1 = clock(), c2;

    do {
        if ((c2 = clock()) == (clock_t) -1)
            return (0);
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return (1);
}


void count_up(int *num) {

    *num += 1;

    printf("%2d / 100\n", *num);

    sleep(30);

    if (*num < 100) {
        count_up(num);
    }
}


void loading_print_id(void) {
    printf("%s", loading_id);
}

/**
 *
 */
void loading_onEnter(void) {


    int count = 0;

    count_up(&count);

    printf("LOAD COMPLETE");

}


/**
 *
 */
void loading_onExit(void) {

    printf("\n\n\n");
    loading_print_id();
    printf("\n\n\n");

}


