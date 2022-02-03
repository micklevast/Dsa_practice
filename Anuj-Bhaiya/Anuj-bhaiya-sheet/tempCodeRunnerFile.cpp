#include<iostream>
#include<algorithm>
using namespace std;
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(int arr1[],int  s1,int arr2[],int s2)
{
    sort(arr1[0],arr1[s1-1]);
    sort(arr2[0],arr2[s2-1]);
    display(arr1,s1);
    display(arr2,s2);
    int temp=arr1[s1-1];

    
}
int main()
{
    int arr1[5]={45,89,23,75,16};
    int arr2[6]={35,19,53,61,43,88};
    merge(arr1,5,arr2,6);
}