//Producer Consumer Problem
#include<stdio.h>
void wait(int &x)
{
    if(x>0)
    {
        x--;
    }
}
void signal(int &x)
{
    x++;
}
int main()
{
    int a[3];
    int semaphore_empty = 3;
    int semaphore_full = 0;
    int semaphore_s=1;
    int choice;
    while(1)
    {
        printf("\n");
        printf("Empty=%d\t full=%d\t semaphore= %d\n",semaphore_empty,semaphore_full,semaphore_empty);
        scanf("%d",&choice);
        if(choice==1)
        {
            if(semaphore_empty!=0 && semaphore_s==1)
            {
                printf("Enter product value: \n");
                wait(semaphore_empty);
                wait(semaphore_s);
                scanf("%d", &a[semaphore_full]);
                signal(semaphore_s);
                signal(semaphore_full);
            }
            else
            {
                printf("BUFFER IS FULL");
            }
        }
        else if(choice==2)
        {
            if(semaphore_full>0 && semaphore_s==1)
            {
                wait(semaphore_full);
                wait(semaphore_s);
                printf("Consumed product value is %d\n");
                signal(semaphore_s);
                signal(semaphore_empty);
            }
            else
            {
                printf("BUFFER IS EMPTY");
            }
        }
        else
            break;
    }
    return 0;
}

/*
Empty=3  full=0  semaphore= 3
1
Enter product value:
7

Empty=2  full=1  semaphore= 2
1
Enter product value:
8

Empty=1  full=2  semaphore= 1
1
Enter product value:
6

Empty=0  full=3  semaphore= 0
1
BUFFER IS FULL
Empty=0  full=3  semaphore= 0
2
Consumed product value is 0

Empty=1  full=2  semaphore= 1
2
Consumed product value is 0

Empty=2  full=1  semaphore= 2
2
Consumed product value is 0

Empty=3  full=0  semaphore= 3
2
BUFFER IS EMPTY
Empty=3  full=0  semaphore= 3
1
Enter product value:
18

Empty=2  full=1  semaphore= 2
1
Enter product value:
18

Empty=1  full=2  semaphore= 1
2
Consumed product value is 0

Empty=2  full=1  semaphore= 2
*/

