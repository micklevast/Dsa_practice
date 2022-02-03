#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j+1]);
        }
    }
    display(arr,size);
}
int main()
{
    int arr[] = {245, 112, 29, 236, 27, 218, 298, 216, 133, 272};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    bubble_sort(arr, size);
    // display(arr, size);
}