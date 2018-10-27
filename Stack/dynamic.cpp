#define SIZE 4

#include<iostream>
using namespace std;

int* array = new int[SIZE];
int top = -1;
int m = 4;

void copy(int* a, int* temp){
    for(int i=0; i<m;i++){
        temp[i] = a[i];
    }
}
void push(int x)
    {   
        ++top;
        if(top==m)
        {
            m = m*2;
            int* temp = new int[m];
            copy(array,temp);
            array = temp;
        
        }
        array[top] = x;
    }

void pop()
    {
        if(top == -1){
            cout<<"Cannot Pop"
        }   
        array[top] = NULL;
        top--;

    }   

void display()
{
    for(int i=0; i<m; i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    push(3);
    push(6);
    push(8);
    push(10);
    display();
    push(15);
    display();
    push(21);
    push(36);
    push(43);
    display();
    pop();
    display();
    
}