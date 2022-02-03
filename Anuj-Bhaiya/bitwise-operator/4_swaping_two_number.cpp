#include<iostream>
using namespace std;
int main()
{
    int x=999;
    int y=333;
    cout<<"before swaping done x="<<x<<" y="<<y<<endl;
    x=x^y;
    y=x^y;
    x=x^y;
    cout<<"after swaping done x="<<x<<" y="<<y<<endl;
}