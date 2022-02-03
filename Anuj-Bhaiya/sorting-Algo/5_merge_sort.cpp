#include<iostream>
using namespace std;
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int ar[20];
void merge(int arr[],int l,int mid,int r)
{
    int k=l;
    int i=l,j=mid+1;
    while(i<=mid && j<=r)
    {
        if(arr[i]<arr[j])
        ar[k++]=arr[i++];
        else
        ar[k++]=arr[j++];
    }
    if(i>mid)
    {
        while(j<=r)
        ar[k++]=arr[j++];
    }
    if(j>r)
    {
        while(i<=mid)
        ar[k++]=arr[i++];
    }
    for(int x=l;x<k;x++)
    arr[x]=ar[x];
}
void merge_sort(int arr[],int l,int r)
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
        int arr[] = {245, 12, 429, 236, 27, 218, 298, 216, 133, 272};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    merge_sort(arr,0,size-1);
    display(arr, size);
}