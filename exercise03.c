#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MaxBuffer 100000
int buffer=0;
bool producerActivity = 0;
bool consumerActivity = 0;

void *consumer(){
	printf("you've entered the consumer function\n");	
	while(1){
		if(producerActivity && consumerActivity){
			printf("race condition checked\n");
			exit(1);
		}
		
		if(!buffer){
			consumerActivity= 1;
			producerActivity =0;
		}
		else
		if(!consumerActivity){
			buffer -=1;
			if(buffer == rand()%MaxBuffer){
				printf("buffering!\n");
			}
		}
	}
}

void* producer(){
	printf("you've entered the producer function\n");
	while(1){
		if(producerActivity && consumerActivity){
			printf("race condition checked\n");
			exit(1);
		}
		if(buffer == MaxBuffer){
			producerActivity=1;
			consumerActivity=0;
		}
		
		if(!producerActivity){
			buffer+=1;
			if( buffer == rand()& MaxBuffer){
				printf("buffering!\n");
			}
		}
	}
}
int main(){
	pthread_t pT, cT;
	
	pthread_create(&pT, NULL, producer, &pT);
	pthread_create(&cT, NULL, consumer, &cT);

	pthread_join(pT,NULL);
	pthread_join(cT, NULL);
	
	return 0;
}
