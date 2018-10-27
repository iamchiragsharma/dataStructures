#define MAXSIZE 5

#include<iostream>
using namespace std;


int stack[MAXSIZE];
int top = -1;

int isfull(){
    if(top == MAXSIZE - 1){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

void push(int x){
    if(!isfull()){
        stack[++top] = x;
    }
    else cout<<"Overflow\n";
}

void pop(){
    if(!isEmpty()){
        top--;
    }
    else cout<<"Underflow\n";
}

void display(){
    for(int i=0;i<MAXSIZE;i++){
        cout<<stack[i]<<" ";
    }
    cout<<"\n";
}

int main()
{   
    push(8);
    push(2);
    push(4);
    push(3);
    push(10);
    push(5);   
}