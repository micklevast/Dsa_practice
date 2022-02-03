#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void reverse_array(int *arr,int size)
{
    int start=0;
    int end=size-1;
    while(start<=end)
    {
        swap(&arr[start],&arr[end]);
        start++;
        end--;
    }
}
void display(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[]={12,56,89,23,45,78,12,56,19};
    int  size=sizeof(arr)/sizeof(arr[0]);
    display(arr,size);
    reverse_array(arr,size);
    display(arr,size);
}