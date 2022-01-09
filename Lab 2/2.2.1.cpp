/*
Shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with
the smallest execution time to execute next. SJN is a non-preemptive algorithm.

Shortest Job first has the advantage of having a minimum average waiting time among all scheduling algorithms.
It is a Greedy Algorithm.
It may cause starvation if shorter processes keep coming. This problem can be solved using the concept of ageing.
It is practically infeasible as Operating System may not know burst time and therefore may not sort them.
While it is not possible to predict execution time, several methods can be used to estimate the execution time
for a job, such as a weighted average of previous execution times. SJF can be used in specialized environments where
accurate estimates of running time are available.

Completion Time: Time at which process completes its execution.
Turn Around Time: Time Difference between completion time and arrival time. Turn Around Time = Completion Time – Arrival Time
Waiting Time(W.T): Time Difference between turn around time and burst time.
Waiting Time = Turn Around Time – Burst Time
*/
/*Shortest-Job-First (SJF) Scheduling*/
#include<iostream>
using namespace std;
int main()
{
    int n,temp,tt=0,min,d,i,j;
    float atat=0,awt=0,stat=0,swt=0;
    cout<<"enter no of process"<<endl;
    cin>>n;
    int a[n],b[n],e[n],tat[n],wt[n];
    for(i=0; i<n; i++)
    {
        cout<<"enter arival time ";       //input
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        cout<<"enter brust time ";      //input
        cin>>b[i];
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(b[i]>b[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;

                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    min=a[0];
    for(i=0; i<n; i++)
    {
        if(min>a[i])
        {
            min=a[i];
            d=i;
        }
    }
    tt=min;
    e[d]=tt+b[d];
    tt=e[d];

    for(i=0; i<n; i++)
    {
        if(a[i]!=min)
        {
            e[i]=b[i]+tt;
            tt=e[i];
        }
    }
    for(i=0; i<n; i++)
    {

        tat[i]=e[i]-a[i];
        stat=stat+tat[i];
        wt[i]=tat[i]-b[i];
        swt=swt+wt[i];
    }
    atat=stat/n;
    awt=swt/n;
    cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n";

    for(i=0; i<n; i++)
    {
        cout<<"P"<<i+1<<"              "<<a[i]<<"                "<<b[i]<<"                  "<<wt[i]<<"               "<<tat[i]<<endl;
    }

    cout<<"awt="<<awt<<" atat="<<atat;  //average waiting time and turn around time
}
/*
enter no of process
5
enter arival time 3
enter arival time 1
enter arival time 4
enter arival time 0
enter arival time 2
enter brust time 1
enter brust time 4
enter brust time 2
enter brust time 6
enter brust time 3
Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)
P1              3                1                  3               4
P2              4                2                  3               5
P3              2                3                  7               10
P4              1                4                  11               15
P5              0                6                  0               6
awt=4.8  atat=8
*/
