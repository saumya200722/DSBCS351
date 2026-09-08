#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtK(Node*& head, int value, int k) {
    Node* newNode = new Node();
    newNode->data = value;

    // Insert at first position
    if (k == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    // Move to (k-1)th node
    for (int i = 1; i < k - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == nullptr) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    // Insert new node
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = nullptr;

    // Create linked list: 10 -> 20 -> 30 -> 40
    head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};

    int k, value;

    cout << "Enter position: ";
    cin >> k;

    cout << "Enter value: ";
    cin >> value;

    insertAtK(head, value, k);

    cout << "Linked list after insertion: ";
    display(head);

    return 0;
}
