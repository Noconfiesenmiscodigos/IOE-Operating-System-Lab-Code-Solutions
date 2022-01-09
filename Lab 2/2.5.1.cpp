/*
Out of all the available processes, CPU is assigned to the process having the smallest burst time.

1-In the case of a tie, it is broken by FCFS Scheduling.
2-The preemptive mode of Shortest Job First is called the Shortest Remaining Time First(SRTF).

Advantages-

1-SRTF is optimal and guarantees the minimum average waiting time.
2-It provides a standard for other algorithms since no other algorithm
  performs better than it.

Disadvantages-

1-It cannot be implemented practically since the burst time of the
  processes can not be known in advance.
2-It leads to starvation for processes with larger burst time.
3-Priorities cannot be set for the processes.
4-Processes with larger burst time have poor response time.
*/
/*Shortest Remaining Time Next Scheduling*/
#include<iostream>

using namespace std;
int main()
{
    int a[10],b[10],x[10];
    int waiting[10],turnaround[10],completion[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;

    cout<<"\nEnter the number of Processes: ";  //input
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter arrival time of process: ";  //input
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter burst time of process: ";  //input
        cin>>b[i];
    }
    for(i=0; i<n; i++)
        x[i]=b[i];

    b[9]=9999;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;
}
/*
Enter the number of Processes: 5

Enter arrival time of process: 3

Enter arrival time of process: 1

Enter arrival time of process: 4

Enter arrival time of process: 0

Enter arrival time of process: 2

Enter burst time of process: 1

Enter burst time of process: 4

Enter burst time of process: 2

Enter burst time of process: 6

Enter burst time of process: 3
Process burst-time      arrival-time    waiting-time    turnaround-time completion-time
p1              1               3               0               1               4
p2              4               1               1               5               6
p3              2               4               2               4               8
p4              6               0               10              16              16
p5              3               2               6               9               11


Average waiting time =3.8  Average Turnaround time =7
*/
