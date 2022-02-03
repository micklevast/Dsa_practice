#include<iostream>
using namespace std;

void fibonacci_series(int size)
{
    if(size==1)
    cout<<0<<" ";
    else
    cout<<0<<" "<<1<<" ";
    int ist=0;int iind=1;
    int next;
    for(int i=2;i<size;i++)
    {
        next=ist+iind;
        cout<<next<<" ";
        ist=iind;
        iind=next;
    }


}
int main()
{
    int size=19;
    fibonacci_series(size);
}