/*
    Algorithm: Main function
    Members:
        - Santiago Collantes Zuluaga
        - Kevin Steven Ocampo M.
*/
#include<bits/stdc++.h>
#include <thread>
#include "priority.h"
#include "fcfs.h"
#include "sjf.h"
#include "roundRobin.h"
#include "priority_roundRobin.h"
using namespace std;

/*void printMenu(){
    cout << "\nProyecto Sisoper 2021-1" << endl;
    cout << "Opciones." << endl;
    cout << "1) Ejcutar algoritmos" << endl;
    cout << "2) Mostrar reporte" << endl;
    cout << "0) Salir" << endl;
}

void printAlgorithms(){
    cout << "\nAlgoritmos de Scheduling" << endl;
    cout << "Opciones." << endl;
    cout << "1) Priority Scheduling" << endl;
    cout << "2) FCFS Scheduling" << endl;
    cout << "3) SJF Scheduling" << endl;
    cout << "4) Round Robin Scheduling" << endl;
    cout << "5) Priority Round Robin Scheduling" << endl;
}*/

int main(){
    //The excute for all algorithms of scheduling will be through
    //threads, as they will run in parallel.
    /*vector<string> algorithms = {"priority","fcfs","sjf","round robin","priority round robin"};
    string tmp;
    int opc, n;
    vector<int> exec;

    while(true){
        printMenu();
        cout << "Elija una opcion: "; cin >> opc;
        if(opc == 1){
            printAlgorithms();
            cout << "Escriba los numeros de los algoritmos(Espacios intermedios): ";
            cin.ignore();
            getline(cin, tmp);
            istringstream isstream(tmp);
            string aux;
            while(isstream >> aux){
                if(stoi(aux) >= 1 && stoi(aux) <= 5)
                    exec.push_back(stoi(aux));
            }
            cout << "Digite la cantidad de procesos a crear: "; cin >> n;
            for(int j = 0; j < exec.size(); j++){
                for(int k = 1; k <= n; k++){
                    if(algorithms[exec[j]] == "priority"){
                        cout << "Digite el BT: ";  
                    }
                    else if(algorithms[exec[j]] == "fcfs"){

                    }
                    else if(algorithms[exec[j]] == "sjf"){

                    }
                    else if(algorithms[exec[j]] == "round robin"){

                    }
                    else if(algorithms[exec[j]] == "priority round robin"){

                    }
                }
            }
            
            for(int i = 0; i < exec.size(); i++){
                thread t1(algorithms[exec[i]-1], proc1, N1);
                t1.join();
            }
        }
        else if(opc == 2){
            cout << "Opcion 2." << endl;
        }
        else if(opc == 0){
            break;
        }
        else{
            cout << "Opcion no valida." << endl;
        }
    }*/
    

    //Priority Example
    cout << "PRIORITY EXAMPLE" << endl;
    process1 proc1[] = {{5, 11, 7}, {4, 6, 9}, {3, 4, 10}, {2, 3, 5}, {1, 1, 8}};
    int N1 = sizeof proc1 / sizeof proc1[0];
    thread t1(priorityScheduling, proc1, N1); //Algorithm Priority is launched

    t1.join(); //Wait for thread t1 to finish

    //FCFS Example
    cout << "\n\nFCFS EXAMPLE" << endl;
    process2 proc2[] = {{5, 11, 7}, {4, 6, 9}, {3, 4, 10}, {2, 3, 5}, {1, 0, 8}};
    int N2 = sizeof proc2/sizeof proc2[0];
    thread t2(fcfsScheduling, proc2, N2); //Algorithm FCFS is launched

    t2.join(); //Wait for thread t2 to finish

    //SJF Example
    cout << "SJF EXAMPLE" << endl;
    process3 proc3[] = {{5, 11, 7}, {4, 6, 9}, {3, 4, 10}, {2, 3, 5}, {1, 0, 8}};
    int N3 = sizeof proc3/sizeof proc3[0];
    thread t3(sjfScheduling, proc3, N3); //Algorithm SJF is launched

    t3.join(); //Wait for thread t3 to finish

    //Round Robin Example
    cout << "ROUND ROBIN EXAMPLE" << endl;
    process4 proc4[] = {{1, 10}, {2, 5}, {3, 8}};
    int N4 = sizeof proc4 / sizeof proc4[0];
    int qt = 2;
    thread t4(roundRobin, proc4, N4, qt); //Algorithm Round Robin is launched

    t4.join(); //Wait for thread t3 to finish

    //Priority Round Robin Example
    cout << "\n\nPRIORITY ROUND ROBIN EXAMPLE" << endl;
    process5 proc5[] = {{1, 10, 2}, {2, 3, 3}, {3, 2, 1}};
    int N5 = sizeof proc5 / sizeof proc5[0];
    int qt2 = 4;
    thread t5(priorityRoundRobin, proc5, N5, qt2); //Algorithm Priority Round Robin is launched

    t5.join(); //Wait for thread t4 to finish

    /*t1.join(); //Wait for thread t1 to finish
    t2.join(); //Wait for thread t2 to finish
    t3.join(); //Wait for thread t3 to finish*/

    return 0;
}