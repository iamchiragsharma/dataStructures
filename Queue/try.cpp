#include<iostream>
#define SIZE 3
using namespace std;

int ary[SIZE];

int main()
{
    int a = 10;
    int* ptr = &a;
    int** pptr = &ptr;
    cout<<*ptr<<"\n";
    cout<<**pptr;
}