#include <stdio.h>
#include <stdlib.h>

int main(){
	char command[10000];
	while(1){
		printf("please enter a valid command:\n>>> ");
		scanf("%s", command);
		system(command);
	}
	
	return 0;
}

