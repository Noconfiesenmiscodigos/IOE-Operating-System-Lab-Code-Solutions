/* Multiple-Level Queues Scheduling
It may happen that processes in the ready queue can be divided into different classes where each class
has its own scheduling needs. For example, a common division is a foreground (interactive) process and
a background (batch) process. These two classes have different scheduling needs. For this kind of situation
Multilevel Queue Scheduling is used. Now, let us see how it works.

Ready Queue is divided into separate queues for each class of processes. For example, let us take three different
types of processes System processes, Interactive processes, and Batch Processes. All three processes have their own
queue. Now, look at the below figure.
*/
/*Multiple-Level Queues Scheduling*/
#include<stdio.h>
int main()
{
    int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp;
    float wtavg, tatavg;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        p[i] = i;
        printf("Enter the Burst Time of Process%d:", i);
        scanf("%d",&bt[i]);
        printf("System/User Process (0/1) ? ");
        scanf("%d", &su[i]);
    }
    for(i=0; i<n; i++)
        for(k=i+1; k<n; k++)
            if(su[i] > su[k])
            {
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=su[i];
                su[i]=su[k];
                su[k]=temp;
            }
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];
    for(i=1; i<n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for(i=0; i<n; i++)
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],su[i],bt[i],wt[i],tat[i]);
    printf("\nAverage Waiting Time is --- %f",wtavg/n);
    printf("\nAverage Turnaround Time is --- %f",tatavg/n);
    return 0;
}
/*
Enter the number of processes:3
Enter the Burst Time of Process0:12
System/User Process (0/1) ? 0
Enter the Burst Time of Process1:18
System/User Process (0/1) ? 0
Enter the Burst Time of Process2:15
System/User Process (0/1) ? 1

PROCESS          SYSTEM/USER PROCESS    BURST TIME      WAITING TIME    TURNAROUND TIME
0                0               12              0               12
1                0               18              12              30
2                1               15              30              45
Average Waiting Time is --- 14.000000
Average Turnaround Time is --- 29.000000
*/
