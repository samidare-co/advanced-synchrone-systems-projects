#include "externc.h"

void Externc__deadline_miss_log_step(int date, int task_id, Externc__deadline_miss_log_out * o){ 
      printf("!!! La tache %d a manque son echeance a la date %d !!!\n", task_id+1, date); 
}

void Externc__random_step(int max, Externc__random_out * o){
    int random = (rand()%max)+1; 
    o->v = random; 
}

const char* task_state_to_string(Scheduler_data__task_state state) {
    switch (state) {
        case Scheduler_data__Running:
            return "Running";
        case Scheduler_data__Ready:
            return "Ready";
        case Scheduler_data__Waiting:
            return "Waiting";
        default:
            return "???";
    }
}



void Externc__print_scheduler_state_step(Scheduler_data__scheduler_state ss, Externc__print_scheduler_state_out * o) 
{
    printf("date courante : %d\n", ss.current_date); 
    for (int i = 0 ; i<sizeof(ss.tasks)/sizeof(ss.tasks[0]); i++){
        printf("Tache %d\n", i+1); 
        printf("\techeance courante: %d\n", ss.tasks[i].current_deadline); 
        printf("\tstatus: %s\n", task_state_to_string(ss.tasks[i].status)); 
        printf("\treste: %d\n", ss.tasks[i].left); 
    }
}

