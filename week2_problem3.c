```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert at beginning
void insertBeginning(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display the linked list
void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    insertBeginning(&head, 20);
    insertBeginning(&head, 10);

    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Linked List: ");
    display(head);

    return 0;
}
