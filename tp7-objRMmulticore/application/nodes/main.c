#include <stdlib.h>
#include <stdio.h>
#include "scheduler_c/scheduler.h"


int main(){
    int cpt = 0 ; 
    char buffer[100]; 

    Scheduler__scheduler_out o ; 
    Scheduler__scheduler_mem s; 
    Scheduler__scheduler_reset(&s); 
    
    for (;;){
        printf("Cycle : %d\n", cpt); 
        Scheduler__scheduler_step(&o, &s) ; 
        cpt++; 
        fgets(buffer, sizeof(buffer),stdin); 
    }
}