#include "api_lopht.h"
#include "syncvars.h"
#include "nodes.h"
#include "variables.h"
#include "threads.h"
#include "scheduler_c/scheduler.h"

#define WAIT_END(var) while (api_ldar(&var) != -1)
/* CYCLE FUNCTIONS */

void mif_entry_point_cpu1()
{
	WAIT_CPU(loc_pc_0, 1);
	switch (out.task_run[1])
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
	UPDATE_CPU(loc_pc_1, 2);
	WAIT_END(loc_pc_0);
}