#include <signal.h>
#include <stdio.h>
void sigint_handler(int signo){
    printf("process id : %ld\n", (long)getpid());
    printf("Ctrl-C\n");
}
int main(void)
{
    printf("signal INT\n");
    printf("signal getpid\n");
    signal(SIGINT, sigint_handler);
    while(1)
        ;
    return 0;
}     
