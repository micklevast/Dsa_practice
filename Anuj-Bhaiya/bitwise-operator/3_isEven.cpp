#include<iostream>
#include<string>
using namespace std;
int main()
{
    int x=8967;
    
    if((x&1)==0)
    cout<<"x=>"<<"even number"<<endl;
    else 
    cout<<"x=>"<<"odd number"<<endl;
}