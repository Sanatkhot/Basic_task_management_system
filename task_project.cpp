//
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

// Task structure to store task details
struct Task {
    char description[50];
    int completed;
};

// add a new task
void addTask(struct Task tasks[], int *taskCount, char description[]) {
    if (*taskCount < MAX_TASKS) {
        struct Task newTask;
        strcpy(newTask.description, description);
        newTask.completed = 0; // Set as incomplete by default
        tasks[*taskCount] = newTask;
        (*taskCount)++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}

// task as complete
void markTaskCompleted(struct Task tasks[], int taskCount, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskCount) {
        tasks[taskIndex].completed = 1;
        printf("Task marked as completed!\n");
    } else {
        printf("Invalid task index.\n");
    }
}

//  display all tasks
void displayTasks(struct Task tasks[], int taskCount) {
    if (taskCount > 0) {
        printf("Task List:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s - %s\n", i + 1, tasks[i].description, tasks[i].completed ? "Completed" : "Incomplete");
        }
    } else {
        printf("No tasks available.\n");
    }
}

int main() {
    struct Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice, taskIndex;
    char description[50];

    do {
        printf("\nTask Management System\n");
        printf("1. Add Task\n");
        printf("2. Mark Task as Completed\n");
        printf("3. Display Tasks\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]s", description); // Read input with spaces
                addTask(tasks, &taskCount, description);
                break;
            case 2:
                printf("Enter task index to mark as completed: ");
                scanf("%d", &taskIndex);
                markTaskCompleted(tasks, taskCount, taskIndex - 1); // Subtract 1 for array index
                break;
            case 3:
                displayTasks(tasks, taskCount);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
