#ifndef EXTERNC_H 
#define EXTERNC_H

#include "externc_types.h"
#include "scheduler_data_c/scheduler_data_types.h"



typedef struct {} Externc__deadline_miss_log_out; 
void Externc__deadline_miss_log_step(int date, int task_id, Externc__deadline_miss_log_out * o); 

typedef struct {int v; } Externc__random_out; 
void Externc__random_step(int max, Externc__random_out * o); 


typedef struct {} Externc__print_scheduler_state_out; 
void Externc__print_scheduler_state_step(Scheduler_data__scheduler_state ss, Externc__print_scheduler_state_out * o); 

const char* task_state_to_string(Scheduler_data__task_state state); 
#endif