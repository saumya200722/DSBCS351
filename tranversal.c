#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node*next;

    NOde(int value){
        data = value;
        next = Null;
    }
};

void traverse(Node*head){
    Node*temp = head;

    while(temp != Null){
        cout<<temp->data<<"";
        temp = temp->next;
    }
}

int main(){
    Node*head = newNode(10);
    head->next = newNOde(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);

    traverse(head);

    return 0;
}