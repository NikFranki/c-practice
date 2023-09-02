// #include <stdio.h>
// #include <stdlib.h>

// typedef struct NODE {
//   struct NODE *link;
//   int value;
// } Node;

// #define FALSE 0
// #define TRUE 1

// int sll_insert(Node *current, int new_value)
// {
//   Node *previous;
//   Node *new;

//   while (current->value < new_value)
//   {
//     previous = current;
//     current = current->link;
//   }

//   new = (Node *)malloc(sizeof(Node));
//   if (new == NULL)
//   {
//     return FALSE;
//   }

//   new->value = new_value;
//   new->link = current;
//   previous->link = new;

//   return TRUE;
// }

// int main()
// {
//   int result = sll_insert(NULL, 1);
//   printf("insert result: %d\n", result);
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

// 创建新节点
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int value)
{
  Node *newNode = createNode(value);
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }

  Node *previous;
  Node *current = *head;
  while (current != NULL && current->data < value)
  {
    previous = current;
    current = current->next;
  }
  previous->next = newNode;
  newNode->next = current;
}

void deleteNode(Node **head, int value)
{
  Node *newNode = createNode(value);
  if (*head == NULL)
  {
    return;
  }

  Node *previous;
  Node *current = *head;

  // 如果是删除头结点
  if (current->data == value)
  {
    *head = current->next;
    return;
  }


  while (current->data != value)
  {
    previous = current;
    current = current->next;
  }

  // 如果删除的是尾结点
  if (current->next == NULL)
  {
    Node *haha = NULL;
    previous->next = haha;
    return;
  }

  previous->next = current->next;
}

// 在链表末尾插入节点
void insertEnd(Node **head, int value) {
    Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// 打印链表内容
void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 释放链表内存
void freeList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;

    // insertEnd(&head, 1);
    // insertEnd(&head, 2);
    // insertEnd(&head, 3);

    insertNode(&head, 1);
    insertNode(&head, 9);
    insertNode(&head, 2);
    insertNode(&head, 4);
    insertNode(&head, 7);
    insertNode(&head, 3);

    deleteNode(&head, 9);

    printf("Linked List: ");
    printList(head);

    freeList(head);

    return 0;
}
