#include<iostream>
using namespace std;
int main()
{
    int arr[]={45,12,35,68,47,95,15,29,89};
    int size=sizeof(arr)/sizeof(arr[0]);
    int search_num;
    cout<<"Enter the Number to be Search:";
    cin>>search_num;
    int flag=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==search_num)
        {
            cout<<"element "<<search_num<<" is found at index:"<<i<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<"Element "<<search_num<<" is not found!";
}