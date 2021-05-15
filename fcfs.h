//First Come, First Served (FCFS)
//Creditos a GeekforGeeks, disponible en: https://www.geeksforgeeks.org/first-come-first-serve-cpu-scheduling-non-preemptive/
#include<bits/stdc++.h>
using namespace std;
  
struct process2{
    int pid; //ID process
    int at; //Arrival Time
    int bt; //Burst Time
};

// Function to sort the process to AT
bool comparison2(process2 a, process2 b){
    return (a.at < b.at);
}

// Function to calculate turn around time
void turnAroundTime(process2 proc[], int N, int wt[], int tat[]){
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int  i = 0; i < N ; i++)
        tat[i] = proc[i].bt + wt[i];
}

// Function to find the waiting time for all processes
void waitingTime(process2 proc[], int N, int wt[]){
    // Waiting time for first process is 0
    wt[0] = 0;
  
    // Calculating waiting time for each process from the given
    // formula
    for (int i = 1; i < N; i++)
        wt[i] = (proc[i - 1].at + proc[i - 1].bt + wt[i - 1]) - proc[i].at;
}

// Function to Calculate waiting time and average waiting time
void fcfsScheduling(process2 proc[], int N){
    //Sorted process by Arrival time
    sort(proc, proc + N, comparison2);

    // Declare auxiliar variables
    int wt[N], tat[N], total_wt = 0, total_tat = 0;

    //Calculate Waiting Time
    waitingTime(proc,N,wt);
  
    //Calculate TurnAround Time
    turnAroundTime(proc, N, wt, tat);

    //Display processes along with all details
    cout << "\nProcesses  "<< " BT  "
         << " WT/RT  " << " TAT\n";
 
    // Calculate total waiting time and total turn around time
    for (int  i=0; i<N; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].pid << "\t\t  "
             << proc[i].bt << "\t    " << wt[i]
             << "\t " << tat[i] <<endl;
    }
 
    cout << "\nAverage waiting time = " << (float)total_wt / (float)N;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)N;
}