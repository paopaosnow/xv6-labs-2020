#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
//https://www.geeksforgeeks.org/c-program-demonstrate-fork-and-pipe/

int
main(int argc,int *argv[]){
    int pipe_parent[2];
    int pipe_child[2];
    char buf[5];
    //char bufp[2];
    pipe(pipe_parent);
    pipe(pipe_child);
    
    if(fork()==0){
        // child process

        // read parent's pipe[0]
        close(pipe_parent[1]);
        read(pipe_parent[0],buf,5);
        close(pipe_parent[0]);

        int child_pid = getpid();
        printf("child <%d> received %s\n",child_pid,buf);

        
        // write to child's pipe[1]
        close(pipe_child[0]);
        write(pipe_child[1],"pong",strlen("pong"));
        close(pipe_child[1]);    
        exit(0);  
        


    }else {
        // parent process

        // write to parent's pipe[1]
        close(pipe_parent[0]);
        write(pipe_parent[1],"ping",strlen("ping"));
        close(pipe_parent[1]);
        wait((int*)0);

        // read child's pipe[0]
        close(pipe_child[1]);
        read(pipe_child[0],buf,5);
        int parent_pid = getpid();
        printf("parent <%d> received %s\n",parent_pid,buf);
        close(pipe_child[0]);
        exit(0);
       

    }

    return 0;

}