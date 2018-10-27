//QUEUE AS LINKED LIST

#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enQueue(node** front, node** rear, int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;

    if(*rear == NULL){
        *front = newNode;
        *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
    
}

void display(node* front, node* rear)
{
    node* current = front;
    while(current != rear->next){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<"\n";
}

void deQueue(node** front, node** rear)
{
    if(*front == NULL ){
        cout<<"Nothing to pop";
        return;
    }
    node* temp;
    temp = *front;
    *front = (*front)->next;
    cout<<"Popped Element "<<temp->data;
    delete(temp);
    cout<<"\n";
}
int main()
{
    enQueue(&front,&rear,3);
    enQueue(&front,&rear,13);
    enQueue(&front,&rear,18);
    enQueue(&front,&rear,21);
    enQueue(&front,&rear,25);
    enQueue(&front,&rear,38);
    display(front,rear);
    deQueue(&front,&rear);
    display(front,rear);
    deQueue(&front,&rear);
    display(front,rear);
    deQueue(&front,&rear);
    display(front,rear);
    deQueue(&front,&rear);
    display(front,rear);
    deQueue(&front,&rear);
    display(front,rear);
    deQueue(&front,&rear);
    display(front,rear);
    deQueue(&front,&rear);
}