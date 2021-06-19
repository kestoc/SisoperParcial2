/*
    Algorithm: Priority Scheduling
    Members:
        - Santiago Collantes Zuluaga
        - Kevin Steven Ocampo M.
    Creditos a GeekforGeeks, disponible en: https://www.geeksforgeeks.org/program-round-robin-scheduling-set-1/
*/
#include<bits/stdc++.h>
#include <thread>
using namespace std;

struct process4{
    int pid; //ID process
    int bt; //Burst Time
};

// Function to find the waiting time for all proc
void findWaitingTime(process4 proc[], int n, int wt[], int quantum){
	// Make a copy of burst times bt[] to store remaining burst times.
	int rem_bt[n];
	for (int i = 0 ; i < n ; i++)
		rem_bt[i] = proc[i].bt;

	int t = 0; // Current time

	// Keep traversing proc in round robin manner until all of them are not done.
	while (1){
		bool done = true;

		// Traverse all proc one by one repeatedly
		for (int i = 0 ; i < n; i++){
			// If burst time of a process is greater than 0
			// then only need to process further
			if (rem_bt[i] > 0){
				done = false; // There is a pending process

				if (rem_bt[i] > quantum){
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t += quantum;

					// Decrease the burst_time of current process
					// by quantum
					rem_bt[i] -= quantum;
				}

				// If burst time is smaller than or equal to
				// quantum. Last cycle for this process
				else{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t = t + rem_bt[i];

					// Waiting time is current time minus time
					// used by this process
					wt[i] = t - proc[i].bt;

					// As the process gets fully executed
					// make its remaining burst time = 0
					rem_bt[i] = 0;
				}
			}
		}
		// If all proc are done
		if (done == true)
            break;
	}
}

// Function to calculate turn around time
void findTurnAroundTime(process4 proc[], int n, int wt[], int tat[]){
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n ; i++)
		tat[i] = proc[i].bt + wt[i];
}

// Function to calculate average time
void roundRobin(process4 proc[], int n, int quantum){
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	// Function to find waiting time of all proc
	findWaitingTime(proc, n, wt, quantum);

	// Function to find turn around time for all proc
	findTurnAroundTime(proc, n, wt, tat);

	//Display proc along with all details
    cout << "\nProcesses  "<< " BT  "
         << " WT/RT  " << " TAT\n";

	// Calculate total waiting time and total turn around time
    for (int  i=0; i<n; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   P" << proc[i].pid << "\t\t   "
             << proc[i].bt << "\t\t" << wt[i]
             << "\t\t  " << tat[i] <<endl;
    }
 
    cout << "\nAverage WT Priority = " << (float)total_wt / (float)n;
    cout << "\nAverage TAT Priority = " << (float)total_tat / (float)n;
}
