#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteFromBeginning(Node*& head) {
    // Check if list is empty
    if (head == nullptr) {
        cout << "Linked list is empty!" << endl;
        return;
    }

    Node* temp = head;   // Store first node
    head = head->next;   // Move head to second node

    delete temp;         // Delete first node
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};

    cout << "Before deletion: ";
    display(head);

    deleteFromBeginning(head);

    cout << "\nAfter deletion: ";
    display(head);

    return 0;
}
