#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
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
    // cout<<"this is vishal";
    int arr[]={0,1,1,2,1,0};
    int size=sizeof(arr)/sizeof(arr[0]);

    display(arr,size);
    int low,mid,high;
    low=mid=0;
    high=size-1;
    while(mid<=high)  //TC:O(n)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++,mid++;
        }
        else if(arr[mid]==1)
        mid++;
        else if(arr[mid]==2)
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }

    display(arr,size);
      
}