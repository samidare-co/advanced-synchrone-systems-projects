#include "counter_c/counter.h"
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

void main() {
    /* Allocation des sorties */
    Counter__counter_out o ; 
    /* Allocation d l'état */
    Counter__counter_mem s ; 
    /* Initialisation de l'état */
    Counter__counter_reset(&s) ;
    /* Boucle for infinie */
    for(;;) {
        sleep(1); 
        /* Fonction de transition */
        Counter__counter_step(&o,&s) ;
        printf(" Result: cnt=%d\n",o.cnt) ;
    }

}