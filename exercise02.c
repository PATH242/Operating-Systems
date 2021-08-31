#include <string.h>
#include <stdio.h>
const int N = 1e5+5;
int main(){
  char s[N];
  printf("Please enter 1 word:\n");
  scanf("%s",s);
  printf("The reverse of that word is:\n");
  for(int i = strlen(s) - 1; i >= 0; i-- )
    printf("%c", s[i]);
  return 0;
}
