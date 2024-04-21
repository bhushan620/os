#include <iostream>
using namespace std;

void nextFit(int blockSize[], int m, int processSize[], int n);
void printfun(int visited[] , int n, int processSize[]);
int main()
{
int m; 
int n; 
int blockSize[] = {100, 500, 200, 300, 600};
int processSize[] = {212, 417, 112, 426};
m = sizeof(blockSize) / sizeof(blockSize[0]);
n = sizeof(processSize) / sizeof(processSize[0]);

nextFit(blockSize, m, processSize, n);

return 0 ;
}

void nextFit(int blockSize[], int m, int processSize[], int n)
{
    int last_allocated=0;
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=-1;
    }

    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            if(blockSize[last_allocated]>=processSize[j])
            {
                visited[j]=last_allocated;
                blockSize[last_allocated]-=processSize[j];
                break;
            }
            last_allocated=(last_allocated+1)%m;
        }  
    }

    printfun(visited,n,processSize);
}

void printfun(int visited[] , int n, int processSize[]){
    cout<<"\nProcess No.\tProcess Size\tBlock no.\n";
    for(int i=0;i<n;i++){
        
        if(visited[i]==-1){
        cout<<i+1<<"\t\t"<<processSize[i]<<"\t\t"<<"Not allocated\n";
        }
        else
        cout<<i+1<<"\t\t"<<processSize[i]<<"\t\t"<<visited[i]+1<<"\n";
    }
}

