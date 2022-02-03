#include<iostream>
using namespace std;
void insert_in_heap_tree(int arr[],int size,int insert_ele) ;

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

void insertion_in_heap_tree(int arr[],int size,int insert_ele)  //method1 as array starting from 0-(size-1)
{
    arr[size]=insert_ele; //inserting at last avail index of heaptree
    int parent_node_index=(size-1)/2;
    while(parent_node_index>=0)    
    {
        if(arr[parent_node_index]>insert_ele)
        {
            break;
        }
        else if(arr[parent_node_index]<insert_ele)
        {
            swap(arr,parent_node_index,parent_node_index*2+1); //compare with parent node and chile node
            cout<<"swaping done...\n";
            size=parent_node_index; //at one time parent node=0
            if(size>0) 
            {parent_node_index=(size-1)/2;}                            //parentNode=(i-1)/2
            else  //eans hmne parent node ko already tuch kar diya h
            break;
        }
    }
    cout<<"after  inserion done in heap tree\n";
    
}

int main()
{
    int heapTree[]={50,40,45,30,20,35,10,0};
    int size=sizeof(heapTree)/sizeof(heapTree[0]);
    display(heapTree,size);

// method1   
    insertion_in_heap_tree(heapTree,size-1,500);
    display(heapTree,size);

// methood 2

    // insertion_in_heap_tree(heapTree,size-1,500);
    // display(heapTree,size);
}

void insert_in_heap_tree(int arr[],int size,int insert_ele) //element is starting from 1-size
{
    int n=size;
    arr[n]=insert_ele;
    int i=n;
    while(i>=1) //untill we check upto root element which is at index 1 of array
    {
        int parent=i/2;
        if(arr[i]<arr[parent])
        break;

        else if(arr[i]>arr[parent])
        {
            swap(arr,i,parent);
            i/=2;
            // OR =>i=parent
        }
    }
}
