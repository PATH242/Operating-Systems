#include <stdio.h>
int main (){
    const int sizeOfAllocation= 8e7;
    for(int i=0;i<10;i++){
        int* a = malloc(sizeOfAllocation);
        memset(a,0,(sizeOfAllocation));
        sleep(1);
    }
    // vmstat 1 si, hence fields remain 0s
    return 0;
}
