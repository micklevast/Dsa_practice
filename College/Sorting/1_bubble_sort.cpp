#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void display(int  arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubble_sort(int arr[],int size)
{
    for(int i=0;i<=size-1;i++)
    {
        for(int j=0;j<=size-1-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
                swap(arr[j+1],arr[j]);
            }
        }
    }
}

int main()
{
    int arr[]={52,12,45,62,56,77,99,189,115,95};
    int size=sizeof(arr)/sizeof(arr[0]);
    display(arr,size);
    bubble_sort(arr,size);
    display(arr,size);
}