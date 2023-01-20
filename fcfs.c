#include <stdio.h>
int n, i, j, at[10], bt[10], ct[10], tat[10], wt[10];
float avg_tat, avg_wt;
void take_input()
{
    printf("Enter the number of process:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number of arrival time:");
        scanf("%d", &at[i]);
        printf("Enter the number of burst time:");
        scanf("%d", &bt[i]);
    }
}

void process()
{
    // int time;

    ct[0] = bt[0];
    for (i = 0; i < n; i++)
    {
        // ct[i] = time;
        ct[i + 1] = ct[i] + bt[i + 1];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}

void process_avg()
{
    avg_wt = 0;
    avg_tat = 0;
    for (i = 0; i < n; i++)
    {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    avg_tat = (double)(avg_tat / n);
    avg_wt = (double)(avg_wt / n);
}

void display()
{
    printf("\n\nArrival Time\tBurst Time\tExit Time\tTAT\tWaiting Time\n ");
    for (i = 0; i < n; i++)
    {
        // printf("Arrival Time\tBurst Time\tExit Time\tTAT\tWaiting Time\n ");
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage Turnaround time = %f \n", avg_tat);
    printf("Average Waiting time = %f ", avg_wt);
}
void main()
{
    take_input();
    process();
    process_avg();
    display();
}