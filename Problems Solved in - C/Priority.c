#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int id, priority, burst_time, arrival_time;
    int remaining_time;
} Process;

void priorityScheduling(Process[], int);

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter process %d details:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    priorityScheduling(processes, n);

    return 0;
}

void priorityScheduling(Process processes[], int n) {
    int current_time = 0, total_waiting_time = 0, total_turnaround_time = 0;
    int completed = 0;

    while (completed < n) {
        int min_priority = 100, min_index;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0 && processes[i].priority < min_priority) {
                min_priority = processes[i].priority;
                min_index = i;
            }
        }

        if (min_priority == 100) {
            current_time++;
            continue;
        }

        total_waiting_time += current_time - processes[min_index].arrival_time;
        total_turnaround_time += current_time - processes[min_index].arrival_time + processes[min_index].remaining_time;
        current_time += processes[min_index].remaining_time;
        processes[min_index].remaining_time = 0;
        printf("\nProcess %d completed at time %d", processes[min_index].id, current_time);
        completed++;
    }

    printf("\nAverage waiting time: %.2f", (float)total_waiting_time / n);
    printf("\nAverage turnaround time: %.2f", (float)total_turnaround_time / n);

    getch();
}
