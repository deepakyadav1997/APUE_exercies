#include "apue.h"


int my_dup_2(int fd1,int fd2){
    
    if(fd1 == fd2){
        return fd2;
    }

    // if fd2 already exists close it
    close(fd2);

    int new_fd = 0;
    int* open_fd = calloc(fd2,sizeof(int));
    int index = 0;

    //Loop through the fd's till we get our fd2
    while(new_fd != fd2){
        new_fd = dup(fd1);
        if(new_fd == fd2)
            break;
        open_fd[index++] = new_fd; 
    }

    //close all fd's that we opened other than fd2
    index = 0;
    while(index < fd2){
        //Reached 0, i.e all opened FD's closed
        if(open_fd[index] == 0)
            break;
        close(open_fd[index]);
        index++;
    }
    free(open_fd);
    return fd2;
}

int main(){
    printf("%d\n",getpid());
    my_dup_2(1,12);
    while (1){
        sleep(1);
    }
    return 0;
    

}