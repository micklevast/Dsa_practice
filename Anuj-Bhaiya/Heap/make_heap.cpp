#include <iostream>
#include <vector>
using namespace std;
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void heapify(int arr[],int heapify_pos,int size_of_arr)
{
    int largest=heapify_pos;
    // int parent=heapify_pos;
    int L_child=largest*2;
    int R_child=largest*2+1;
    if(L_child<size_of_arr && arr[L_child]>arr[largest])
    {largest=L_child;
    cout<<"largest changes to left child\n";}

    if(R_child<size_of_arr && arr[R_child]>arr[largest])
    {largest=R_child;
    cout<<"largest changes to right child\n";}

    if(largest!=heapify_pos)
    {
        swap(arr,largest,heapify_pos);

        int parent_of_heapify_pos=heapify_pos/2;
        if(parent_of_heapify_pos>=1)
        heapify(arr,parent_of_heapify_pos,size_of_arr);
    }
    else
    return;

}
void print_arr(int arr[],int size);
void make_heap(int arr[],int size_of_arr)
{
    int non_leaf_ele=size_of_arr/2;
    cout<<"non leaf:"<<non_leaf_ele<<endl;
    int loop=1;
    for(int i=(non_leaf_ele);i>=1;i--)
    {
        cout<<"loop:"<<loop++<<endl;
        heapify(arr,i,size_of_arr);
        print_arr(arr,size_of_arr);
    }
}

void print_arr(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n------------------------------\n";
}

int main()
{
    // Heap is data structure create using complete Binary tree

    // A Heap is a special Tree-based data structure in which the tree is a complete binary tree. Generally,
    //  Heaps can be of two types:max-heap and min-heap
    int ele_to_making_max_heap[] = { 0,2, 5, 3, 10, 4 ,111,23,26};
    int size = sizeof(ele_to_making_max_heap) / sizeof(ele_to_making_max_heap[0]);

    make_heap(ele_to_making_max_heap,size);
    print_arr(ele_to_making_max_heap,size);
}