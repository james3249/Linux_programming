#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void sigint_handler(int signo){
    printf("Ctrl-C\n");
    pid_t childpid;
    printf("process id : %ld\n", (long)getpid());
    childpid = fork();
   if( childpid == -1)
       perror("Failed to fork\n");
   else if ( childpid ==0 )
       printf("child, pid:%ld ppid:%ld\n",
              (long)getpid(), (long)getppid());
   else
       printf("parent, pid:%ld ppid:%ld\n",
              (long)getpid(), (long)getppid());

}
int main(void)
{
   pid_t childpid;
    signal(SIGINT, sigint_handler);
    while(1)
        ;
    return 0;
}     
