//Priority Schedulling
//Creditos a GeekforGeeks, disponible en: https://www.geeksforgeeks.org/program-for-priority-cpu-scheduling-set-1/
#include<bits/stdc++.h>
using namespace std;

struct process1{
    int pid;  // process ID
    int bt;   // CPU Burst time required
    int priority; // Priority of this process
};
 
// Function to sort the process1 acc. to priority
bool comparison(process1 a, process1 b){
    return (a.priority > b.priority);
}
 
// Function to find the waiting time for all processes
void findWaitingTime(process1 proc[], int N, int wt[]){
    // waiting time for first process is 0
    wt[0] = 0;
 
    // calculating waiting time
    for (int  i = 1; i < N ; i++ )
        wt[i] =  proc[i-1].bt + wt[i-1];
}
 
// Function to calculate turn around time
void findTurnAroundTime( process1 proc[], int N, int wt[], int tat[]){
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int  i = 0; i < N ; i++)
        tat[i] = proc[i].bt + wt[i];
}
 
//Function to calculate average time
void priorityScheduling(process1 proc[], int N){
    // Sort processes by priority
    sort(proc, proc + N, comparison);

    int wt[N], tat[N], total_wt = 0, total_tat = 0;
 
    //Function to find waiting time of all processes
    findWaitingTime(proc, N, wt);
 
    //Function to find turn around time for all processes
    findTurnAroundTime(proc, N, wt, tat);
 
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