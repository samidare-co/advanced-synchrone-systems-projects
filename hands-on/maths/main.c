#include "identite_c/identite.h"

int main(){
    Identite__sum_out *o ; 
    Identite__sum_step(o); 
    printf("sortie : %d\n", o->s); 

}