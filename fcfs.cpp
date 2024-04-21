#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

bool compareByArrivalTime(const Process& a, const Process& b) {
    return a.arrival_time < b.arrival_time;
}

void calculateWaitingTime(vector<Process>& processes) {
    int current_time = 0;

    for (auto& process : processes) {
        if (process.arrival_time > current_time) {
            current_time = process.arrival_time;
        }
        process.waiting_time = current_time - process.arrival_time;
        current_time += process.burst_time;
        process.turnaround_time = process.waiting_time + process.burst_time;
    }
    }

void calculateTurnaroundTime(vector<Process>& processes) {
    for (auto& process : processes) {
        process.turnaround_time = process.waiting_time + process.burst_time;
    }
}

void displayResults(const vector<Process>& processes) {
    float total_waiting_time = 0;
    float total_turnaround_time = 0;

    cout << "Process\t  Arrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (const auto& process : processes) {
        cout << process.process_id << "\t\t" << process.arrival_time << "\t\t"
             << process.burst_time << "\t\t" << process.waiting_time << "\t\t"
             << process.turnaround_time << endl;

        total_waiting_time += process.waiting_time;
        total_turnaround_time += process.turnaround_time;
    }

    float average_waiting_time = total_waiting_time / processes.size();
    float average_turnaround_time = total_turnaround_time / processes.size();

    cout << "\nAverage Waiting Time: " << average_waiting_time << endl;
    cout << "Average Turnaround Time: " << average_turnaround_time << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Process Pid: ";
        cin >> processes[i].process_id;
        cout << "Process " << processes[i].process_id << " Arrival Time: ";
        cin >> processes[i].arrival_time;
        cout << "Process " << processes[i].process_id << " Burst Time: ";
        cin >> processes[i].burst_time;
        
       
    }

    // Sort processes based on arrival time
    sort(processes.begin(), processes.end(), compareByArrivalTime);
   

    // Calculate waiting time
    calculateWaitingTime(processes);

    // Calculate turnaround time
    calculateTurnaroundTime(processes);

    // Display results
    displayResults(processes);

    return 0;
}
