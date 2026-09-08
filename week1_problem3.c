#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteAtK(Node*& head, int k) {
    // Empty list
    if (head == nullptr) {
        cout << "Linked list is empty!" << endl;
        return;
    }

    // Delete first node
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    // Move to (k-1)th node
    for (int i = 1; i < k - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Delete kth node
    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
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

    int k;
    cout << "\nEnter position: ";
    cin >> k;

    deleteAtK(head, k);

    cout << "After deletion: ";
    display(head);

    return 0;
}
