#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node *next;
};

int main() {
    // Create nodes
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // Allocate memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Store data
    head->data = 10;
    second->data = 20;
    third->data = 30;

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = NULL;

    // Traversal
    struct Node *temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    // Free memory
    free(head);
    free(second);
    free(third);

    return 0;
}
