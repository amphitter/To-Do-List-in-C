# To-Do List Application

A simple command-line to-do list application written in C. This application allows you to add tasks, list all tasks, and delete tasks from your to-do list. The tasks are stored in a text file named `todolist.txt` to persist between program runs.

## Features

- Add a new task to the to-do list.
- List all tasks in the to-do list.
- Delete a specific task from the to-do list.

## Requirements

- A C compiler (such as `gcc`).

## How to Compile and Run

1. **Clone the repository** (or download the source code):

   ```sh
   git clone <repository-url>
   cd <repository-directory>
   ```

2. **Compile the source code**:

   ```sh
   gcc todo.c -o todo
   ```

3. **Run the application**:

   ```sh
   ./todo
   ```

## Usage

1. **Add a task**:
   - Select the "Add a task" option from the menu.
   - Enter the task description.

2. **List all tasks**:
   - Select the "List all tasks" option from the menu.
   - All tasks will be displayed with their corresponding task numbers.

3. **Delete a task**:
   - Select the "Delete a task" option from the menu.
   - Enter the task number you wish to delete.

4. **Exit**:
   - Select the "Exit" option from the menu to close the application.

## Example

```sh
To-Do List Application
1. Add a task
2. List all tasks
3. Delete a task
4. Exit
Choose an option: 1
Enter the task: Buy groceries
Task added successfully.

To-Do List Application
1. Add a task
2. List all tasks
3. Delete a task
4. Exit
Choose an option: 2
To-Do List:
1. Buy groceries

To-Do List Application
1. Add a task
2. List all tasks
3. Delete a task
4. Exit
Choose an option: 3
Enter the task number to delete: 1
Task deleted successfully.

To-Do List Application
1. Add a task
2. List all tasks
3. Delete a task
4. Exit
Choose an option: 4
Exiting...
```

## Notes

- The tasks are stored in a file named `todolist.txt` in the same directory as the application. Ensure you have write permissions to this directory.
- If the `todolist.txt` file does not exist, it will be created automatically when adding the first task.

## License

This project is open-source and available under the [MIT License](LICENSE).

## Contributions

Contributions are welcome! Feel free to open an issue or submit a pull request.
