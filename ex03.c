#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <sys/time.h>
#include <error.h>
#include <stdbool.h>
#include <dirent.h>

int main(){
    printf("The available shortcuts: \np+e--> I passed the Exam \nc+a+p-->Get some cappuccino! \n");
    int a[100] = {0};
     char* dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int fd = open(dev,O_RDONLY);
    
    if( fd < 0){
        return EXIT_FAILURE;
    }
    else{
        while(1){
            struct input_event evt;
            read(fd,&evt,sizeof(evt));
          
            if(evt.type==EV_KEY){
        	    a[evt.code] = EV_KEY;
            }
        	if( a[25] == a[18]){
        		printf("I passed the Exam\n");
        	}
        	else
        	if( a[46] == a[30] && a[30] == a[25] && a[25] ){
        		printf("Get some cappuccino!\n");
        	}
        }
    }     
    return 0;
}
