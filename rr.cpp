
#include<iostream>
#include<algorithm>
using namespace std;

struct Process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int arrival_time;
};

void findWaitingTime(Process processes[], int n, int quantum , int min) {
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = processes[i].burst_time;

    int t =min;

    while (true) {
        bool done = true;

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && processes[i].arrival_time <= t) {
                done = false;

                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    processes[i].waiting_time = t - processes[i].burst_time - processes[i].arrival_time;
                    rem_bt[i] = 0;
                }
            }
        }

        if (done)
            break;
    }
}

void findTurnAroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++)
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
}

void findavgTime(Process processes[], int n, int quantum,int min) {
    int total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, quantum , min);
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
    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Process " << i + 1 << " (Arrival Time Burst Time): ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
    }

    int quantum;
    cout << "Enter time quantum: ";
    cin >> quantum;

    int min=processes[0].arrival_time;
    for (int i = 1; i < n; i++) {
        if(processes[i].arrival_time<min)
        {
            min=processes[i].arrival_time;
        }
    }

    findavgTime(processes, n, quantum,min);

    return 0;
}
