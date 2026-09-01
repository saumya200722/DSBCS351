#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*insertAtEnd(struct node*head ,int value)
{
    struct node*newnode,*temp;
    newnode = (structnode*)malloc(sizeof(structnode));
    newnode->data=value;
    newnode->next=null;
    if (head==null)
    {
        head = newnode;
    }
    else
    {
        temp= head;
        while(temp->next!=null)
        {
            temp=temp->next;
        }
        temp->next = newnode;
    }
     return head;
}
