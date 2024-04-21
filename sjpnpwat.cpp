
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
    int currentTime = 0;

    for (auto& process : processes) {
        if (process.arrival_time > currentTime) {
            currentTime = process.arrival_time;
        }
        process.waiting_time = currentTime - process.arrival_time;
        currentTime += process.burst_time;
        process.turnaround_time = process.waiting_time + process.burst_time;
    }
}

void displayResults(const vector<Process>& processes) {
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;

    cout << "Process\t\tArrival Time\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\n";
    for (const auto& process : processes) {
        cout << process.process_id << "\t\t\t" << process.arrival_time << "\t\t\t\t"
             << process.burst_time << "\t\t\t" << process.waiting_time << "\t\t\t"
             << process.turnaround_time << endl;

        totalWaitingTime += process.waiting_time;
        totalTurnaroundTime += process.turnaround_time;
    }

    float averageWaitingTime = totalWaitingTime / processes.size();
    float averageTurnaroundTime = totalTurnaroundTime / processes.size();

    cout << "\nAverage Waiting Time: " << averageWaitingTime << endl;
    cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;
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

    // Calculate waiting time and turnaround time
    calculateWaitingTime(processes);

    // Display results
    displayResults(processes);

    return 0;
}
