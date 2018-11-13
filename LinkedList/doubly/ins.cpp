#include<iostream>

using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

node* head = NULL;

void insert(node**head, int pos, int data){
    node* newNode = new node;
    newNode->data = data;
    if(pos==1)
    {
        newNode->prev = NULL;
        newNode->next = *head;
        if(*head)
        {
            (*head)->prev = newNode;
        }
    *head = newNode;
    return;
    }
        int index=1;
        node* moveNode;
        moveNode = *head;
        while(index<pos-1 && moveNode!= NULL )
        {
            moveNode = moveNode->next;
            index++;
        }

        newNode->next = moveNode->next; //This also makes newNode->next = NULL if it's the last node.
        newNode->prev = moveNode;  
        if(moveNode->next)
        {
            moveNode->next->prev = newNode;   
        }
        moveNode->next = newNode;
}

void display(node** head){
    node* index;
    index = *head;
    while(index != NULL){
        cout<<index->data<<" ";
        index=index->next;
        }
    cout<<"\n";
}

void deleteNode(node** head, int pos)
{   
    if(pos == 1)
    {   
        if(*head == NULL)
        cout<<"Nothing to delete";
        *head = (*head)->next;
        delete((*head)->prev);
        return;
    }
    int index=1;
    node* moveNode;
    moveNode = *head;
    while(index<pos && moveNode!= NULL )
    {
        moveNode = moveNode->next;
        index++;
    }
    if(index!= pos-1){
        cout<<"Position Doesn't Exist\n";
        return;
    }
    moveNode->prev->next = moveNode->next;
    if(moveNode->next)      //!Check this condition for the deletion at end
    moveNode->next->prev = moveNode->prev;
    delete(moveNode);
       
}

int main(){
    insert(&head, 1, 23);
    display(&head);
    insert(&head,1,13);
    display(&head);
    insert(&head, 3, 12);
    display(&head);
    insert(&head, 4, 15);
    display(&head);
    deleteNode(&head,7);
    display(&head);
}