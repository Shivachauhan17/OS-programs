#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


#define MAX_MSG 40

enum process_type_t {
	PARENT,
	CHILD
};


void write_pid(const enum process_type_t ptype){
    const char *msg_template="PID =%d - %s\n";
    char msg[MAX_MSG];
    sprintf(msg,msg_template,getpid(),ptype==PARENT?"Parent":"Child");
    write(STDOUT_FILENO,msg,strlen(msg));
}


int main(){
    const pid_t pid=fork();
    if(pid<0){
        fprintf(stderr, "Failed to fork the process\n");
		exit(EXIT_FAILURE);
    }
    else if(pid==0){
        write_pid(CHILD);
        exit(EXIT_FAILURE);
    }
    else{
        write_pid(PARENT);
        int count=0;
        while(1){
            sleep(1);
            if(count==10){
                wait(NULL);
                // break;
            }
            count++;
        }
    }

    return 0;
}