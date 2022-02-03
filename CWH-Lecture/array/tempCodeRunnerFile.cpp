#include<iostream>
using namespace std;
void display(int *arr,int size)
{
    for(int i=0;i<size;i++ )
    {
        cout<<*arr<<" ";
        arr++;
    }
}
int main()
{
    int size;
    cout<<"enter size of array:"<<size;
    cin>>size;
    int *arr=new int(size);
    for(int i=0;i<size;i++)
    {
        cin>>*arr;
        arr++;
    }
    display(arr,size);


}