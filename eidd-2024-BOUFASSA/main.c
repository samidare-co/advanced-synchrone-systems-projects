#include <stdio.h> 
#include "app_c/app.h"
#include <unistd.h>



int main(){

    //App__modulo_cnt_params_4__mem scnt;
    //App__modulo_cnt_params_4__out ocnt;
    //App__modulo_cnt_params_4__reset(&scnt);

    //App__modulo_off_params_42__mem s;
    //App__modulo_off_params_42__out o;
    //App__modulo_off_params_42__reset(&s);

    App__main_app_mem s;
    App__main_app_out o;
    App__main_app_reset(&s);

    for (;;)
    {
        App__main_app_step( &o, &s);
        printf("main output : %d\n", o.out);
        sleep(1) ; 
    }

}