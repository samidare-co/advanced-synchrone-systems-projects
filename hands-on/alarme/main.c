#include <stdio.h>
#include "alarme_c/alarme.h"

int main()
{
    Alarme__alarme_out o;

    int val;
    for (;;)
    {
        printf("Enter a value: ");
        scanf("%d", &val);
        Alarme__alarme_step(val, &o);
        printf("Alarme: %d\n", o.alarme);
    }
}