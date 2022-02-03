#include <iostream>
using namespace std;
void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        
        for (int j = 0; j < size - 1 - i; j++)
        {
            if(arr[j]<arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[] = {21, 89, 56, 12, 45, 78, 63, 35, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr,size);
}