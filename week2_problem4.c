```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Delete from beginning
void deleteBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;

    free(temp);
    printf("Node deleted from beginning.\n");
}

// Delete from end
void deleteEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If there is only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted from end.\n");
        return;
    }

    struct Node *temp = *head;

    // Move to second-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    printf("Node deleted from end.\n");
}

// Delete from a given position
void deletePosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Delete first node
    if (position == 1) {
        deleteBeginning(head);
        return;
    }

    struct Node *temp = *head;

    // Move to the node before the required position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *deleteNode = temp->next;
    temp->next = deleteNode->next;

    free(deleteNode);

    printf("Node deleted from position %d.\n", position);
}

// Display the linked list
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Insert at end (used to create the list)
void insertEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

int main() {
    struct Node *head = NULL;

    // Creating the linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("Original List:\n");
    display(head);

    // Delete from beginning
    deleteBeginning(&head);
    display(head);

    // Delete from end
    deleteEnd(&head);
    display(head);

    // Delete from position 2
    deletePosition(&head, 2);
    display(head);

    return 0;
}
