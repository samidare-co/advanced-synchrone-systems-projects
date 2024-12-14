#include "api_lopht.h"
#include "syncvars.h"
#include "nodes.h"
#include "variables.h"
#include "threads.h"
#include "scheduler_c/scheduler.h"

void global_init()
{

    Scheduler__scheduler_out o;
    Scheduler__scheduler_mem s;
    Scheduler__scheduler_reset(&s);
    int task_end[2] = {0, 0};
}

void mif_entry_point_cpu0()
{
    Scheduler__scheduler_step(task_end, &out, &mem);
    UPDATE_CPU(loc_pc_0, 1);
    switch (out.task_run[0])
    {
    case 0:
        task0();
        break;
    case 1:
        task1();
        break;
    case Scheduler__ntasks:
        break;
    default:
        printf("Error.\n");
        break;
    }
    WAIT_CPU(loc_pc_1, 2);
    loc_pc_1 = -1;
    UPDATE_CPU(loc_pc_0, -1);
}