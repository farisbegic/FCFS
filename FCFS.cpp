#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    // number of processes
    int n;

    // dynamic allocation of arrays
    int *burstTime = new int[n];
    int *waitingTime = new int[n];
    int *turnAroundTime = new int[n];

    // Average times to be initialized later
    double waitingAvg;
    double turnAroundTimeAvg;

    cout << "This program works only with integers" << endl;

    cout << "Enter the number of processes: ";
    cin >> n;

    // Loop for receiving the data (burst time) of each process
    // Array index represents the number of process, value on that index represents its burst time
    for (int i=0 ; i<n ; i++){
        cout << "Enter the burst time for each process [" << i+1 << "]:";
        cin >> burstTime[i];
    }

    // burstTime[1] = 5;

    // Waiting time for the first process is always 0, and along the way we initialize waiting time average to 0
    waitingTime[0] = waitingAvg = 0;

    // Turnaround time of the first process is its own burst time, also we set average turnaround time to the turnaround time of the first process
    turnAroundTime[0] = turnAroundTimeAvg = burstTime[0];

    for(int i=1 ; i<n ; i++){

        // Turnaround time of process i is equal to turnaround time of the process before + itw own burst time
        turnAroundTime[i] = turnAroundTime[i-1] + burstTime[i];

        // Waiting time if process i is equal to the sum if waiting and burst time of the previous process
        waitingTime[i] = waitingTime[i-1] + burstTime[i-1];

        // Simply adding times to avg variables that are going to be divided by the number of processes later
        waitingAvg += waitingTime[i];
        turnAroundTimeAvg += turnAroundTime[i];
    }

    // DISPLAY TABLE

    cout << "Process" << "\t\t" << "Burst Time" << "\t\t" << "Waiting Time" << "\t\t" << "Turnaround Time" << endl;

    for (int i=0 ; i<n ; i++){
        cout << "P" << i+1 << setw(17) << burstTime[i] << setw(24) << waitingTime[i] << setw(24) << turnAroundTime[i] << endl;
    }

    cout << endl;

    cout << "Average Turnaround Time is: " << turnAroundTimeAvg / n << endl;
    cout << "Average Waiting time is: " << waitingAvg / n << endl;

    // DISPLAY GANT CHART

    for (int i=0 ; i<=(turnAroundTime[n-1]*2) + n ; i++){
        cout << "-";
    }
    cout << endl;

    for (int i=0 ; i<n ; i++){
        cout << "|" << setw(burstTime[i]) << "P" << i+1 << setw(burstTime[i]);
    }
    cout << "|" << endl;

    for (int i=0 ; i<=(turnAroundTime[n-1]*2) + n ; i++){
        cout << "-";
    }
    cout << endl << "0";

    for (int i=0 ; i<n ; i++){
        cout << setw(burstTime[i]*2 + 1) << turnAroundTime[i];
    }

    delete[] burstTime;
    delete[] waitingTime;
    delete[] turnAroundTime;

    return 0;
}
