//Shortest Job First (SJF)
#include<bits/stdc++.h>
using namespace std;

struct process3{
    int pid; //ID process
    int at; //Arrival Time
    int bt; //Burst Time
};

// Function to sort the process to AT
bool comparison3(process3 a, process3 b){
    return (a.at < b.at);
}

// Function to sort the process to BT
bool comparison4(process3 a, process3 b){
    return (a.bt < b.bt);
}

// Function to calculate turn around time
void turnAroundTime(process3 proc[], int N, int wt[], int tat[]){
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int  i = 0; i < N ; i++)
        tat[i] = proc[i].bt + wt[i];
}

// Function to find the waiting time for all processes
void waitingTime(process3 proc[], int N, int wt[]){
    // Waiting time for first process is 0
    wt[0] = 0;
  
    // Calculating waiting time for each process from the given
    // formula
    for (int i = 1; i < N; i++)
        wt[i] = (proc[i - 1].at + proc[i - 1].bt + wt[i - 1]) - proc[i].at;
}

// Function to display Gantt Chart
void dispGanttChart3(process3 proc[],int N, int wt[])
{
    int temp, prev = 0;
    process3* spaces = proc;
    cout << "\n\nGantt Chart (IS indicates ideal state) :- \n\n+";

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
        cout << (string(to_string(spaces[i].pid).length()
                            + (spaces[i].pid != -1)
                            + 2 * spaces[i].bt,
                        ' '))
             << spaces[i].at + spaces[i].bt + wt[i];
    }
    cout << "\n\n";
}

// Function to Calculate waiting time and average waiting time
void sjfScheduling(process3 proc[], int N){
    //Sorted process by Arrival time
    sort(proc, proc + N, comparison3);
    //Sorted process by Burst time
    sort(proc + 1, proc + N, comparison4);

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
        cout << "   " << proc[i].pid << "\t\t   "
             << proc[i].bt << "\t   " << wt[i]
             << "\t    " << tat[i] <<endl;
    }
 
    cout << "\nAverage waiting time = " << (float)total_wt / (float)N;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)N;

    //Gantt Chart
    dispGanttChart3(proc,N,wt);
}