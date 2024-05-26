#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_LENGTH 256
#define TODO_FILE "todolist.txt"

// Function to display the menu
void displayMenu() {
    printf("To-Do List Application\n");
    printf("1. Add a task\n");
    printf("2. List all tasks\n");
    printf("3. Delete a task\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Function to add a task to the to-do list
void addTask() {
    FILE *file = fopen(TODO_FILE, "a");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char task[MAX_TASK_LENGTH];
    printf("Enter the task: ");
    getchar(); // To consume the newline character left by previous input
    fgets(task, MAX_TASK_LENGTH, stdin);
    task[strcspn(task, "\n")] = '\0'; // Remove the newline character

    fprintf(file, "%s\n", task);
    fclose(file);
    printf("Task added successfully.\n");
}

// Function to list all tasks in the to-do list
void listTasks() {
    FILE *file = fopen(TODO_FILE, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char task[MAX_TASK_LENGTH];
    int taskNumber = 1;

    printf("To-Do List:\n");
    while (fgets(task, MAX_TASK_LENGTH, file)) {
        task[strcspn(task, "\n")] = '\0'; // Remove the newline character
        printf("%d. %s\n", taskNumber++, task);
    }

    fclose(file);
}

// Function to delete a task from the to-do list
void deleteTask() {
    FILE *file = fopen(TODO_FILE, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char tasks[100][MAX_TASK_LENGTH];
    int taskNumber = 1, taskToDelete;

    // Read all tasks into an array
    while (fgets(tasks[taskNumber - 1], MAX_TASK_LENGTH, file)) {
        tasks[taskNumber - 1][strcspn(tasks[taskNumber - 1], "\n")] = '\0'; // Remove the newline character
        taskNumber++;
    }

    fclose(file);

    if (taskNumber == 1) {
        printf("No tasks to delete.\n");
        return;
    }

    listTasks();
    printf("Enter the task number to delete: ");
    scanf("%d", &taskToDelete);

    if (taskToDelete < 1 || taskToDelete >= taskNumber) {
        printf("Invalid task number.\n");
        return;
    }

    file = fopen(TODO_FILE, "w");
    if (!file) {
        perror("Could not open file");
        return;
    }

    // Write all tasks except the one to be deleted
    for (int i = 0; i < taskNumber - 1; i++) {
        if (i != taskToDelete - 1) {
            fprintf(file, "%s\n", tasks[i]);
        }
    }

    fclose(file);
    printf("Task deleted successfully.\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                listTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
