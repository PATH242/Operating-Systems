#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int arr []){

    int sizeOfArray =( (int) ( sizeof(arr) / sizeof(arr[0]) ));

    ///bubble sort:
    for(int i=0; i<sizeOfArray ; i++){
        for(int j=0; j<sizeOfArray-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    ///print the array:
    printf("The sorted array is:\n");
    for(int i=0; i<sizeOfArray; i++){
        printf("%d ",arr[i]);

    }
    printf("\n");
    return;
}
int main(){
    int a[]={6,5,4,3,2,1};
    bubble_sort(a);
    return 0;
}
