#include <stdio.h>

int main() {
    int alloc[5][5], req[5][5], avail[5];
    int finish[5] = {0};
    int n, m, i, j, flag;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    // Allocation Matrix
    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Request Matrix
    printf("Enter Request Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &req[i][j]);

    // Available Resources
    printf("Enter Available Resources:\n");
    for(j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    // Deadlock Detection
    for(i = 0; i < n; i++) {
        flag = 0;

        for(j = 0; j < m; j++) {
            if(req[i][j] > avail[j]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            finish[i] = 1;
        }
    }

    // Display Deadlocked Processes
    printf("\nDeadlocked Processes:\n");

    for(i = 0; i < n; i++) {
        if(finish[i] == 0)
            printf("P%d\n", i);
    }

    return 0;
}
