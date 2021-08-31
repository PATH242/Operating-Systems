#include <stdio.h>
#include <string.h>
int main(int a, char *c[])
{
   int n, spaces;
   sscanf(c[1], "%d", &n);
    for(int stars = 1; stars < 2*n ; stars += 2){
       spaces = (2*n - stars)/2;
       for(int j = 0; j<spaces; j++)
            printf(" ");
       for(int j = 0; j<stars; j++)      
            printf("*");
        printf("\n");
    }
    return 0;
}
