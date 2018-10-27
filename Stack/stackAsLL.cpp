//Linked list implementation as stack

#include<iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* top = NULL;

void push(node** top, int data){
    node* newNode = new node;
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

void pop(node** top){
    if(*top == NULL){
        cout<<"Underflow";
    }
    node* current = *top;
    *top = (*top)->next;
    delete(current);
}

void display(node* top){
    node* current = top;
    while(current!= NULL)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<"\n";
}

int main()
{
    push(&top, 15);
    push(&top, 23);
    push(&top, 67);
    push(&top, 89);
    display(top);
}