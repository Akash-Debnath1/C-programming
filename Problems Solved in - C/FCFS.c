#include <stdio.h>


int main() {
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    float total_wt = 0, total_tat = 0;
    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage waiting time: %.2f", total_wt / n);
    printf("\nAverage turnaround time: %.2f", total_tat / n);

    getch();
}
