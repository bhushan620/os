#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int ch;
    printf("The parent process ID is %d\n", getpid());

    printf("\nEnter 1 to create a split process using fork() : ");
    printf("\nEnter 2 to create a split process using fork() with priority execution : ");
    printf("\nEnter 3 to implement exec() : ");
    printf("\nEnter 4 to implement copy command: ");
    printf("\nEnter 5 to implement search pattern: ");
    printf("\nEnter 6 to implement exit\n");
    
    printf("enter your choice = ");
    scanf("%d",&ch);
    
    
    
    switch(ch){
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
            printf("\nYou are in the original file\n");
            break;
        }

    	case 4:
    		copyfile();
    		break;

    	case 5:
			searchpattern();
			break;

		case 6:
			printf("= = exiting = =");
			break;

		default:
			printf("enter valid number\n");		
	}
	return 0;
	
}

void copyfile(){
	pid_t pid = fork();
	if(pid < 0){
		printf("fork failed");
	}
	else if(pid == 0){
		char *args[] = {"cp" , "source.txt" , "dest.txt" , NULL};
		execvp("cp",args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else{
	    wait(NULL);
	    printf("file copied");
	}
	
}
void searchpattern(){
	char pattern[256];
	printf("enter pattern to search = ");
	scanf("%255s",pattern);
	
	pid_t pid = fork();
    
	if(pid < 0){
		printf("fork failed");
	}
	else if(pid == 0){
		char *args[] = {"grep" , pattern , "source.txt" , NULL};
		execvp("grep",args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else{
	    wait(NULL);
	    printf("pattern searched");
	}
	
}



// #include<stdio.h>

// int main()
// {
//   printf("\nThe execvp() system calls has redirected us to the another C file");
//   printf("\n-------We are in the exec.c file-------\n");
//   return 0;
// }
