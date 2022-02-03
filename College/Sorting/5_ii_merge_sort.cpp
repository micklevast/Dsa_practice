#include<iostream>
using namespace std;
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int b[15]={0};
void merge(int arr[],int l,int mid,int r)
{
    int i=l,k=l,j=mid+1;
    while(i<=mid && j<=r)
    {
        if(arr[i]>arr[j])
        {
            b[k++]=arr[j++];
        }
        else
        {
            b[k++]=arr[i++];
        }
    }

    if(i>mid)
    {
        while(j<=r)
        b[k++]=arr[j++];
    }
    if(j>r)
    {
        while (i<=mid)
        {
            b[k++]=arr[i++];
        }
        
    }
    for(int x=l;x<k;x++)
    {
        arr[x]=b[x];
    }
}

void merge_sort(int *arr,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);

    }
}

int main()
{
    int arr[]={35,26,12,34,18,377,98,65,59,38};
    int size=sizeof(arr)/sizeof(arr[0]);
    display(arr,size);

    merge_sort(arr,0,size-1);
    display(arr,size);
}