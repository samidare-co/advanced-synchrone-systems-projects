#include <stdlib.h>
#include <stdio.h>
#include "scheduler_c/scheduler.h"

int main()
{
    int cpt = 0;
    char buffer[100];

    Scheduler__scheduler_out o;
    Scheduler__scheduler_mem s;
    Scheduler__scheduler_reset(&s);
    int task_end[2] = {0, 0};
    for (;;)
    {
        printf("Cycle : %d\n", cpt);
        printf("Entrez task_end[0] : ");
        scanf("%d", &task_end[0]);
        printf("Entrez task_end[1] : ");
        scanf("%d", &task_end[1]);
        Scheduler__scheduler_step(task_end, &o, &s);
        cpt++;
        fgets(buffer, sizeof(buffer), stdin);
    }
}