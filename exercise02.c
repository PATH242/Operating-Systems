///manipulation of memory using malloc,pointers,free

#include <stdio.h>
int main(){
    int n;
    printf("please enter the size of the array you want:\n");
    scanf("%d",&n);
    int* arr = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        *(arr+i)=i;
    }
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
    free(arr);
    return 0;
}
