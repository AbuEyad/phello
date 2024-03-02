#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int x = 0;
    
    int pid = fork();
    if(pid == -1){
        return 1;
    }
    if(pid == 0){
        x++;
    }

    
    sleep(1);
    printf("Value of x = %d\n", x);
    
    printf("PID = %d\n", getpid());
    if (pid != 0) {
        wait(NULL);
    }



    return 0;
}