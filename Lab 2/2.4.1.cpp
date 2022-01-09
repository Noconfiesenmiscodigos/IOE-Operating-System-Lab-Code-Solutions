/*
Round Robin is a CPU scheduling algorithm where each process is assigned a fixed time slot in a cyclic way.

It is simple, easy to implement, and starvation-free as all processes get fair share of CPU.
One of the most commonly used technique in CPU scheduling as a core.
It is preemptive as processes are assigned CPU only for a fixed slice of time at most.
The disadvantage of it is more overhead of context switching.
*/
/*Round Robin Scheduling*/
// Program implementation in C++ for Round Robin scheduling
#include<iostream>
using namespace std;
//The Function to find the waiting time for all processes
void fWaitingTime(int processes[], int n,
                  int bt[], int wt[], int quantum)
{
    // Let us Make a copy of burst times bt[] to store remaining burst times

    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] = bt[i];

    int t = 0; // for Current time

    // Let us keep traverse the processes in the round robin manner until all of them are not done.

    while (1)
    {
        bool done = true;

        //let us Traverse all processes one by one repeatedly
        for (int i = 0 ; i < n; i++)
        {
            // If burst time of a process is greater than 0 then there is a need to process further
            if (rem_bt[i] > 0)
            {
                done = false; // indicates there is a pending process

                if (rem_bt[i] > quantum)
                {
                    // By Increasing the value of t it shows how much time a process has been processed
                    t += quantum;

                    // Decreasing the burst_time of current process by the quantum
                    rem_bt[i] -= quantum;
                }

                // If burst time is smaller than or equal to the quantum then it is Last cycle for this process
                else
                {
                    // Increase the value of t to show how much time a process has been processed
                    t = t + rem_bt[i];

                    // Waiting time is current time minus time used by this process.
                    wt[i] = t - bt[i];

                    // As the process gets fully executed thus remaining burst time becomes 0.

                    rem_bt[i] = 0;
                }
            }
        }

        // If all the processes are done
        if (done == true)
            break;
    }
}

// Function used to calculate the turn around time
void fTurnAroundTime(int processes[], int n,
                     int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate the average time
void findavgTime(int processes[], int n, int bt[],
                 int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    fWaitingTime(processes, n, bt, wt, quantum);

    // Function to find turn around time for all processes
    fTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with all details
    cout << "Processes "<< " Burst time "
         << " Waiting time " << " Turn around time\n";

    // Calculate the total waiting time and total turn
    // around time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
             << wt[i] <<"\t\t " << tat[i] <<endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

//Given below is the Driver Code
int main()
{
    // process id's
    int processes[] = { 1, 2, 3,4};
    int x = sizeof processes / sizeof processes[0];

    // Burst time of all processes
    int burst_time[] = {21, 13, 6,12};

    // Time quantum
    int quantum = 2;
    findavgTime(processes, x, burst_time, quantum);
    return 0;
}
/*
Processes  Burst time  Waiting time  Turn around time
 1              21       31              52
 2              13       32              45
 3              6        16              22
 4              12       30              42
Average waiting time = 27.25
Average turn around time = 40.25
*/
