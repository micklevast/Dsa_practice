#include<iostream>
using namespace std;
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void max_heapify(int arr[],int i,int size) //max_heapify the i th element of array
{                                       //means heapify ith and ussse down wale node of tree per
    int largest=i;
    int left=i*2+1;
    int right=i*2+2;
    if(left<=size && arr[left]>arr[largest]) //checking that left wala exit karta h kya by left<=size
    {
        largest=left; 
    }
    if(right<=size && arr[right]>arr[largest]) //checking that right wala exit karta h kya by right<=size
    {
        largest=right;
    }
    if(largest!=i) //check if root is not largest then swap
    {
        swap(arr,largest,i);
        max_heapify(arr,largest,size);
    }
    else
    return ;
}
void  Build_max_heap(int arr[],int size)
{
    // as the leaf node is already heapify so don't need to heapify again them
    // since node without child is start from size/2-1 th index of array so we start from there as they are not heapify
    for(int i=size/2-1;i>=0;i--)
    {
        max_heapify(arr,i,size);
    }
}
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void heap_sort(int arr[],int size)
{
    max_heapify(arr,0,size);
    for(int k=size;k>0;k--) //decreasing the heap size
    {
        swap(arr,0,k);
        size--; //swaping max__heap_val with last element of heap
        max_heapify(arr,0,size);
    }
}

int main()
{
    int arr[]={23,56,45,78,89,12,68,49};
    int size=sizeof(arr)/sizeof(arr[0]);
    display(arr,size);
    Build_max_heap(arr,size-1);
    cout<<"displayin max Heap    :";
    display(arr,size);
    cout<<"displayin sorted array:";
    heap_sort(arr,size-1);
    display(arr,size);
}