#include "extern.h"

void Extern__read_bool_step(int addr,
Extern__read_bool_out*_out) {
printf("read_bool(%d):",addr) ; fflush(stdout) ;
scanf("%d",&(_out->value)) ;
}

void Extern__f1_step(int i, Extern__f1_out* _out){
    _out->o = i+5; 
    printf("F1(%d)=%d\n",i,_out->o) ;
}

void Extern__f2_step(int i,Extern__f2_out*_out) {
_out->o = i + 100 ;
printf("F2(%d)=%d\n",i,_out->o) ;
}

void Extern__g_step(Extern__g_out*_out) {
static int s = 300 ;
s += 50;
_out->o = s ;
printf("G()=%d\n",_out->o) ;
}

void Extern__act_step(int i, Extern__act_out*_out) {
    printf("actuator : %d\n", i); 
}