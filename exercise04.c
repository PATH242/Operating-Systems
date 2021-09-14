#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define size 1000
#define arraySize 100000

int main(){
	char commandLine[arraySize];
	char* commandArguments [arraySize];
	printf("enter the commands you want to execute\n");
	while(1){
		for(int i=0; i<size;i++){
			commandLine[i]= '\0';
			commandArguments[i]= NULL;
		}
		
		fgets( commandLine, sizeof(commandLine), stdin);
		int a=0, b=0;
		
		commandArguments[0]= (char*)malloc(size);
		
		for(int i=0; i<strlen(commandLine)-1; i++){
			if( commandLine[i] == ' '){
				commandArguments[a++][b]='\0';
				commandArguments[a]= (char*)malloc(size);
				b=0;
			}
			else{
				commandArguments[a][b++]= commandLine[i];
			}
		}
		
		int forkValue= fork();
		if(forkValue == 0){
			execvp(commandArguments[0], commandArguments);
		}
	}
	return 0;
}
