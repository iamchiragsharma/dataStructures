//Queue as static array
#define SIZE 5
#include<iostream>

using namespace std;
int array[SIZE];
int front=-1,rear=-1;

void insert(int data)
{   
    rear = rear + 1;
    if(rear==SIZE)
    {
        cout<<"Overflow\n";
        return;
    }
    
    if(rear==0)
    {
        front = rear;
        array[rear] = data;
        return;    
    }
    
    array[rear] = data;
}

void display(int front, int rear, int array[])   
{
    for(int i=front; i<rear; i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}

void remove(int front, int rear)
{
    ++front;
    if(front == rear+1)
    cout<<"Underflow";
}
int main()
{
    insert(5);
    insert(10);
    insert(3);
    insert(5);
    insert(9);
    insert(10);
    display(front,rear,array);
    remove(front, rear);
    display(front,rear,array);

}