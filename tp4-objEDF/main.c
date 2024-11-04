#include <stdlib.h>
#include <stdio.h>
#include "scheduler_c/scheduler.h"


int main(){
    int cpt = 0 ; 
    char buffer[100]; 
    
    Scheduler__main_out o ; 
    Scheduler__main_mem s ; 
    Scheduler__main_reset(&s); 

    
    for (;;){
        printf("Cycle : %d\n", cpt); 
        Scheduler__main_step(&o, &s) ; 
        cpt++; 
        fgets(buffer, sizeof(buffer),stdin); 
    }
}