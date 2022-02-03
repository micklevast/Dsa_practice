#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int  temp=a;
    a=b;
    b=temp;

}

int main()
{
    int arr[]={0,2,1,0,2,1,2,1,0,0,0,1,2,2,2,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int l=0,mid=0,h=size-1;
    while(mid<=h)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[l]);
            mid++;l++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else if(arr[mid]==2)
        {
            swap(arr[mid],arr[h]);
            h--;
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"";
    }
}