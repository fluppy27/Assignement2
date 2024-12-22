#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>


int main(){

int n = 0;

printf("please enter your number\n");
scanf("%d", &n);
printf("thank you, you entered %d\n", n);

int pid = fork;
int status;

    if(pid == 0){
        while( n !=1){
            if(n%2 ==0){
                n = n/2;
            }
            else{
                n = (3*n)+1;
            }
        }

    }
    else if(pid != 0){
        waitpid(pid, &status, 0);
        printf("process complete\n");
    }

    return 0;
}