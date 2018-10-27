#include<iostream>

using namespace std;

int factorial(int fact)
{
    if(fact==1)
    return 1;

    else
    return fact * factorial(fact - 1);

}
int main()
{
    int fact = 10;
    int val = factorial(fact);
    cout<<val;
    

}