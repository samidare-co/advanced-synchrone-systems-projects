#include <stdio.h>
#include "min_list_c/min_list.h"

int main()
{
    Min_list__min_flot_mem s;
    Min_list__min_flot_out o;
    Min_list__min_flot_reset(&s);

    int val;
    for (;;)
    {
        printf("Enter a value: ");
        scanf("%d", &val);
        Min_list__min_flot_step(val, &o, &s);
        printf("Min value: %d\n", o.y);
    }
}