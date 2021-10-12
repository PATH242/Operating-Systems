#include <stdio.h>
int main (){
    const int sizeOfAllocation= 8e7;
    for(int i=0;i<10;i++){
        int* a = malloc(sizeOfAllocation);
        memset(a,0,(sizeOfAllocation));
        printf("test\n");
        sleep(1);
    }
    // vmstat 1 si, fields remain 0s, and top shows that it's using much memory
    return 0;
}
