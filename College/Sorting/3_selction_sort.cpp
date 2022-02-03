#include <iostream>
using namespace std;
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void selection_sort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int minpos=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[minpos])
            {
                minpos=j;
            }
        }
        if(minpos!=i)
        {
            swap(arr[i],arr[minpos]);
        }
    }
}

int main()
{
    int arr[] = {45, 5612, 535, 122, 89, 57, 919, 68};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    selection_sort(arr,size);
    display(arr, size);
}