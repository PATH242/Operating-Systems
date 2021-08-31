#include <stdio.h>
#include <string.h>
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
  int x,y;
  printf("please enter 2 numbers\n");
  scanf("%d%d", &x, &y);
  swap(&x, &y);
  printf("after swapping, the first number became %d, while the second became %d\n",x,y);
  return 0;
}
