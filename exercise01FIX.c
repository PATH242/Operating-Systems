#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* threadOut( void* a){
	printf("Welcome to this thread\tit has ID of: %lu\n", *(unsigned long*)a);
	pthread_exit(NULL);
}
int main(){
	int n=3;
	for(int i=0;i<n;i++){
		pthread_t threadID;
		pthread_create(&threadID, NULL, threadOut,&threadID);
		printf("creation of thread is complete: %lu\n", threadID);
		pthread_join( threadID, NULL); ///the fix
	}
	return 0;
}
