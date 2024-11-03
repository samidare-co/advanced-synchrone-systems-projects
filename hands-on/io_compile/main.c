#include "fileA_c/fileA.h"
#include "fileC_c/fileC.h"

int main(){
    int input = 4; 

    FileA__foo_out fooA_output ; 
    FileA__foo_step(input, &fooA_output) ;

    FileA__bar_out bar_output ; 
    FileA__bar_step(input, &bar_output) ; 

    FileC__foo_out fooC_output ; 
    FileC__foo_step(input, &fooC_output) ;

}




