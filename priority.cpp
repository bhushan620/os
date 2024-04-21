#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

struct Process {
    int id;
    int burst_time;
    int waiting_time;
    int priority;
    int turnaround_time;
    int arrival_time;
};

void findWaitingTime(Process processes[], int n , int min ) {
    int rem_bt[n];
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = processes[i].burst_time;
        visited[i] = 0;
    }
    int t = min ;
    int sum=0;
    while(accumulate(rem_bt,rem_bt+n,sum)!=0)
    {
        int max=__INT32_MAX__;
        int index;
        int flag=0;
        for(int i=0 ;i<n;i++){
            if(processes[i].arrival_time<=t && visited[i]==0 && processes[i].priority<max)
            {
                max=processes[i].priority;
                index=i;
                flag=1;
            }
        }
        if(flag)
        {
            visited[index]=1;
            rem_bt[index]=0;
            cout<<"Process"<<index+1<<"got executed from"<<t<<"to"<<t+processes[index].burst_time<<endl;
            t+=processes[index].burst_time;
            processes[index].waiting_time= t- processes[index].arrival_time - processes[index].burst_time;
        }
        else{
                t++;
        }
    }


    
}

void findTurnAroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++)
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
}

void findavgTime(Process processes[], int n,int min) {
    int total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n ,min);
    findTurnAroundTime(processes, n);

    cout << "PN\tBT\tAT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {
        total_wt += processes[i].waiting_time;
        total_tat += processes[i].turnaround_time;
        cout << processes[i].id << "\t" << processes[i].burst_time << "\t"
             << processes[i].arrival_time << "\t" << processes[i].waiting_time << "\t"
             << processes[i].turnaround_time << endl;
    }

    cout << "Average waiting time = " << (float)total_wt / n;
    cout << "\nAverage turn around time = " << (float)total_tat / n;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];
    cout << "Enter arrival time, burst time & priority for each process:\n";
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Process " << i + 1 << " (Arrival Time Burst Time Priority): ";
        cin >> processes[i].arrival_time >> processes[i].burst_time>>processes[i].priority;
    }

    int min=processes[0].arrival_time;
    for (int i = 1; i < n; i++) {
        if(processes[i].arrival_time<min)
        {
            min=processes[i].arrival_time;
        }
    }

    findavgTime(processes, n, min);

    return 0;
}
