/**
 * @fileName main_state.c.
 * @author komatsu
 * @version 0.0
 * @date 8/1/16.
 * @description
 */

#include "main_state.h"


char *main_id = "main";


void main_print_id(void) {
    printf("%s", main_id);
}

/**
 *
 */
void main_onEnter(void) {

   int key_type;

   printf("\n\n*********************************************\n");
   printf("*********************************************\n");
   printf("*********************************************\n");
   printf("*********************************************\n");
   printf("*********************************************\n");
   printf("*********************************************\n");
   printf("*********************************************\n");
   printf("*********************************************\n");
   printf("*********************************************\n");
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
void main_onExit(void) {

    printf("\n\n\n");
    printf("GAME END... .. . ");
    printf("\n\n\n");

}


