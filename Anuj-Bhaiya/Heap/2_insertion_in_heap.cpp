#include <iostream>
#include <vector>
// insertion in heap
using namespace std;
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void print_arr(int  arr[], int size);
void heapify(int arr[], int heapify_pos, int size)
{
    int largest = heapify_pos;
    int L_child = largest * 2 + 1;
    int R_child = largest * 2 + 2;
    if (L_child < size && arr[L_child] > arr[largest])
        largest = L_child;

    if (R_child < size && arr[R_child] > arr[largest])
        largest = R_child;

    if (largest != heapify_pos)
    {
        swap(arr,largest,heapify_pos);
        cout<<"swaped "<<arr[largest] <<" and "<<arr[heapify_pos]<<" after swaping...\n";
        print_arr(arr,size);

        int parent_of_heapify_pos = (heapify_pos - 1) / 2;
        if (parent_of_heapify_pos >= 0)
            heapify(arr, parent_of_heapify_pos, size);
    }
    else
        return;
}

void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n------------------------------\n";
}

void insertion_in_heap(int arr[],int size)
{
    int insert_ele = 15;
    // firstly put element to be inserted at last position of arr
    arr[size-1]=insert_ele;
    int heapify_pos=(size-1-1)/2;
    heapify(arr,heapify_pos,size);

    print_arr(arr, size);
}

int main()
{
    int arr[]={10, 5, 3, 2, 4,0};

    int size = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr, size);
    cout << "size:" << size << endl;
    insertion_in_heap(arr,size);
    print_arr(arr, size);
}