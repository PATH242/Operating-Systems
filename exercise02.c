#include <string.h>
#include <stdio.h>
cost int N = 1e5+5;
char s[N],ch;
int idx = 0;
int main(){
  printf("Please enter 1 word:\n");
  scanf("%s",s);
  printf("The reverse of that word is:\n");
  for(int i = strlen(s) - 1; i >= 0; i-- )
    printf("%c", s[i]);
  return 0;
}
