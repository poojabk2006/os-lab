#include <stdio.h>
int main() {
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], pr[20];
    int ct[20], wt[20], tat[20], done[20] = {0};
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Enter Priority (lower number = higher priority):\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pr[i]);

    while(completed < n) {
        int min = 9999, index = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && done[i] == 0 && pr[i] < min) {
                min = pr[i];
                index = i;
            }
        }

        if(index != -1) {
            time += bt[index];
            ct[index] = time;
            done[index] = 1;
            completed++;
        } else {
            time++;
        }
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    avg_tat /= n;
    avg_wt /= n;

    printf("\nProcess AT BT PR CT WT TAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], ct[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
