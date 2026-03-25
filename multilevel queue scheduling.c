#include <stdio.h>
int main() {
    int n, i, time = 0, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], rt[n], queue[n];
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];

        printf("Enter Queue (1: RR, 2: FCFS) for P%d: ", i+1);
        scanf("%d", &queue[i]);
    }

    printf("Enter Time Quantum for Queue 1 (RR): ");
    scanf("%d", &tq);
    printf("\nExecution Order (Queue 1 - RR):\n");

    int done;
    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(queue[i] == 1 && rt[i] > 0) {
                done = 0;

                if(rt[i] <= tq) {
                    time += rt[i];
                    rt[i] = 0;

                    tat[i] = time;
                    wt[i] = tat[i] - bt[i];

                    printf("P%d ", i+1);
                } else {
                    time += tq;
                    rt[i] -= tq;

                    printf("P%d ", i+1);
                }
            }
        }
    } while(!done);
    printf("\nExecution Order (Queue 2 - FCFS):\n");

    for(i = 0; i < n; i++) {
        if(queue[i] == 2 && rt[i] > 0) {
            time += rt[i];

            tat[i] = time;
            wt[i] = tat[i] - bt[i];

            rt[i] = 0;

            printf("P%d ", i+1);
        }
    }
    printf("\n\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
