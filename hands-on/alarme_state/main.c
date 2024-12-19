#include <stdio.h>
#include "alarme_c/alarme.h"

int main()
{
    Alarme__alarme_out o;
    Alarme__alarme_mem s;
    Alarme__alarme_reset(&s);

    int val;
    for (;;)
    {
        printf("Enter a value: ");
        scanf("%d", &val);
        Alarme__alarme_step(val, &o, &s);
        printf("Alarme: %d\n", o.alarme);
    }
}