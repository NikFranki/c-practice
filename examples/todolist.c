// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_TASKS 100
// #define MAX_TASK_LENGTH 100

// typedef struct {
//     char description[MAX_TASK_LENGTH];
//     int completed;
// } Task;

// Task tasks[MAX_TASKS];
// int numTasks = 0;

// void addTask(const char *description) {
//     if (numTasks < MAX_TASKS) {
//         strcpy(tasks[numTasks].description, description);
//         tasks[numTasks].completed = 0;
//         numTasks++;
//         printf("Task added: %s\n", description);
//     } else {
//         printf("Task list is full.\n");
//     }
// }

// void listTasks() {
//     printf("Todo List:\n");
//     for (int i = 0; i < numTasks; i++) {
//         printf("%d. [%c] %s\n", i + 1, tasks[i].completed ? 'X' : ' ', tasks[i].description);
//     }
// }

// void completeTask(int index) {
//     if (index >= 0 && index < numTasks) {
//         tasks[index].completed = 1;
//         printf("Task completed: %s\n", tasks[index].description);
//     } else {
//         printf("Invalid task index.\n");
//     }
// }

// int main() {
//     char input[MAX_TASK_LENGTH];
//     char command;
//     int index;

//     while (1) {
//         printf("Enter command (a: add, l: list, c: complete, q: quit): ");
//         scanf(" %c", &command);

//         if (command == 'q') {
//             break;
//         }

//         switch (command) {
//             case 'a':
//                 printf("Enter task description: ");
//                 scanf(" %[^\n]", input);
//                 addTask(input);
//                 break;
//             case 'l':
//                 listTasks();
//                 break;
//             case 'c':
//                 printf("Enter task index to complete: ");
//                 scanf("%d", &index);
//                 completeTask(index - 1);
//                 break;
//             default:
//                 printf("Invalid command.\n");
//                 break;
//         }
//     }

//     printf("Goodbye!\n");

//     return 0;
// }

// copy(try to make it by myself)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASKS_LENGTH 100

typedef struct
{
  char desc[MAX_TASKS_LENGTH];
  int completed;
} Task;

Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask(const char *desc)
{
  if (numTasks < MAX_TASKS)
  {
    strcpy(tasks[numTasks].desc, desc);
    tasks[numTasks].completed = 0;
    numTasks++;
    printf("Task added: %s\n", desc);
  }
  else
  {
    printf("Task list is full.\n");
  }
}

void listTasks()
{
  printf("Todo List:\n");
  for (int i = 0; i < numTasks; i++)
  {
    printf("%d. [%c] %s\n", i + 1, tasks[i].completed ? 'X' : ' ', tasks[i].desc);
  }
}

void completeTask(int index)
{
  if (index >= 0 && index < numTasks)
  {
    tasks[index].completed = 1;
    printf("Task completed: %s\n", tasks[index].desc);
  }
  else
  {
    printf("Invalid task index.\n");
  }
}

int main()
{
  char input[MAX_TASKS_LENGTH];
  char command;
  int index;

  while (1)
  {
    printf("Enter command (a: add, l: list, c: complete, q: quit): ");
    scanf(" %c", &command);

    if (command == 'q')
    {
      break;
    }

    switch (command)
    {
    case 'a':
      printf("Enter task desc: ");
      scanf(" %[^\n]", input);
      addTask(input);
      break;
    case 'l':
      listTasks();
      break;
    case 'c':
      printf("Enter task index to complete: ");
      scanf("%d", &index);
      completeTask(index - 1);
      break;
    default:
      printf("Invalid command.\n");
      break;
    }
  }

  printf("Goodbye!\n");

  return 0;
}