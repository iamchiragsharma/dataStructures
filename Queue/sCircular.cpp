//CIRCULAR QUEUE IN STATIC ARRAY
#define SIZE 5
#include<iostream>

using namespace std;
int array[SIZE];
int front=-1,rear=-1;


void enQueue(int data)
{
    rear = ++rear%SIZE;

    if(front==-1)
    {
        front = rear;
        array[rear] = data;
        return;
    }
    if(front == rear)
    {
        cout<<"Overflow\n";
        return;
    }

    array[rear] = data;
}

void deQueue()
{
    array[front] = 0;
    front = ++front%SIZE;

    if(front == -1)
    {
        cout<<"Underflow\n";
        return;
    }
    if(front == rear)
    {
        cout<<"Underflow\n";
    }

}


void display()
{
    cout<<"Front> "<<front<<"\n";
    cout<<"Rear> "<<rear<<"\n";
    int count = front;
    
    while(count<=rear)
    {
        cout<<array[count]<<" ";

        if(count<SIZE)
        count++;
        else
        count = (count+1)%SIZE;
    }
    cout<<"\n";
}

int main()
{
enQueue(10);
enQueue(12);
enQueue(14);
enQueue(19);
enQueue(21);
display();  
deQueue();
display(); 
enQueue(1);
display();
}