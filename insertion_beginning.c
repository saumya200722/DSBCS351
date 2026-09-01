#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*insert at beginning(struct node*head ,int value)
{
    struct node*newnode;
    newnode = (structnode*)malloc(sizeof(structnode));
    newnode->data=value;
    newnode->next=head;
    head = newnode;
    return head;
}
