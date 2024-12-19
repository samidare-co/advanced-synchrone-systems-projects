#include "reset_counter_c/reset_counter.h"
#include <stdio.h>

int main()
{
    Reset_counter__reset_counter_out o;
    Reset_counter__reset_counter_mem s;
    Reset_counter__reset_counter_reset(&s);

    int resetBool = 0;

    for (;;)
    {
        printf("Enter 1 to reset the counter, 0 to increment it\n");
        scanf("%d", &resetBool);
        Reset_counter__reset_counter_step(resetBool, &o, &s);
        printf("Counter: %d\n", o.counter);
    }
}