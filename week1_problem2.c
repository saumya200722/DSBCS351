#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteFromEnd(Node*& head) {
    // If list is empty
    if (head == nullptr) {
        cout << "Linked list is empty!" << endl;
        return;
    }

    // If only one node exists
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // Move to second-last node
    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // Delete last node
    delete temp->next;
    temp->next = nullptr;
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

    deleteFromEnd(head);

    cout << "\nAfter deletion: ";
    display(head);

    return 0;
}
