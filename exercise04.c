///create your own realloc
#include <stdio.h>
void reallocate(int* ptr, int newSize){
    if(ptr==NULL){
        ptr= malloc(newSize* sizeof(int));
        return;
    }
    if(newSize==0){
        free(ptr);
        return;
    }
    int* tmpptr= malloc(sizeof(ptr));
    memcpy(tmpptr, ptr, sizeof(ptr));
    ptr= malloc(newSize*sizeof(int));
    memcpy(ptr, tmpptr, sizeof(ptr));
    return;
}
int main(){
    int n,n1;
    printf("please enter the size of the array you want: \n");
    scanf("%d",&n);
    int* arr = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        *(arr+i)= 3; ///temp value to check correctness
    }
    printf("please enter the new size of the array you want:\n");
    scanf("%d",&n1);
    reallocate(arr,n1);
    for(int i=0;i<n1;i++){
        printf("%d ",*(arr+i));
    }
    return 0;
}
