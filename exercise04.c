#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main (){
    struct rusage truerusage;
    const int sizeOfAllocation= 8e7;
    for(int i=0;i<10;i++){
        int* a = malloc(sizeOfAllocation);
        memset(a,0,(sizeOfAllocation));
        getrusage(RUSAGE_SELF, &truerusage);
        printf("The true usage is: %ld\n", truerusage.ru_ixrss + truerusage.ru_idrss + truerusage.ru_isrss);
        sleep(1);
    }
    return (0) ;
}
