#include<bits/stdc++.h>
#include <thread>
#include "priority.h"
#include "fcfs.h"
#include "sjf.h"
using namespace std;

int main(){
    process1 proc[] = {{5, 11, 7}, {4, 6, 9}, {3, 4, 10}, {2, 3, 5}, {1, 1, 8}};
    int n = sizeof proc / sizeof proc[0];
    priorityScheduling(proc, n);
    /*
    //Priority Example
    process1 proc1[] = {{5, 11, 7}, {4, 6, 9}, {3, 4, 10}, {2, 3, 5}, {1, 1, 8}};
    int N1 = sizeof proc1 / sizeof proc1[0];
    thread t1(priorityScheduling, proc1, N1); //Algorithm Priority is launched

    //FCFS Example
    process2 proc2[] = {{5, 11, 7}, {4, 6, 9}, {3, 4, 10}, {2, 3, 5}, {1, 0, 8}};
    int N2 = sizeof proc2/sizeof proc2[0];
    thread t2(fcfsScheduling, proc2, N2); //Algorithm FCFS is launched

    //SJF Example
    process3 proc3[] = {{5, 11, 7}, {4, 6, 9}, {3, 4, 10}, {2, 3, 5}, {1, 0, 8}};
    int N3 = sizeof proc3/sizeof proc3[0];
    thread t3(sjfScheduling, proc3, N3); //Algorithm SJF is launched

    t1.join() //Wait for thread t1 to finish
    t2.join() //Wait for thread t2 to finish
    t3.join() //Wait for thread t3 to finish*/

    return 0;
}