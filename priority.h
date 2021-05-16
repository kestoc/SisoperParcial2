/*
    Algorithm: Priority Scheduling
    Members:
        - Santiago Collantes Zuluaga
        - Kevin Steven Ocampo M.
    Creditos a GeekforGeeks, disponible en: https://www.geeksforgeeks.org/program-for-priority-cpu-scheduling-set-1/
*/
#include<bits/stdc++.h>
#include <thread>
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

void dispGanttChart1(process1 proc[],int N, int wt[])
{
    int temp, prev = 0;
    process1* spaces = proc;
    cout << "\n\nGantt Chart Priority :- \n\n+";

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
    int ct = 0; 
    //For 3rd row of gantt chart
    for(int i = 0; i < N; i++) {
        if(ct >= 10){
            cout<< (string(to_string(spaces[i].pid).length()
                            + (spaces[i].pid != -1)
                            + 2 * spaces[i].bt - 1,
                        ' '))
             << ct + spaces[i].bt;
        }
        else{
            cout<< (string(to_string(spaces[i].pid).length()
                            + (spaces[i].pid != -1)
                            + 2 * spaces[i].bt,
                        ' '))
             << ct + spaces[i].bt;
        }
        ct += spaces[i].bt;
    }
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
        cout << "   P" << proc[i].pid << "\t\t   "
             << proc[i].bt << "\t\t" << wt[i]
             << "\t\t  " << tat[i] <<endl;
    }
 
    cout << "\nAverage WT Priority = " << (float)total_wt / (float)N;
    cout << "\nAverage TAT Priority = " << (float)total_tat / (float)N;

    //Gantt Chart
    dispGanttChart1(proc,N,wt);
}