//Circular linked list insertion

#include<iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* head = NULL;

node* traversal(node* head){
    node* lastNode = head;
    do{
        lastNode=lastNode->next;
    }while(lastNode->next != head);

    return lastNode;
}

void insert(node** head, int pos, int data){
    node* newNode = new node;
    node* lastNode;
    newNode->data = data;

    if(pos==1){
        if(*head == NULL)
        {
            *head = newNode;
            newNode->next = *head;
            return;
        }
        lastNode = traversal(*head);
        lastNode->next = newNode;
        newNode->next = *head;
        *head = newNode;    
        return;
    }
    int count=1;
    node* moveNode = *head;
    while(count<pos-1 && moveNode->next != *head){
        moveNode = moveNode->next;
        count++;
    }
    node* afterMoveNode = moveNode->next;
    
    if(count != pos-1){
        cout<<"Error\n";
        return;
    }
    moveNode->next = newNode;
    newNode->next = afterMoveNode;
    if(afterMoveNode == *head){
        newNode->next = *head;
    }
}

void display(node* head){
    node* current = head;
    do{
        cout<<current->data<<" ";
        current=current->next;
    }while(current != head); //if we do current->next it leaves the last node so current!=head
    cout<<"\n";
}

void remove(node** head, int pos)
{
    if(pos == 1){
        node* lastNode = traversal(*head);
        lastNode->next = (*head)->next;
        *head = (*head)->next;
        return;
    }

    node* firstNode = *head;
    node* secondNode = NULL;
    int count = 1;
    while(count < pos-1 && firstNode->next != *head ){
        firstNode = firstNode->next;
        count++;
    }

    if(count != pos-1)
    {
        cout<<"Error Wrong Index\n";
        return;
    }
    secondNode = firstNode->next;

    if(secondNode->next == *head)
    {
        firstNode->next = *head;
        return;
    }

    firstNode->next = secondNode->next;
    free(secondNode);
}

int main(){
    insert(&head,1,12);
    insert(&head,2,10);
    insert(&head,3,15);
    insert(&head,2,9);
    insert(&head,4,11);
    insert(&head,4,19);
    insert(&head,1,1);
    display(head);
    remove(&head, 3);
    display(head);
    remove(&head, 1);
    display(head);
    remove(&head,5);
    display(head);
}



//Output
//1 12 9 10 19 11 15
//1 12 10 19 11 15
//12 10 19 11 15
//12 10 19 11