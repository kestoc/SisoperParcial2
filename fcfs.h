/*
    Algorithm: First Come, First Served (FCFS)
    Members:
        - Santiago Collantes Zuluaga
        - Kevin Steven Ocampo M.
*/
#include<bits/stdc++.h>
#include <thread>
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

// Function to display Gantt Chart
void dispGanttChart2(process2 proc[],int N, int wt[])
{
    int temp, prev = 0;
    process2* spaces = proc;
    cout << "\n\nGantt Chart FCFS :- \n\n+";

    // For 1st row of gantt chart
    for(int i = 0; i < N; i++) {
        cout << string(to_string(spaces[i].pid).length()
                           + (spaces[i].pid != -1)
                           + 2 * spaces[i].bt,
                       '-')
             << "+";
    }
    cout << "\n|";

    // For process no. in 2nd row
   for(int i = 0; i < N; i++) {
        cout << string(spaces[i].bt, ' ');
        if (spaces[i].pid == -1)
            cout << "IS" << string(spaces[i].bt, ' ') << '|';
        else
            cout << "P" << spaces[i].pid
                 << string(spaces[i].bt, ' ') << '|';
    }
    cout << "\n+";

    for(int i = 0; i < N; i++) {
        cout << (string(to_string(spaces[i].pid).length()
                            + (spaces[i].pid != -1)
                            + 2 * spaces[i].bt,
                        '-'))
             << "+";
    }
    cout << "\n0";
//For 3rd row of gantt chart
    for(int i = 0; i < N; i++) {
        if(spaces[i].at + spaces[i].bt + wt[i] >= 10){
            cout << (string(to_string(spaces[i].pid).length()
                            + (spaces[i].pid != -1)
                            + 2 * spaces[i].bt - 1,
                        ' '))
            << spaces[i].at + spaces[i].bt + wt[i];
        }
        else {
            cout <<(string(to_string(spaces[i].pid).length()
                            + (spaces[i].pid != -1)
                            + 2 * spaces[i].bt,
                        ' '))
             << spaces[i].at + spaces[i].bt + wt[i];
        }
    }
    cout << "\n\n";
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
        cout << "   P" << proc[i].pid << "\t\t   "
             << proc[i].bt << "\t\t" << wt[i]
             << "\t\t  " << tat[i] <<endl;
    }
 
    cout << "\nAverage WT FCFS = " << (float)total_wt / (float)N;
    cout << "\nAverage TAT FCFS = " << (float)total_tat / (float)N;

    //Gantt Chart
    dispGanttChart2(proc,N,wt);
}