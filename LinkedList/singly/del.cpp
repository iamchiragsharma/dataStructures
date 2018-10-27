#include<iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* head = NULL;

void insertNode(node** head, int data, int pos)
{
    node* temp = new node;

    temp->data = data;
    if(pos == 1)
    {
        temp->next = *head;
        *head = temp;
        return;
    }
    node* current = *head;
    int count=1;
    while(count < pos-1 && current!=NULL)
    {
        count++;
        current = current->next;
    }

    if(count != pos-1)
    {
        cout<<"Error cannot insert";
        return;
    }

    temp->next = current->next;
    current->next = temp;
}



void displayNode(node* head)
{
    node* index = head;
    //using index->next = NULL leaves the last element behind 
    //display function
    while(index != NULL){
        cout<<index->data<<" ";
        index=index->next;
    }
    cout<<"\n";
}

//Deletion can be done in three ways
//Deleting from the end
//Deleting from the beginning
//Deleting from the middle

void deleteNode(node** head, int pos)
{
    node* current = *head;
    //Deleting from beginning
    if(pos == 1)
    {
        if(*head == NULL)
        {
            cout<<"Underflow";
            return;
        }
        *head = (*head)->next;
        free(current);
        return;
    }
    int count=1;
    node* prevCurrent =*head;
    while(count < pos && current!=NULL)
    {
        count++;
        prevCurrent = current;
        current = current->next;
    }
    prevCurrent->next = current->next;
}

int main(){
    insertNode(&head,10,1);
    insertNode(&head,5,2);
    insertNode(&head,3,3);
    insertNode(&head,14,2);
    insertNode(&head,15,4);
    insertNode(&head,13,5);
    insertNode(&head,18,3);
    insertNode(&head,4,2);
    displayNode(head);
    deleteNode(&head,2);
    displayNode(head);
}