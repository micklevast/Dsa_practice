#include<iostream>
using namespace std;
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
}

void heapify(int arr[],int heapify_ele_index,int size)
{
    int larger=heapify_ele_index;
    int left_child=heapify_ele_index*2+1;
    int right_child=heapify_ele_index*2+2;
    if(left_child<=size && arr[left_child]>arr[larger])
    {
        larger=left_child;
    }
    if(right_child<=size && arr[right_child]>arr[larger])
    {
        larger=right_child;
    }

    if(larger!=heapify_ele_index)
    {
        swap(arr,larger,heapify_ele_index);
        cout<<"swaping...\n";
        heapify(arr,larger,size);
        
    }
    else 
    return ;


}

void deletion_in_HeapTree(int arr[],int size) //deletion is always delete =>root element
{
    arr[0]=arr[size-1];
    heapify(arr,0,size-1);
    // max_heapify(arr,0,size-1);

    
}

void deletion_method2(int arr[],int size)
{
    arr[0]=arr[size];
    int i=0;
    while(i<=size-1)
    {
        if(i*2+1<=size)
        int left=arr[i*2+1];

        if(i*2+2<=size)
        int right=arr[i*2+2];

        int larger=left>right?((i*2)+1):((i*2)+2);
        if(arr[i]<arr[larger])
        {
            swap(arr,i,larger);
            i=larger;
        }
        else 
        {
           return; 
        }
    }
}

int main()
{
    int heapTree[]={500,400,405,30,20,35,10};
    int size=sizeof(heapTree)/sizeof(heapTree[0]);
    display(heapTree,size);
    // deletion_in_HeapTree(heapTree,size);
    // display(heapTree,size-1);

    deletion_method2(heapTree,size-1);
    display(heapTree,size-1);
}