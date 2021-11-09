#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <sys/time.h>
#include <error.h>
#include <stdbool.h>
int main(){
    
    char* dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    
    int fd = open(dev,O_RDONLY);
    if(fd < 0){
        return EXIT_FAILURE;
    }
    else{
        struct input_event evt;
        while(1){
            ssize_t temp = read(fd,&evt,sizeof(evt));
            if(evt.value == 0 && evt.type == EV_KEY)
                printf("RELEASED 0x%04x (%d)\n", evt.code, evt.code);
            else 
            if (evt.value == 1 && evt.type == EV_KEY)
                printf("PRESSED 0x%04x (%d)\n", evt.code, evt.code);
           
            fflush(stdout);
        } 
    }
    return EXIT_SUCCESS;
}
