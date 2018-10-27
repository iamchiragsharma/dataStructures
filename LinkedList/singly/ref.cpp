#include<iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* head = NULL;

/* There are two ways of updating linked list as we can see first one is the method of the single
reference. See the *head passed is not the actual head here. They have differenct addresses to point.
It's more of a call by VALUE instead of call by referemce. So whenever you use the reference method
don't forget to update the head on your own. You should return the head of the program or the whole 
execution will stop with the error of SEGMENTATION FAULT: CORE DUMPED. Since as soon as the function
ends the memory core is dumped and nothing is returned. */

node* push(node *head, int data){
    cout<<&head<<"\n";
    node* temp = new node;
    if(head == NULL){
        temp->data = data;
        temp->next = NULL;
        head = temp;
        return head;
    }
}

/* This is the second method of dereferencing the pointer. In this method we pass reference to the head
or pointer and we changed directly to it. We don't return anything. But while passing to it make sure to
pass the reference to head in it e.g (&head, 5)  */

void pushRef(node** head, int data){
    node* temp = new node;
    if(*head == NULL){
        temp->data = data;
        temp->next = NULL;
        *head = temp;
    }
}

int main(){
    cout<<head;
    head = push(head, 5);
    //pushRef(&head, 5);
    cout<<head<<"\n";
    cout<<head->data;

}