#include <stdio.h>
#include <unistd.h>
int main(){
	int forkValue= fork();

	if(forkValue == 0){
		printf("Hello from child [%d, %d]\n", getpid(), forkValue);
	}
	else
	if(forkValue >0){
		printf("Hello from parent [%d, %d]\n", getpid(), forkValue);
	}
	else{
		printf("something went wrong\n");
	}

	return 0;
}
