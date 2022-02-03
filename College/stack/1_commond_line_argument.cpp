#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    cout<<"this is running safely";
    cout<<"you have entered "<<argc<<" number of commond line argument";
    for(int i=0;i<argc;i++)
    cout<<argv[i]<<endl;
    return 0;
}
