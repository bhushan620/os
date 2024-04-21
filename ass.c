#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    printf("__________ OSL Assignment 1 ______________\n");
    printf("The parent process ID is %d\n", getpid());

    printf("\nEnter 1 to create a split process using fork() : ");
    printf("\nEnter 2 to create a split process using fork() with priority execution : ");
    printf("\nEnter 3 to implement exec() : \n");

    int userChoice;
    scanf("%d", &userChoice);

    switch (userChoice) {
        case 1: {
            pid_t childPID = fork();
            if (childPID == 0) {
                printf("We are in the child process. PID = %d \n", getpid());
            } else if (childPID > 0) {
                printf("We are in the parent process. PID = %d \n", getpid());
            } else {
                printf("Error spliting the child process");
            }
            break;
        }

        case 2: {
            pid_t childPID = fork();
            if (childPID == 0) {
                printf("We are in the child process. PID = %d \n", getpid());
            } else if (childPID > 0) {
                printf("We are in the parent process. PID = %d \n", getpid());
                wait(NULL);
                printf("Child process must be terminated");
            } else {
                printf("Error spliting the child process");
            }
            break;
        }

        case 3: {
            char *args[] = {"./exec", NULL};
            execvp(args[0], args);
            break;
        }
  
    }

    printf("\nYou are in the original file\n");

    return 0;
}


// exec.c
// #include<stdio.h>

// int main()
// {
//   printf("\nThe execvp() system calls has redirected us to the another C file");
//   printf("\n-------We are in the exec.c file-------\n");
// }