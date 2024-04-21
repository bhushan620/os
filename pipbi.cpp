#include<bits/stdc++.h>
#include<sys/wait.h>

using namespace std;
int main(){
    pid_t child;
    int fd[2];
    int fe[2];
    char buffer[2][100];
    char buf2[100];
    
    if(pipe(fd)<0){
        cerr<<"pipe leaked";
        return 1;
    }
    if(pipe(fe)<0){
        cerr<<"pipe leaked";
        return 1;
    }

    child = fork();

    if(child<0){
        cerr<<"child failed";
        return 1;
    }
    else if(child!=0){
        // close(fd[0]);
        const char msg[100] = "Bhushan";
         write(fd[1],msg,100);

        cout<<"\nParent sent:"<<msg;

        wait(NULL);

        read(fe[0],buffer[1],100);

        cout<<"\nParent process recieved1: "<<buffer[1]<<endl;

    }
    else {
        //child process
        
        read(fd[0],buffer[1],100);
        cout<<"Child process recieved1: "<<buffer[1]<<endl;
        
        const char msg[100] = "Pisal";
         write(fe[1],msg,100);
        cout<<"Child sent: "<<msg<<endl;
    }
    

    return 0;
}