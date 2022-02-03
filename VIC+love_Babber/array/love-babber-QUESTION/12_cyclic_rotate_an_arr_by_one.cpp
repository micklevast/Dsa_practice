#include <iostream>
using namespace std;
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void rotate(int arr[], int size)
{
    for (int i = 0; i < size; i++) //satrting from start
    {
        arr[i + 1] = arr[i]; //this will give an wrong output
    }
    arr[0] = arr[size - 1];
    display(arr, size);
}

void cyclic_rotate(int arr[], int size)
{
    int last=arr[size-1];

    for (int i = size - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[0]=last;
    // display(arr, size);
}
int main()
{
    int arr[] = {12, 78, 56, 32, 45, 6895, 7562, 31, 78, 45, 49, 9999};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    // rotate(arr,size);
    cyclic_rotate(arr,size);
     display(arr, size);
}